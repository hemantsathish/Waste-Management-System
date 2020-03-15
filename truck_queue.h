typedef struct node
{
    int bags;      //no of garbage bags a truck can hold
    struct node *link;   // pointer to the next node
}node;

typedef struct list
{
    node *head;       // pointer to the head of the queue
    node *tail;      // pointer to the tail of the queue
    int number_of_nodes;  // stores number of nodes in the queue
}s_list;

node* create_node(int);
void list_initialize(s_list *);
void enqueue(s_list *,int );
void list_destroy(s_list *);
