#include "ft_ls.h"

//method that will be used to sort the passed flags or dir by ascii
//method that will be used to save all dir's
void check_files_val(char **argv, struct s_flags dirs)
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
            if (valid_file(files[i]) == 1)
            {
                ft_putstr(files[i]);
                ft_putchar('\n');
            }
        }
        else
            closedir(mydir);//mem free
        free(files[i]);//mem free
        i++;
    }
    free(files);//mem free
    return;
}

//helper function for flags_
struct s_flags flags_help(char *argv, struct s_flags flags)
{
    int j;

    j = 1;
    while (argv[j])
    {
        if (argv[j] == 'a' && flags.a != 1)
            flags.a = 1;
        else if (argv[j] == 'l' && flags.l != 1)
            flags.l = 1;
        else if (argv[j] == 't' && flags.t != 1)
            flags.t = 1;
        if (argv[j] == 'r' && flags.r != 1)
            flags.r = 1;
        else if (argv[j] == 'R' && flags.R != 1)
            flags.R = 1;
        else if (argv[j] != 'a' && argv[j] != 'l' && argv[j] != 't' && argv[j] != 'r' && argv[j] != 'R')
            flags.error = -1;
        j++;
    }
    return (flags);
}
