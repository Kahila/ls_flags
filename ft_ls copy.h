#ifndef FT_LS_H
#define FT_LS_H

///including allowed libraries
#include "libft/libft.h"
// #include <unistd.h>
// #include <time.h>     //working with the time and the ctime functions
#include <dirent.h>   //working with the opendir, readdir and closedir functions
// #include <sys/stat.h> //working with the stat function and lstat functions
// #include <grp.h>
// #include <sys/types.h> //
// #include <pwd.h>       //working with the passwd struct;
// #include <uuid/uuid.h> //working with the uuid_t data type
// #include <sys/xattr.h> //working with the listaxttr and the getxattr functions
// #include <stdlib.h>    //working with the malloc, exit and free functions
// #include <string.h>    //working with the strerror function
// #include <stdio.h>     //working with the perror function
// #include <errno.h>
// #define POTENTIAL_FLAG '-'
// #define HIDDEN_FILES 'a'
// #define FILE_DETAILS 'l'
// #define RECURSIVE_LS 'R'
// #define SORT_LAST_MODI 't'
// #define SORT_REV_LEXO 'r'

enum statusCodes
{
    INVALID_FLAG = -1,
    SUCCESS,
    VALID_FLAG,
    IS_FILE,
    IS_FOLDER,
    FAILED,
    FAILED_TO_READ_FILE_INFO
};

typedef struct s_flags
{
    int l;
    int a;
    int r;
    int t;
    int R;
    int dash;
    int error;
    int dir_start;
} t_flags;

// typedef struct s_list
// {
//     int nLinks;
//     int dirORfile;
//     int sLink;
//     int nBytes;
//     char *last_modified;
//     char *user;
//     char *group;
//     char *fileName;
//     char *permits;
//     struct s_list *next;
//     struct s_list *prev;
// } t_list;
#include "stdio.h"

struct s_flags flags_passed(char **argv);
char *flag_ret(char **flag);
int check_invalid(char *st);
int valid_file(char *dir);
void order(char **argv);
void check_files(char **argv, struct s_flags dirs);
// int count_invalid(char **argv, struct s_flags dirs);
// int count_valid(char **argv, struct s_flags dirs);
char **store_invalid(char **argv, struct s_flags dirs);
char **store_valid(char **argv, struct s_flags dirs);
char **sort_(char **inv);
void check_files_val(char **argv, struct s_flags dirs);


#endif