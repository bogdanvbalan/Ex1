// FUNCTIONS 
void add(int val);

//TYPES
typedef void (*print_ptr)();

typedef struct node{
  struct node * next;
  int val;
  print_ptr print_list;
} Node;

//VARIABLES
extern Node* head;