#include<stdio.h>
#include<stdlib.h>
#include"dustbin_stack.h"

// creating a stack
dustbin *create_dustbin()
{
	dustbin *bin = malloc(sizeof(dustbin));
	bin->head = NULL;
	return bin;
}

// creating a node in the stack
garbage *create_garbage()
{
	garbage *g = (garbage*)malloc(sizeof(garbage));
	g->next = NULL;
	return g;
}

// to check if the dustbin is empty
int is_empty(dustbin *bin)
{
	return bin->head == NULL;
}

// to push an element into the stack
void push(dustbin *bin)
{

	garbage *g = create_garbage();
	g->next = bin->head;
	bin->head = g;
}

// to remove the top most element from the stack
int pop(dustbin *bin)
{
	if(is_empty(bin))
		return 0;
	garbage *temp = bin->head;
	bin->head = bin->head->next;
	free(temp);
}
