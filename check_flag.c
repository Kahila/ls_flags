#include "ft_ls.h"

//method that will check the flags passed
struct s_flags flags_(char **argv)
{
    int i;
    int j;
    struct s_flags flags;

    i = 1;
    while (argv[i])
    {
        j = 1;
        if (argv[i][0] != '-' || !argv[i][1])
            break;
        flags = flags_help(argv[i], flags);
        flags.dir_start = ++i;
    }
    return (flags);
}

//function that will be used to check the flags passed
struct s_flags flags_passed(char **argv)
{
    int i;
    struct s_flags flags;

    i = 1;
    flags = flags_(argv);
    if (argv[1][0] != '-' || ft_strcmp(argv[1], "-") == 0)
        flags.dir_start = 1;
    else if (ft_strcmp(argv[1], "--") == 0)
    {
        flags.dir_start = 2;
        flags.error = 0;
    }
    return flags;
}

//method that will be used to check for any errors in the flags
struct s_flags check_errors(char **argv)
{
    struct s_flags st_flags;

    st_flags = flags_passed(argv);
    if (st_flags.error == -1)
    {
        ft_putstr("usige: ls [-atrlR] [file ...]\n");
        exit(INVALID_FLAG);
    }
    check_files(argv, st_flags);
    return(st_flags);
}

//method that will be used to sort the passed flags or dir by ascii
//method that will be used to save all dir's
void check_files(char **argv, struct s_flags dirs)
{
    DIR *mydir;
    char **files;
    int i;

    i = 0;
    files = store_invalid(argv, dirs);
    while (files[i])
    {
        mydir = opendir(files[i]);//mem alloc
        if (!mydir)
        {
            if (valid_file(files[i]) == -1)
            {
                ft_putstr("ls: ");
                ft_putstr(files[i]);
                ft_putstr(": No such file or directory\n");
            }
        }
        else
            closedir(mydir);//mem free
        free(files[i++]);//mem free
    }
    free(files);//mem free
    check_files_val(argv, dirs);
    return;
}