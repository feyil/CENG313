
struct history_node {
    char** arg_vector;
    int size;
    struct history_node* next;
};

typedef struct history_node HNode;

void hello();
void add_to_history(char** arg_vector, int size);
const void show_history();
void release_history();