#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "history_queue.h"
#include "string.h"
#include "shell.h"
void history_test();

int main() {
    start_shell();
    return 0;
}

/*
void history_test() {
    printf("Hello Budy\n");
    hello();
    char** a = (char**) malloc(sizeof(char*) * 2);
    a[0] = "furkan ";
    char** b = (char**) malloc(sizeof(char*) * 2);
    b[0] = "emre ";
    char** c = (char**) malloc(sizeof(char*) * 2);
    c[0] = "emasdasre ";
    char** d = (char**) malloc(sizeof(char*) * 2);
    d[0] = "kazma ";
    char** f = (char**) malloc(sizeof(char*) * 2);
    f[0] = "ls";
    f[1] = "-l";
    add_to_history(a,2);
    add_to_history(b,2);
    add_to_history(c,1);
    add_to_history(d,1);
    add_to_history(f,2);
    free(a);
    free(b);
    free(c);
    free(d);
    free(f);
    show_history();
    release_history();
}

void test_input() {
     printf("myshell>");

    char *s;
    s = malloc(100 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);

    char** arg_vector = (char**) malloc(sizeof(char*) * 10);
    
    char *token = strtok(s, " "); 
    int counter = 0;
    while (token != NULL && counter < 10) 
    { 
        arg_vector[counter] = token;
        printf("%s\n", arg_vector[counter]);
         
        token = strtok(NULL, " ");
        counter++;
    } 
    if(strcmp("cd", arg_vector[0]) == 0) {
       // printf("%s", arg_vector[1]);
        if(chdir(arg_vector[1]) == 0) {
            printf("succes");
        }
       
    }
}
*/