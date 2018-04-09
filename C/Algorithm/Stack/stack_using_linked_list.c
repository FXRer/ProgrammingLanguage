#include <stdlib.h>
 
/* List Structure */
typedef struct Node
{
	int data;
	struct Node *next;
} node_t;
 
int NoOfNodes=0;		// Count number of node_t
 
node_t *head=NULL;		// Head node to keep track of list
 
/* Driver Functions */
void Push(int data);
int Pop();
void PrintStack(node_t *);
 
/* Main Method */
int main()
{
	Push(0);
	Push(1);
	Push(2);
	Push(3);
	
	Pop(); 		// Delete 3 from Stack
	Pop(); 		// Delete 2 from Stack
	
	PrintStack(head); // Print Stack data
	
	return 0;
}
 
/* Insert Element */
void Push(int data)
{
	// Declaring node
	NoOfNodes++;
	node_t *tmp = (node_t*)calloc(1,sizeof(node_t));
	tmp->data = data;
	tmp->next = NULL;
	
	// If head is NULL or first node
	if(!head)
	{
		head = tmp;
		return;
	}
 
	// Traverse list upto end
	node_t *traverse=head;
	while(traverse->next)
		traverse = traverse->next;
	
	traverse->next = tmp;
}
 
/* Delete Element */
int Pop()
{
	node_t *traverse = head;
	
	for(int i=0;i<NoOfNodes-2;i++)
		traverse = traverse->next;
	
	node_t *Delete = traverse->next;
	traverse->next = NULL;
	int data = Delete->data;
	free(Delete);
	NoOfNodes--;
	
	return data;
}
 
/* Print Stack */
void PrintStack(node_t *p)
{
	printf(" %d",p->data);
	if(!p->next)return;
	PrintStack(p->next);
}

// Source: http://www.firmcodes.com/write-a-c-program-to-implement-a-stack-using-an-array-and-linked-list/
