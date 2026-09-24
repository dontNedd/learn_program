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
        while((entry=readdir(path)))
        {
            printf("Please Enter in Pid: \n");
            scanf("%s", user_input);
            for(int i = 0; strcmp(entry->d_name, user_input); i++){
                int sum = entry->d_name[i];

                if(sum == 0){
                    printf("PID FOUND!\n");
                }
            }
        }
    }

    closedir(path);
    return 0;
}
