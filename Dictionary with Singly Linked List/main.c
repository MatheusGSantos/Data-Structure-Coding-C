/*
////////////////////////////////////////////////////////////////////////////////
This is Linked List Exercise 1: Dictionary delete, insert and search operations
Matheus Gama dos Santos, 08/20/2018 23:19
////////////////////////////////////////////////////////////////////////////////
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node
{
	char *key;
	int value;
	struct Node* next;
};


struct CSLList
{
	int size;
	struct Node* head;
	struct Node* tail;
};


void Insert(struct CSLList *list, int value, char* key)
{
	if ( !(list->head) )	//If empty
	{
		list->head = (struct Node*) malloc( sizeof(struct Node) );
		list->head->next = list->head;
		list->head->value = value;
		list->head->key = key;
		list->tail = list->head;
		list->size++;
	}
	else
	{
		struct Node* Aux = (struct Node*) malloc(sizeof(struct Node));
		Aux->next = list->head;
		Aux->value = value;
		Aux->key = key;
		list->head = Aux;
		list->tail->next = list->head;
		list->size++;
	}
}


void Delete(struct CSLList *list, struct Node* n)
{
	if (!n)	//If empty
	{
		printf("Invalid operation! Element not found.\n");
		exit(1);
	}
	else
	{
		if (n == list->head)	//deleting first element
		{
			list->tail->next = list->head->next;
			list->head = list->tail->next;
			list->size--;
		}
		else
		{
			struct Node* Aux = list->head;
			while(Aux->next != n)
			{
				Aux = Aux->next;
			}
			if (Aux->next == list->tail)	//deleting last element
			{
				list->tail = Aux;
				list->tail->next = list->head;
				list->size--;
			}
			else
			{
				Aux->next = Aux->next->next;
				list->size--;
			}
		}
	}
}


struct Node* Search(struct CSLList *list, const char* key)
{
	struct Node* Aux = list->head;
	for (int i = 0; i < list->size; i++)
	{
		if (!strcmp(Aux->key,key))
		{
			return Aux;	//returns pointer to element
		}
		Aux = Aux->next;
	}
	return NULL;	 //No matches
}


void PrintList(struct CSLList list)
{
	struct Node* Aux = list.head;
	for (int i = 0; i < list.size; i++)
	{
		printf("%s : %d\n", Aux->key ,Aux->value);
		Aux = Aux->next;
	}
}


int main(int argc, char const* argv[])
{
	struct CSLList list;
	list.head = NULL;
	list.tail = NULL;
	list.size = 0;

	return 0;
}