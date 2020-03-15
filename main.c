#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"dustbin_stack.h"
#include"truckqueue.h"

// function to check if the truck is empty
void empty_trucks(s_list *ptr_list)      
{
	for(node *temp = ptr_list->head; temp != NULL; temp = temp->link)
		temp->bags = 0;
}

// function to display the number of bags in each truck
void display (s_list *at)              
{
    int i=1;
    for (node *temp = at->head; temp != NULL; temp = temp->link,i++)
        printf ("\nThe number of bags in the truck-%d is %d.\n",i,temp->bags);
}

// function to avoid any chances of crash while taking input
int prompt()
{
    int bags = -1, size = 10000;
    char input[size];
    while(1)
    {
        printf("\nEnter the number of garbage bags to dispose:- ");
        fgets(input, size, stdin);
        bags = atoi(input);
        if(bags < 1)
        {
            puts("Please enter a positive number");
        }
        else
        {
            break;
        }
    }
    return bags;
}

int main()
{
    printf("Welcome to our Waste Management System\n");
	//printf("\nEnter the number of garbage bags to dispose:- ");
	int n = prompt();
	//scanf("%d", &n);
	if(n < 1)        // If number of bags in the bin is 0 or lesser, there is nothing to collect
	{
	    puts("There is no garbage to dispose!");
	    return 0;
	}
	dustbin *bin = create_dustbin();  // creating a dustbin using stacks
	for(int i=0;i<n;i++)
	{
		push(bin);                    // pushing the garbage into the stack
	}
	s_list *ptr_list = malloc(sizeof(s_list));
	list_initialize(ptr_list);        // initializing a queue for the trucks
	enqueue(ptr_list,0);              // add a truck to the queue
	while(!is_empty(bin))
	{
		if(ptr_list->tail->bags==10)  // a truck can hold 10 bags at the most. Will add more   trucks according to the number of garbage bags.
		{
			enqueue(ptr_list,0);   
		}
		pop(bin);                   // using pop func to remove the top from the stack
		ptr_list->tail->bags++;     // increasing the number of bags in a truck 
	}
	puts("All the garbage bags have been collected.");
	display(ptr_list);
	empty_trucks(ptr_list);
	puts("\nThe trucks have disposed the garbage in the junkyard.");
	display(ptr_list);
	list_destroy(ptr_list);       
    return 0;
}
