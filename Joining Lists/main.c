/*
////////////////////////////////////////////////////////////////////////////////
This is Linked List Exercise 4: Joining two sorted lists
Matheus Gama dos Santos, 09/08/2018 14:12
////////////////////////////////////////////////////////////////////////////////
*/

#include <stdio.h>
#include <stdlib.h>


#define LIST_1_SIZE 4
#define LIST_2_SIZE 6

struct Node
{
	int value;
	struct Node* next;
};


void fillList1(struct Node** list)
{
	*list = (struct Node*) malloc(sizeof(struct Node));
	(*list)->next = NULL;
	(*list)->value = 0;

	struct Node* Aux = *list;

	for (int i = 1; i < LIST_1_SIZE; ++i)
	{
		Aux->next = (struct Node*) malloc(sizeof(struct Node));
		Aux->next->value = i;
		Aux->next->next = NULL;
		Aux = Aux->next;
	}
}


void fillList2(struct Node** list)
{
	*list = (struct Node*) malloc(sizeof(struct Node));
	(*list)->next = NULL;
	(*list)->value = LIST_1_SIZE;

	struct Node* Aux = *list;

	for (int i = LIST_1_SIZE+1; i < LIST_1_SIZE+LIST_2_SIZE; ++i)
	{
		Aux->next = (struct Node*) malloc(sizeof(struct Node));
		Aux->next->value = i;
		Aux->next->next = NULL;
		Aux = Aux->next;
	}
}


void Printlist(struct Node* list)
{
	struct Node* Aux = list;
	while (Aux)
	{
		printf("%d\n", Aux->value);
		Aux = Aux->next;
	}
}


struct Node* JoinLists(struct Node* l1, struct Node* l2)
{
	struct Node* out = NULL;
	struct Node* Aux = NULL;

	while(l1 || l2)
	{
		if(!out)
		{
			out = (struct Node*) malloc(sizeof(struct Node));
			if(!l1)
			{
				out->value = l2->value;
				l2 = l2->next;
			}
			else if (!l2)
			{
				out->value = l1->value;
				l1 = l1->next;
			}
			else
			{
				if (l1->value < l2->value)
				{
					out->value = l1->value;
					l1 = l1->next;
				}
				else
				{
					out->value = l2->value;
					l2 = l2->next;
				}
			}
			out->next = NULL;
			Aux = out;
		}
		else 
		{
			Aux->next = (struct Node*) malloc(sizeof(struct Node));
			if(!l1)
			{
				Aux->next->value = l2->value;
				Aux->next->next = NULL;
				Aux = Aux->next;
				l2 = l2->next;
			}
			else if (!l2)
			{
				Aux->next->value = l1->value;
				Aux->next->next = NULL;
				Aux = Aux->next;
				l1 = l1->next;
			}
			else
			{
				Aux->next->next = NULL;
				if (l1->value < l2->value)
				{
					Aux->next->value = l1->value;
					l1 = l1->next;
				}
				else
				{
					Aux->next->value = l2->value;
					l2 = l2->next;
				}
				Aux = Aux->next;
			}
		}
	}
	return out;
}


int main(int argc, char const *argv[])
{
	struct Node* list1 = NULL;
	struct Node* list2 = NULL;
	fillList1(&list1);
	fillList2(&list2);

	struct Node* listJ = JoinLists(list1, list2);

	Printlist(listJ);
}