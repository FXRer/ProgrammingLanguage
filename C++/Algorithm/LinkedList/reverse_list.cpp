#include<stdlib.h>
#include<stack>			//Use Standard template library to create Stack data structure 
using namespace std;
 
typedef struct Node
{
	int data;
	struct Node *next;
} node_t;
 
node_t *head = NULL;		// Head node to keep track of linked list
 
/* Driver functions */
void reverse();
void insert(int data, int position);
void print();
 
/* Main method */
int main()
{
	insert(0,1);	// Insert Element at first position LINKED-LIST =  / 0 /
	insert(1,2);	// Insert Element at second position LINKED-LIST = / 0 1 /
	insert(2,3);	// Insert Element at third position LINKED-LIST =  / 0 1 2 /	
	insert(3,4);	// Insert Element at fourth position LINKED-LIST = / 0 1 2 3/	
	
	print();		// Printing Elements of Linked List
	
	reverse();
	
	print();		// Printing Elements of Linked List
	
	return 0;
}

/* Function for Reversing Linked List */
void reverse()
{
	stack<node_t*> Stack;
	node_t *traverse = head;
	
	/* Pushing to Stack */
	while(traverse!=NULL)
	{
		Stack.push(traverse);
		traverse = traverse->next;
	}
 
	/* Poping from Stack */	
	node_t *tmp = Stack.top();
	head = tmp;
	Stack.pop();
	while(!Stack.empty())
	{
	
		tmp->next = Stack.top();
		Stack.pop();	
		tmp = tmp->next;
	}
	tmp->next = NULL; // Make last node next to zero which not linked to other node
}
 
/* Function for Inserting nodes at defined position */
void insert(int data, int position)
{
	node_t *tmp = (node_t*)malloc(sizeof(node_t));
	tmp->data = data;
	tmp->next = NULL;
	
	if(position==1)
	{
		tmp->next = head;
		head = tmp;
		return ;
	}
	
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
	node_t *p = head;
	while(p)
	{
		printf(" %d",p->data);
		p = p->next;
	}
	printf(" \n\n ");
}

// http://www.firmcodes.com/write-a-program-to-reverse-a-linked-list-using-stack-in-c/
