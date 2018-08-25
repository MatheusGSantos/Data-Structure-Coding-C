/*
////////////////////////////////////////////////////////////////////////////////
This is Linked List Exercise 3: Reversing Lists
Matheus Gama dos Santos, 08/25/2018 18:30
////////////////////////////////////////////////////////////////////////////////
*/

#include <stdio.h>
#include <stdlib.h>

#define LIST_MAX_SIZE 35

struct Node
{
	int value;
	struct Node* next;
};


void fillList(struct Node** list)
{
	*list = (struct Node*) malloc( sizeof(struct Node) );
	(*list)->next = NULL;
	(*list)->value = 0;

	struct Node* Aux = *list;

	for (int i = 1; i < LIST_MAX_SIZE; ++i)
	{
		Aux->next = (struct Node*) malloc( sizeof(struct Node) );
		Aux->next->value = i;
		Aux->next->next = NULL;
		Aux = Aux->next;
	}
}


struct Node* Reverse(struct Node* list)
{
	struct Node* holder;	//pointer that holds the rest of the list
	struct Node* head;		//pointer to the first element of the reversed list

	head = list;	
	holder = list->next;	//holder = {n1,n2,...,NULL}
	head->next = NULL;	//Reverse = {n0,NULL}

	struct Node* Aux;	//Holds the element to prepend to reversed list

	while(holder)
	{
		Aux = holder;
		holder = holder->next;
		Aux->next = head;
		head = Aux;	
	}

	return head;
}


void PrintSet(struct Node* set)
{
	struct Node* Aux = set;
	while(Aux)
	{
		printf("%d\n", Aux->value);
		Aux = Aux->next;
	}
}


int main(int argc, char const *argv[])
{
	struct Node* list = NULL;
	fillList(&list);

	list = Reverse(list);

	printf("\n\nList Reverse: \n");
	PrintSet(list);
	
	return 0;
}