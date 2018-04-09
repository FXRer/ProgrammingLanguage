#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


struct node 
{
	int data;
	struct node *next;
};

typedef struct node node_t;

int main()
{
	node_t *head, *first, *temp = 0;
	int count = 0;
	int choice = 1;
	first = 0;

	while (choice)
	{
		head = (node_t *)malloc(sizeof(node_t));
		printf("Enter the data item\n");
		scanf("%d", &head->data);
		if (first != 0)
		{
			temp->next = head;
			temp = head;
		}
		else
		{
			first = temp = head;
		}
		fflush(stdin);
		printf("Do you want to continue (0 = No, 1 = Yes)?\n");
		scanf("%d", &choice);
	}
	
	temp->next = 0;
	
	temp = first;
	printf("\n Status of the linked list is\n");
	while (temp != 0)
	{
		printf("%d=>", temp->data);
		count++;
		temp = temp->next;	
	}
	printf("NULL\n");
	printf("No. of nodes in the list = %d\n", count);	
	
	return 0;
}

// Source: https://www.sanfoundry.com/c-program-create-linked-list-display-elements/
