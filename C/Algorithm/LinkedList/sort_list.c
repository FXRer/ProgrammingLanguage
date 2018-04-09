#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node 
{
	int data;
	struct node *next;
};

typedef struct node node_t;

node_t *head = NULL;			// Head node to keep track of linked list

/* Driver functions */
void print();
void swap(node_t *p1, node_t *p2);
void sort(node_t *head);
void insert(int data, int position);

/* Main method */
int main()
{
	insert(4,1);	// Insert Element at first position LINKED-LIST =  / 4 /
	insert(2,2);	// Insert Element at second position LINKED-LIST = / 4 2 /
	insert(3,3);	// Insert Element at third position LINKED-LIST =  / 4 2 3 /
	insert(1,4);	// Insert Element at fourth position LINKED-LIST = / 4 2 3 1/
	insert(0,5);	// Insert Element at fifth position LINKED-LIST =  / 4 2 3 1 0/
 
	printf("\n Before sorting = ");	
	print();
	
	sort(head);		//  Sorting linked list
 
	printf("\n After sorting  = ");
	print();	
 
	return 0;
}

void sort(node_t *head)
{
	node_t *start = head;
	node_t *traverse;
	node_t *min;
	
	while (start->next)
	{
		min = start;
		traverse = start->next;
		
		while (traverse)
		{
			/* Find minimum element from array */ 
			if( min->data > traverse->data )
			{
				min = traverse;
			}
			
			traverse = traverse->next;	
		}
		swap(start, min);
		start = start->next;
	}
	
}

void swap(node_t *x, node_t *y)
{
	int tmp = x->data;
	x->data = y->data;
	y->data = tmp;
}

void insert(int data, int position)
{
	/* Declaring node */
	node_t *tmp = (node_t*)malloc(sizeof(node_t));
	tmp->data = data;
	tmp->next = NULL;
 
	/* If node insertion at first point */
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

void print()
{
	node_t *p = head;
	
	while(p)
	{
		printf(" %d",p->data);
		p = p->next;
	}
	printf(" \n\n");
}


// Source: http://www.firmcodes.com/c-program-to-sorting-a-singly-linked-list/
