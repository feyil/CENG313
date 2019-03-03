#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int insert(List** head, int value) {
  List* node_head = *head;
  List* node_prv = 0;

  if(!(*head)) {
    (*head) = (List*) malloc(sizeof(List));
    (*head)->data = value;
    (*head)->next = 0;

    return 0; //success
  }
  else {
    while(node_head) {
      if(node_head->data == value) {

	return 1;
      }
      else if((node_head->data) > value) {
	List* node = (List*) malloc(sizeof(List));

	node->next = node_head;
	node->data = value;

	(!node_prv) ? (*head = node) : (node_prv->next = node);
       	
	return 0;
      }
      
      node_prv = node_head;
      node_head = node_head->next;
    }
    List *node = (List*) malloc(sizeof(List));
    
    node->data = value;
    node->next = 0;

    node_prv->next = node;
    
    return 0; //success
  }
  return 1; //faliure
}

int const search(List* head, int value) {
  while(head) {
    if(head->data == value) {
      
      return 0; //success   
    }
    head = head->next;
  }

  return 1; //faliure
}

int delete(List** head, int value) {
  List* node_head = *head;
  List* node_prv = 0;

  if(!(*head)) {
    return 1;
  }
  else {
    while(node_head) {
      if((node_head->data) == value) {

	(!node_prv) ? (*head = node_head->next) : (node_prv->next = node_head->next);
	free(node_head);
	
	return 0; // success
      }      
      node_prv = node_head;
      node_head = node_head->next;
    }
    return 1; //falilure
  }
}

void const print_list(List* head) {
  printf("Final list:\n");
 
  int counter = 0;
  printf(" ");
  while(head) {
    printf("%d ",head->data);
    counter += 1;

    head = head->next;
    //preference we can free remaining element in the list
  }
  printf("\n");
}

//fey
