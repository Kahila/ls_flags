#include "ft_ls.h"

//method that will be used to get the amount of space to allocate for invalid files
int count_invalid(char **argv, struct s_flags dirs)
{
    DIR *mydir;
    int len;
    int start;

    len = 0;
    start = dirs.dir_start;
    // start = 1;
    // printf("%i\n", start);
    while (argv[start])
    {
        mydir = opendir(argv[start]);
        if (!mydir)
            len++;
        else
            closedir(mydir);
        start++;
    }
    //printf("here\n");
    return (len);
}

//method that will be used to get the amount of space to allocate for valid files
int count_valid(char **argv, struct s_flags dirs)
{
    DIR *mydir;
    int len;
    int start;

    len = 0;
    start = dirs.dir_start;
    while (argv[start])
    {
        mydir = opendir(argv[start]);
        if (mydir)
        {
            closedir(mydir);
            len++;
        }
        start++;
    }
    return (len);
}

//method that will be used to save all the invalid files
char **store_invalid(char **argv, struct s_flags dirs)
{
    DIR *mydir;
    char **files;
    int i;
    int start;

    i = 0;
    // printf(">>%i\n", dirs.dir_start);
    files = (char**)malloc(sizeof(char*)*(count_invalid(argv, dirs)+1));
    files[count_invalid(argv, dirs)] = NULL;
    start = dirs.dir_start;
    while (argv[start])
    {
        mydir = opendir(argv[start]);
        if (!mydir)
        {
            files[i] = ft_strcpy(ft_strnew(ft_strlen(argv[start])), argv[start]);
            i++;
        }
        else
            closedir(mydir);
        start++;
    }
    return (sort_(files));
}

//method that will be used to save all the valid files
char **store_valid(char **argv, struct s_flags dirs)
{
    DIR *mydir;
    char **files;
    int i;
    int start;

    i = 0;
    files = (char**)malloc(sizeof(char*)*(count_invalid(argv, dirs)+1));
    files[count_valid(argv, dirs)] = NULL;
    start = dirs.dir_start;
    while (argv[start])
    {
        mydir = opendir(argv[start]);
        if (mydir)
        {
            files[i] = ft_strcpy(ft_strnew(ft_strlen(argv[start])), argv[start]);
            closedir(mydir);
            i++;
        }
        start++;
    }
    return (sort_(files));
}