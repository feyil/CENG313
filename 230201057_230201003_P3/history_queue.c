#include <stdlib.h>
#include <stdio.h>
#include "history_queue.h"
#include <string.h>

HNode* h_head = 0;
int history_size = 0;

void hello() {
    printf("Hello From History\n");

}

void add_to_history(char** arg_vector, int size) { // be carfeul arg_vector
    if(h_head == 0) {
        HNode* node = (HNode*) malloc(sizeof(HNode));
        char** source = (char**) malloc(sizeof(char*) * size);
        node->arg_vector = memcpy(source, arg_vector, sizeof(char*) * size);
        node->size = size;
        node->next = 0;
        h_head = node;
        history_size++;
    } 
    else {
        if(history_size >= 10) {
            HNode* new_head = h_head->next;
            free(h_head->arg_vector);
            free(h_head);
            h_head = new_head;
        }
        else {
            history_size++;
        }
        
        HNode* node = (HNode*) malloc(sizeof(HNode));
        char** source = (char**) malloc(sizeof(char*) * size);
        node->arg_vector = memcpy(source, arg_vector, sizeof(char*) * size);
        node->size = size;
        node->next = 0;
            
        HNode* tmp_head = h_head;
        while(tmp_head != 0) {
            if(tmp_head->next == 0) {
                tmp_head->next = node;
                break;
            }
            tmp_head = tmp_head->next;
        }
    }
}

const void show_history() {
    HNode* tmp_head = h_head;
    int counter = 1;
    while(tmp_head != 0) {
        int n = tmp_head->size;
        printf("[%d] ", counter);
        for(int i = 0; i < n; i++) {
            printf("%s ", tmp_head->arg_vector[i]);
        }
        printf("\n");
        tmp_head = tmp_head->next;
        counter++;
    }
}

void release_history() {
    HNode* tmp_head = h_head;
    while(tmp_head != 0) {
        HNode* new_head = tmp_head->next;
        free(tmp_head->arg_vector);
        free(tmp_head);
        tmp_head = new_head;
    }    
}
