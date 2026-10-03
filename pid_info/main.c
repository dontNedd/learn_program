#include <stddef.h>
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

void char_plus_string(char *s) {
    char c = "/";
    // moves a pointer to the end of the string
    while(*s++);
    // substract the "0" at the end of *s string
    *(s - 1) = c;
    // readd the null terminator to mark new end of string
    *s = '\0';

}

int main() 
{
    char Path[200] = "/proc/";
    char user_input[200];
    char key[200] = "cmdline";

    // grab user input pid.
    check_pids(Path);
    printf("\nEnter Pid: \n");
    scanf("%s", user_input);
    printf("USER_INPUT: %s\n", user_input);

    // cat path and userinput strings
    char *NewPath = strcat(Path, user_input);

    // need to add strings in to DIR.
    struct dirent *entry;
    DIR *path;
    path = opendir(NewPath);

    printf("Please Enter in Pid: \n");
    scanf("%s", user_input);

    // key for checking if path is emty 
    while((entry=readdir(path)) != NULL)
    {
        if(strcmp(entry->d_name, key) == 0) {
            printf("Found Key: %s\n", key);
            printf("d_name: %s\n", entry->d_name);

            // need to a / in the key string.

            char *temp = strcat(NewPath, key);
            printf("NEW PATH IN IF: %s\n", temp);

        }
    }
}
