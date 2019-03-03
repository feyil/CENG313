#include <stdio.h>
#include <stdlib.h>

struct lst_node_s {
  int data;
  struct lst_node_s* next;
};

typedef struct lst_node_s List;

int insert(List** head, int value);
int const search(List* head, int value);
int delete(List** head, int value);
void const print_list(List* head);

//fey
