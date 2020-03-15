typedef struct garbage
{
	struct garbage *next;     // pointer to the next item in the trash
}garbage;

typedef struct dustbin       // pointer to the head of the trash (top)
{
	garbage *head;
}dustbin;

dustbin *create_dustbin();
garbage *create_garbage();
int is_empty(dustbin *);
int count(dustbin *);
void push(dustbin *);
int pop(dustbin *);
