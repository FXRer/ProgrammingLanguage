#include<stdio.h>
#include<stdlib.h>
 
/* List Structure */ 
typedef struct Node
{
	int data;
	struct Node *next;
} node_t;
 
node_t *head = NULL;	// Head node to keep track of linked list
 
/* Driver functions */
void find(node_t *head);
void insert(int data, int position);
void print();
 
/* Main method */
int main()
{
	insert(0,1);	// Insert Element at first position LINKED-LIST =  / 0 /
	insert(1,2);	// Insert Element at second position LINKED-LIST = / 0 1 /
	insert(2,3);	// Insert Element at third position LINKED-LIST =  / 0 1 2 /
	insert(3,4);	// Insert Element at fourth position LINKED-LIST = / 0 1 2 3/
	insert(4,5);	// Insert Element at fourth position LINKED-LIST = / 0 1 2 3 4/
 
	print();		// Printing Elements of Linked List
	
	find(head);	// Find middle element
 
	return 0;
}
 
/* Function to find the middle of the linked list */
void find(node_t *head)
{
    node_t *slow_ptr = head;
    node_t *fast_ptr = head;
 
    if (head!=NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        printf(" The middle element is %d \n", slow_ptr->data);
    }
} 
 
/* Function for Inserting nodes at defined position */
void insert(int data, int position)
{
	/* Declaring node */
	node_t *tmp = (node_t*)malloc(sizeof(node_t));
	tmp->data = data;
	tmp->next = NULL;
	
	/* if node insertion at first point */
	if(position==1)
	{
		tmp->next = head;
		head = tmp;
		return ;
	}
	
	/* Adding & Adjusting node links*/
	node_t *traverse = head;
	for(int i=0; i<position-2; i++)
	{
		traverse = traverse->next;
	}	
	tmp->next = traverse->next;
	traverse->next = tmp;	
}
 
/* Function for Printing Linked List */
void print()
{
	printf("\n Linked List = ");
	node_t *p = head;
	while(p)
	{
		printf(" %d",p->data);
		p = p->next;
	}
	printf(" \n\n");
}


// Source: http://www.firmcodes.com/c-program-to-find-the-middle-node-of-a-linked-list/
