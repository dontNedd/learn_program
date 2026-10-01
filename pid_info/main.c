#include <stdio.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>

void check_pids(char *dirname) {
    struct dirent *d;
    DIR *dir = opendir(dirname);
    while((d = readdir(dir)) != NULL) {
        printf("%3s\n", d->d_name);
    }
}

int main() 
{
    char Path[200] = "/proc/";
    char user_input[200];

    // grab user input pid.
    check_pids(Path);
    printf("\nEnter Pid: \n");
    scanf("%s", user_input);
    printf("USER_INPUT: %s\n", user_input);

    // cat path and userinput strings
    char *NewPath = strcat(Path, user_input);
    printf("NEW PATH: %s\n", NewPath);

    // need to add strings in to DIR.
    struct dirent *entry;
    DIR *path;
    path = opendir(NewPath);

    printf("Please Enter in Pid: \n");
    scanf("%s", user_input);

    // key for checking if path is emty 
    int key = 0;
    while((entry=readdir(path)) != NULL)
    {
        // not sure if it would help but add switch statment in stead of alot of if statements
        if(++key > 2) {
            printf("entry->d_name: %s\n", entry->d_name);
        } else if(key <= 2) {
            printf("EMPTY DIR\n");
        } else {
            readdir(path);
        }
    }
}
