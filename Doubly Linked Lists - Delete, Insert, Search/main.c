/*
////////////////////////////////////////////////////////////////////////////////
This is Doubly Linked List Exercise 1: Insert, Delete and Search
Matheus Gama dos Santos, 09/11/2018 11:52
////////////////////////////////////////////////////////////////////////////////
*/


#include <stdlib.h>
#include <stdio.h>


struct Node
{
	int value;
	struct Node* next;
	struct Node* previous;
};


void Insert(struct Node** list, int value)
{
	if (!*list)
	{
		*list = (struct Node*) malloc(sizeof(struct Node));
		(*list)->previous = NULL;
		(*list)->next = NULL;
		(*list)->value = value;
	}
	else
	{
		if (value < (*list)->value)
		{
			(*list)->previous = (struct Node*) malloc(sizeof(struct Node));
			(*list)->previous->previous = NULL;
			(*list)->previous->next = *list;
			(*list)->previous->value = value;
			*list = (*list)->previous;
		}
		else
		{
			struct Node* Aux = *list;
			while (1)
			{
				if (!(Aux->next))
				{
					break;
				}
				if (Aux->value < value)
				{
					if (Aux->next->value >= value)
						break;
					else
					{
						Aux = Aux->next;
					}
				}
			}
			if (!Aux->next)
			{
				Aux->next = (struct Node*) malloc(sizeof(struct Node));
				Aux->next->value = value;
				Aux->next->next = NULL;
				Aux->next->previous = Aux;
			}
			else
			{
				Aux->next->previous = (struct Node*) malloc(sizeof(struct Node));
				Aux->next->previous->next = Aux->next;
				Aux->next->previous->previous = Aux;
				Aux->next->previous->value = value;
				Aux->next = Aux->next->previous;
			}
		}
	}
}


void Delete(struct Node** list, struct Node* element)
{
	if (!(*list)) {
		printf("Empty List.\n");
		exit(1);
	}
	if ((*list) == element)
	{
		*list = (*list)->next;
		(*list)->previous = NULL;
	}
	else
	{
		struct Node* Aux = *list;
		while (Aux->next != element && Aux->next != NULL)
		{
			Aux = Aux->next;
		}
		Aux->next = Aux->next->next;
		if (Aux->next)
		{
			Aux->next->previous = Aux;
		}
	}
}


struct Node* Search(struct Node* list, int value)
{
	if (!list) {
		printf("Empty list.");
	}
	else {
		int flag = 0;
		while (1)
		{
			if (list->value == value)
			{
				flag = 1;
				break;
			}
			if (!(list->next) && (list->value != value))
			{
				break;
			}
			list = list->next;
		}
		if (flag)
		{
			return list;
		}
		else
		{
			printf("Element not found.\n");
			return NULL;
		}
	}
}


//void Printlist(struct Node* list)
//{
//	struct Node* Aux = list;
//	while (Aux)
//	{
//		printf("%d\n", Aux->value);
//		Aux = Aux->next;
//	}
//}


int main(int argc, char const *argv[])
{
	struct Node* list = NULL;

	return 0;
}