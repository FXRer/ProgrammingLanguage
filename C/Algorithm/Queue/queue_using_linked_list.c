#include <stdlib.h>
 
/* List Structure */
typedef struct Node
{
	int data;
	struct Node *next;
} node_t;
 
node_t *head=NULL;		// Head node to keep track of list
 
/* Driver Functions */
void EnQueque(int data);
int DeQueue();
void PrintQueue(node_t *p);
 
/* Main Method */
int main()
{
	EnQueque(0);
	EnQueque(1);
	EnQueque(2);
	EnQueque(3);
	DeQueue();			// Delete 0 from list
	DeQueue();			// Delete 1 from list
	
	EnQueque(4);		// Add 4 at the end of list
	
	PrintQueue(head);		// Print element of queue
	
	return 0;
}
 
/* Insert Element */
void EnQueque(int data)
{
	// Declaring node
	node_t *tmp = (node_t*)calloc(1,sizeof(node_t));
	tmp->data = data;
	tmp->next = NULL;
	
	// If head is NULL or first node
	if(!head)
	{
		head = tmp;
		return;
	}
	node_t *traverse=head;
	
	// Traverse list upto end
	while(traverse->next)
		traverse = traverse->next;
	
	traverse->next = tmp;
}
 
/* Delete Element */
int DeQueue()
{
	node_t* tmp = head;
	head = head->next;
	
	int data = tmp->data;
	
	free(tmp);
	
	return data;
}
 
/* Print queue */
void PrintQueue(node_t *p)
{
	printf(" %d",p->data);
	if(!p->next)
		return;
	print(p->next);
}

// Source: http://www.firmcodes.com/write-a-c-program-to-implement-a-queue-using-array-and-linked-list/
