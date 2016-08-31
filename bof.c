#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *read_password(){
    int fd = open("password.txt", O_RDONLY);
    int len;
    char *buffer = (char*)malloc(48);
    len = read(fd, buffer, 48);
    buffer[len-1] = 0;
    close(fd);
    return buffer;
}

int main(int argc, char *argv[], char *env[]){
    int authen = 0;
    char input[48];
    char *password = read_password();
    scanf(" %s", input);
    if(strncmp(input, password, strlen(password)) == 0){
        authen = 1;
    }
    if(authen){
        printf("You're admin\n");
    }else{
        printf("GG NOOB.\n");
    }
    return 0;
}
