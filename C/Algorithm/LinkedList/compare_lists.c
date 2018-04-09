#include <stdio.h>
#include <stdlib.h>

/* Structuree for a linked list node */
struct node
{
	int data;
	struct node *next;
};

int are_identical(struct node *x, struct node *y)
{
	while (x != NULL && y != NULL)
	{
		if (x->data != y->data)
			return 0;
			
		x=x->next;
		y=y->next;
	}
	
	return (x == NULL && y == NULL);
}

void push(struct node** head_ref, int data) 
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	
	if (!new_node)
		return;

	/* Put in the data */
	new_node->data = data;
	
	/* New node next will now point to head element */
	new_node->next = (*head_ref);
	
	/* Head will contain address of new node */
	(*head_ref) = new_node;
}

int main()
{
	struct node *a = NULL;
	struct node *b = NULL;
	
	push(&a, 1);
	push(&a, 2);
	push(&a, 3);

	push(&b, 1);
	push(&b, 2);
	push(&b, 3);

	printf("%s\n", are_identical(a, b) ? "Indentical" : "Not indentical");
	
	return 0;
}


// Source: http://findnerd.com/list/view/Check-two-Linked-Lists-are-Identical-or-not-in-C/16898/
