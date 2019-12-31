#include "ft_ls.h"

//method that will deal with basic ls (no flags passed)
void basic_ls(int argc, struct s_flags flags)
{
    DIR *mydir;
    // char **files_sorted;
    struct dirent *files;
   
    // if (argc > 1 && ft_strcmp("--", argv[2]))
    //     return;
    mydir = opendir("./");//mem alloc
    if (argc == 1 || flags.error == 0)
    {
        while((files = readdir(mydir)))
        {
            if (files->d_name[0] != '.')
            {
                ft_putstr(files->d_name);
                ft_putchar('\n');   
            }
        }
    }
    closedir(mydir);//mem free
    return;
}

int main(int argc, char **argv)
{
    struct s_flags flags;

    if (argc > 1)
        flags = check_errors(argv);
    //basic_ls(argc, flags_(argv));
    // while (1 == 1)
    // {}
    return 0;
}