/*
////////////////////////////////////////////////////////////////////////////////
This is Linked List Exercise 1: Dictionary delete, insert and search operations
Matheus Gama dos Santos, 08/12/2018 13:45
////////////////////////////////////////////////////////////////////////////////
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node
{
	int value;
	struct Node* next;
};


struct CSLList
{
	int size;
	struct Node* head;
	struct Node* tail;
};


void Insert(struct CSLList *list, int value, int pos)
{
	if ( !(list->head) )	//If empty
	{
		list->head = (struct Node*) malloc( sizeof(struct Node) );
		list->head->next = list->head;
		list->head->value = value;
		list->tail = list->head;
		list->size++;
	}
	else
	{
		if ((pos > list->size) || (pos < 0))
		{
			printf("Invalid Position.\n");
		}
		else
		{
			struct Node* Aux;
			if (pos == 0)		//Prepend operation
			{
				Aux = (struct Node*) malloc(sizeof(struct Node));
				Aux->next = list->head;
				Aux->value = value;
				list->head = Aux;
				list->tail->next = list->head;
				list->size++;
			}
			else
			{
				if (pos == list->size)		//Append operation
				{
					list->tail->next = (struct Node*) malloc(sizeof(struct Node));
					list->tail->next->next = list->head;
					list->tail->next->value = value;
					list->tail = list->tail->next;
					list->size++;
				}
				else		//insert operation
				{
					Aux = list->head;
					for (int i = 1; i < pos; i++)	//won't happen if pos = 1 
					{
						Aux = Aux->next;
					}
					struct Node* AdAux = Aux->next;
					Aux->next = (struct Node*) malloc(sizeof(struct Node));
					Aux->next->next = AdAux;
					Aux->next->value = value;
					list->size++;
				}
			}
		}
	}
}


void Delete(struct CSLList *list, int pos)
{
	if (!(list->head))	//If empty
	{
		printf("Invalid Operation! Empty List.\n");
		exit(1);
	}
	else
	{
		if ( (pos > list->size - 1) || (pos < 0))
		{
			printf("Invalid Position.\n");
		}
		else
		{
			if (pos == 0)	//deleting first element
			{
				list->tail->next = list->head->next;
				list->head = list->tail->next;
				list->size--;
			}
			else
			{
				struct Node* Aux = list->head;
				for (int i = 1; i < pos; i++)	//won't happen if pos = 1 
				{
					Aux = Aux->next;
				}

				if (pos == (list->size - 1))	//deleting last element
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
}


int Search(struct CSLList *list, int value)
{
	struct Node* Aux = list->head;
	for (int i = 0; i < list->size; i++)
	{
		if (Aux->value == value)
		{
			return i;	//return index
		}
		Aux = Aux->next;
	}
	return -1;	 //No matches
}


void PrintList(struct CSLList list)
{
	struct Node* Aux = list.head;
	for (int i = 0; i < list.size; i++)
	{
		printf("List[%d]: %d\n",i ,Aux->value);
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