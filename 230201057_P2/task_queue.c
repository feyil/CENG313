#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "task_queue.h"
#include "list.h"

Task* task_queue(int n) {
  Task* head = 0;
  Task* task = 0;
  
  srand(time(NULL));
  for(int i = 0; i < n; i++) {
    task = (Task*) malloc(sizeof(Task));
    task->next = 0;
    task->task_num = i;
    
    task->task_type = rand() % 3;

    task->value = rand() % 10; //You can change possible values for list
    
    task_enqueue(&head, task);
  }
  printf("Generated %d random list tasks...\n", n);
  
  process(&head);
}

Task* task_enqueue(Task** head, Task* task) {
  Task* node_head = *head;

  if(!(*head)) {
    (*head) = task;
  }
  else {
    while(node_head) {
      if(!node_head->next) {
	node_head->next = task;
	return 0;
      }
      node_head = node_head->next;
    }
  }
}

Task* task_dequeue(Task** head) {
  Task* node_head = *head;
  if((*head)->next) {
    (*head) = (*head)->next;
  }
  else {
    *head = 0;
  }

  return node_head;
}

int process(Task** head) {
  List* Lhead = 0;

  while(*head) {
    Task* p1 = task_dequeue(head);
    
    print_task(p1);

    switch(p1->task_type) {
    case 0:
      if(!insert(&Lhead,p1->value)) {
	printf("%d is inserted\n",p1->value);
      }
      else {
	printf("%d cannot be inserted\n", p1->value);
      }
      break;
    case 1:
      if(!delete(&Lhead,p1->value)) {
	printf("%d deleted\n",p1->value);
      }
      else {
	printf("%d cannot be deleted\n", p1->value);
      }
      break;
    case 2:
      if(!search(Lhead, p1->value)) {
	printf("%d is found\n",p1->value);
      }
      else {
	printf("%d is not found\n", p1->value);
      }
      break;
    }
    free(p1);
    p1 = 0;
  }
  print_list(Lhead);
}

void const print_task_queue(Task* head) {
  while(head) {
    print_task(head);
    printf("\n");
    head = head->next;
  }
}

void const print_task(Task* task) {
  switch(task->task_type) {
  case 0:
    printf("task %d-insert %d: ",task->task_num, task->value);
    break;
  case 1:
    printf("task %d-delete %d: ",task->task_num, task->value);
    break;
  case 2:
    printf("task %d-search %d: ",task->task_num, task->value);
    break;
  }
}

//fey
