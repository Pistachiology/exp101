#include <stdio.h>
#include <stdlib.h>

char *name;
int ((*func)(char*, ...));

int check_input(char *input){
    int i;
    for(i = 0; input[i]; i++){
        if(!( input[i] >= 'a' && input[i] <= 'z'))
            return 1;
    }
    return 0;
}
void show_menu(){
    printf("Use After Free - Echo Service\n");
    printf(" 1.) init\n");
    printf(" 2.) set argument\n");
    printf(" 3.) execute\n");
    printf(" 4.) change name\n");
    printf(" 5.) exit\n");
}

int main(int argc, char *argv[], char *env[]){
    int choice = 0;
    char *name = (char*) malloc(32) , *arg = NULL, buffer[1024], confirm_exit;
    printf("What is your name ?\n"); scanf("%30s", name);
    while(confirm_exit != 'Y'){
        show_menu();
        printf("choice: "); scanf(" %d", &choice);
        switch(choice){
            case 1:
                if(!arg){
                    arg = (char*)malloc(32);
                    printf("arg = %p %s\n", arg, arg);
                }else
                    printf("You have already init\n");
                break;
            case 2:
                if(!arg) printf("You did not init argument yet.");
                else{
                    scanf(" %[^\n]30s", arg);
                    if(check_input(arg)){
                        printf("Don't cheat me ! \n");
                        exit(0);
                    }
                }
                break;
            case 3:
                sprintf(buffer, "echo %s", arg);
                system(buffer);
                free(arg);
                arg = NULL;
                break;
            case 4:
                printf("Enter your new name: "); scanf(" %30s", name);
                break;
            case 5:
                printf("Do you want to exit ? (Y/N)\n"); scanf(" %c", &confirm_exit);
                free(name);
            default: break;
        }
    }
}
