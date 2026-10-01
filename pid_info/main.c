#include <stdio.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>

int main() 
{
    char Path[200] = "/proc/";
    char user_input[200];

    // grab user input pid.
    printf("Enter Pid: \n");
    scanf("%s", user_input);
    printf("USER_INPUT: %s\n", user_input);

    // cat path and userinput strings
    char *NewPath = strcat(Path, user_input);
    printf("NEW PATH: %s\n", NewPath);

    // need to add strings in to DIR.
    struct dirent *entry;
    DIR *path;
    path = opendir(NewPath);

    if(path == NULL)
    {
        printf("Directory doesn't exist.\n");
        return -1;
    }
    else {
        while((entry=readdir(path)))
        {
        printf("%s\n", entry->d_name);
        }
    }
}

// int main(int argc, char *argv[])
// {
//     pid_t user_input[2000];
//     struct dirent *entry;
//
//     DIR *path; 
//     path = opendir("/proc/");
//
//     if(path == NULL)
//     {
//         printf("Directory doesn't exist.\n");
//         return -1;
//     }
//     else {
//         printf("Starting pid info...\n");
//         printf("Please Enter in Pid: \n");
//         scanf("%d", user_input);
//
//         while((entry=readdir(path)))
//         {
//             if(strcmp(entry->d_name, (char *)user_input) == 0)
//             {
//                 printf("MATCH: %s, %d\n", entry->d_name, *user_input);
//                 char *newPath = strcat(path, user_input);
//
//                 path = opendir(newPath);
//                 printf("NEW DIR OPENED: %s\n", path);
//             }
//         }
//     }
//
//     closedir(path);
//     return 0;
// }
