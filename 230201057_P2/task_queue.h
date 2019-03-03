#include <stdio.h>
#include <stdlib.h>

struct tsk_node_s {
  int task_num; //starting from 0;
  int task_type; // insert 0, delete 1, search 2
  int value;
  struct tsk_node_s* next;
};

typedef struct tsk_node_s Task;


Task* task_queue(int n); // Generate n numbers of task in a queue
Task* task_enqueue(Task** head, Task* task); // return: New tail
Task* task_dequeue(Task** head); // return: New head
int process(Task** head);
void const print_task_queue(Task* head);
void const print_task(Task* task);

//fey
