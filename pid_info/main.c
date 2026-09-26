#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    char user_input[2000];
    struct dirent *entry;

    DIR *path; 
    path = opendir("/proc/");

    if(path == NULL){
        printf("Directory doesn't exist.\n");
        return -1;
    }
    else {
        printf("Starting pid info...\n");

        printf("Please Enter in Pid: \n");
        scanf("%s", user_input);
        while((entry=readdir(path)))
        {
            if( strcmp(entry->d_name, user_input) == 0)
            {
                printf("MATCH: %s, %s\n", entry->d_name, user_input);
            };
        }
    }

    closedir(path);
    return 0;
}
