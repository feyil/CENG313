#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "shell.h"
#include "string.h"
#include "history_queue.h"

void start_shell() {
    char *inputLine;
    int counter = 0;
    while(1) {
        printf("\nmyshell>");
        counter++;
       
        //read command line
        inputLine = malloc(100 * sizeof(char));        
        scanf("%[^\n]%*c", inputLine);

        inputLine = realloc(inputLine, strlen(inputLine) + 1);

        //parse command line
        int arg_size = 0;
        char** arg_vector = parse(inputLine, &arg_size);
     
        if(strcmp("cd", arg_vector[0]) == 0) {
            if(arg_size == 1) {
                char* directory = getenv("HOME");

                if(chdir(directory) == 0) {
                    setenv("PWD", directory, 1);
                    add_to_history(arg_vector,arg_size);
                }
                else {
                    printf("Invalid Command!");
                }
            }
            else if(arg_size == 2) {
                if(chdir(arg_vector[1]) == 0) {
                    char* directory = getenv("PWD");
                    strcat(directory, arg_vector[1]);
                    setenv("PWD", directory, 1);
                    add_to_history(arg_vector,arg_size);
                }
                else {
                    char* directory = getenv("PWD");
                    strcat(directory, arg_vector[1]);
                   
                    if(chdir(directory) == 0) {
                        add_to_history(arg_vector,arg_size);
                        setenv("PWD", directory, 1);
                    }
                    else {
                        printf("Invalid Command");
                    }
                }
            }
            else {
                printf("Invalid Command");
                break;
            }
        }
        else if(strcmp("dir", arg_vector[0]) == 0) {
            add_to_history(arg_vector,arg_size);
            char buff[100];
            getcwd(buff, sizeof(buff));
            printf("%s", buff);
           
        }
        else if(strcmp("history", arg_vector[0]) == 0) {
            add_to_history(arg_vector,arg_size);
            show_history();
        }
        else if(strcmp("findloc", arg_vector[0]) == 0) {
            if(arg_size == 1) {
                char* path = getenv("PATH");
                add_to_history(arg_vector,arg_size);
            }
            else if(arg_size == 2) {
                char* path = getenv("PATH");
                add_to_history(arg_vector,arg_size);
            }
            else {
                printf("Invalid Command");
            }
        }
        else if(strcmp("bye", arg_vector[0]) == 0) {
            release_history();
            exit(0);
        }
        else {
            add_to_history(arg_vector,arg_size);
            if(strcmp("&",arg_vector[arg_size - 1]) == 0){
		if(fork()==0){
			if(execvp(arg_vector[0],arg_vector) == -1){printf("Invalid Command");}
			
		}
	    }
	    else{
		if(fork()==0){
			if(execvp(arg_vector[0],arg_vector) == -1){printf("Invalid Command");}
		}
		else{
			wait(NULL);
		}
	    }
        }

        free(arg_vector);
    }

}

char** parse(char* inputLine, int* size) {
    char** arg_vector = (char**) malloc(sizeof(char*) * 10);
    
    char *token = strtok(inputLine, " "); 
    int counter = 0;
    
    while (token != NULL && counter < 10) 
    { 
        arg_vector[counter] = token;
        token = strtok(NULL, " ");
        counter++;
    }
   
    arg_vector = realloc(arg_vector, sizeof(char*) * counter); 
    *size = counter;
    
    return arg_vector;
}
