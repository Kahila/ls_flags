#include "ft_ls.h"

//function that will be used to check the flags passed
struct s_flags flags_passed(char **argv)
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
        while (argv[i][j])
        {
            if (argv[i][j] == 'a' && flags.a != 1)
                flags.a = 1;
            else if (argv[i][j] == 'l' && flags.l != 1)
                flags.l = 1;
            else if (argv[i][j] == 't' && flags.t != 1)
                flags.t = 1;
            else if (argv[i][j] == 'r' && flags.r != 1)
                flags.r = 1;
            else if (argv[i][j] == 'R' && flags.R != 1)
                flags.R = 1;
            else if (argv[i][j] != 'a' && argv[i][j] != 'l' && argv[i][j] != 't' && argv[i][j] != 'r' && argv[i][j] != 'R')
                flags.error = -1;
            j++;
        }
        flags.dir_start = ++i;
    }
    if (argv[1][0] != '-')
        flags.dir_start = 1;

    return flags;
}

//method that will be used to check for any errors in the flags
void check_errors(char **argv)
{
    struct s_flags st_flags;

    st_flags = flags_passed(argv);
    if (st_flags.error == -1)
    {
        ft_putstr("usige: ls [-atrlR] [file ...]\n");
        exit(INVALID_FLAG);
    }
    check_files(argv, st_flags);
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
        free(files[i]);//mem free
        i++;
    }
    free(files);//mem free
    check_files_val(argv, dirs);
    return;
}

int main(int argc, char **argv)
{
    if (argc > 1)
        check_errors(argv);

    while (1 == 1)
    {}
    return 0;
}