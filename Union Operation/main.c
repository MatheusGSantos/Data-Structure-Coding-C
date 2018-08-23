/*
////////////////////////////////////////////////////////////////////////////////
This is Linked List Exercise 2: Set Union Operation
Matheus Gama dos Santos, 08/23/2018 14:08
////////////////////////////////////////////////////////////////////////////////
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SET_MAX_SIZE 35


struct Node
{
	int value;
	struct Node* next;
};


void fillSet1(struct Node** s1)
{
	*s1 = (struct Node*) malloc( sizeof(struct Node) );
	(*s1)->next = NULL;
	(*s1)->value = 0;

	struct Node* Aux = *s1;

	for (int i = 1; i < SET_MAX_SIZE; ++i)
	{
		Aux->next = (struct Node*) malloc( sizeof(struct Node) );
		Aux->next->value = i;
		Aux->next->next = NULL;
		Aux = Aux->next;
	}
}


void fillSet2(struct Node** s2)
{
	*s2 = (struct Node*) malloc( sizeof(struct Node) );
	(*s2)->next = NULL;
	(*s2)->value = SET_MAX_SIZE;

	struct Node* Aux = *s2;

	for (int i = 1; i < SET_MAX_SIZE; ++i)
	{
		Aux->next = (struct Node*) malloc( sizeof(struct Node) );
		Aux->next->value = i+SET_MAX_SIZE;
		Aux->next->next = NULL;
		Aux = Aux->next;
	}
}


struct Node* Union(struct Node* s1, struct Node* s2)
{
	struct Node* last = s1;
	
	while(last->next)
		last = last->next;

	last->next = s2;
	last = s1;

	return last;

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
	struct Node* set1 = NULL;
	struct Node* set2 = NULL;
/*
	fillSet1(&set1);	//fill set1 for debugging
	fillSet2(&set2);	//fill set2 for debugging
	struct Node* un = Union(set1, set2);
*/

	return 0;
}