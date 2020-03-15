#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"truckqueue.h"

// creates a node which contains number of bags (will be used as each element of the queue)
node* create_node(int bags)       
{
    if (bags > 10)
        {
            printf("Truck full of garbage");
            exit(0);
        }
    node *new_node=(node*)malloc(sizeof(node));
    new_node->bags=bags;
    new_node->link=NULL;
    return new_node;
}

// initializes a queue 
void list_initialize(s_list *ptr_list)           
{
    ptr_list->head=ptr_list->tail=NULL;
    ptr_list->number_of_nodes=0;
}

// adds a node at the end of the queue (enqueues a node with bags into the ptr_list)
void enqueue(s_list *ptr_list, int bags)    
{
    node *temp=create_node(bags);
    if(ptr_list->number_of_nodes==0)
        ptr_list->head=ptr_list->tail=temp;   
    else
    {
        ptr_list->tail->link=temp;
        ptr_list->tail=temp;
    }
    ptr_list->number_of_nodes++;         
}

//destroys all the nodes from ptr_list
void list_destroy(s_list *ptr_list)
{
    node *temp,*prev=NULL;
    temp=ptr_list->head;
    while(temp!=NULL)
    {
        prev=temp;
        temp=temp->link;
        free(prev);
    }
}

