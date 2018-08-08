/*
////////////////////////////////////////////////////////////////////////////
This is Stack Exercise 3: Stack with Singly Linked List
Matheus Gama dos Santos, 08 / 07 / 2018 19:57
///////////////////////////////////////////////////////////////////////////
*/

#include <stdio.h>
#include <stdlib.h>
#define STACK_MAX_SIZE 100

struct Node
{
	int value;
	struct Node* ancestor;	//ancestor node
};


struct SLLstack
{
	int size;
	struct Node* top;

};


void Push(struct SLLstack* s, char value)
{
	if (s->size == STACK_MAX_SIZE)
	{
		printf("Stack Overflow!\n");
		exit(1);
	}
	else
	{
		if (!s->top)
		{
			s->top = (struct Node*) malloc(sizeof(struct Node));
			s->top->value = value;
			s->top->ancestor = NULL;
		}
		else
		{
			struct Node* nAux = (struct Node*) malloc(sizeof(struct Node));
			nAux->value = value;
			nAux->ancestor = s->top;
			s->top = nAux;
		}
		printf("Element Added!\n");
		s->size++;
	}
}

char Pop(struct SLLstack* s)
{
	if (!s->size)
	{
		printf("Stack Underflow!\n");
		exit(1);
	}
	else
	{
		char copy_value = s->top->value;
		if (!s->top->ancestor)
		{
			free(s->top);	//stack returns to 0 elements
		}
		else
		{
			struct Node* aux = s->top->ancestor;
			free(s->top);							//top element is now the ancestor node
			s->top = aux;
		}
		s->size--;
		return copy_value;
	}
}

int main(int argc, char  const	*argv[])
{
	struct SLLstack s;
	s.size = 0;
	s.top = NULL;

	return 0;
}