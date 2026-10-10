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

void char_plus(char *s) {
    char c = '/';
    while(*s++);
    *(s - 1) = c;
    *s = '\0';
}

int check_int(char *s) {
    printf("Reached CHECK_INT\n");
    char *asdf = "bus";

    bool checker = true;
    while(checker){
        s++;
        if(strcmp(s, asdf)){
            printf("\nStirngs Match: %s, %s\n", s, asdf);
        }

        if(s == NULL){
            checker = false;
        }
    }
    return -1;
}

int main() 
{
    char Path[200] = "/proc/";
    char user_input[200];
    char key[200] = "cmdline";

    check_pids(Path);
    printf("\nEnter Pid: \n");
    scanf("%s", user_input);
    printf("USER_INPUT PRE: %s\n", user_input);
    check_int(user_input);
    char_plus(user_input);
    printf("USER_INPUT: %s\n", user_input);

    char *NewPath = strcat(Path, user_input);

    struct dirent *entry;
    DIR *path;
    path = opendir(NewPath);

    while((entry=readdir(path)) != NULL)
    {
        if(strcmp(entry->d_name, key) == 0) {
            char_plus(key);

            char *temp = strcat(NewPath, key);
            printf("NEW PATH IN IF: %s\n", temp);
        }
    }
}
