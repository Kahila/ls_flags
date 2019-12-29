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