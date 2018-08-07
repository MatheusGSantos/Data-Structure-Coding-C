/*
////////////////////////////////////////////////////////////////////////////
This is Stack Exercise 2: Reversing a string using stacks
Matheus Gama dos Santos, 08/06/2018 22:30
///////////////////////////////////////////////////////////////////////////
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_MAX_SIZE 100

struct Stack
{
	char v[STACK_MAX_SIZE];
	int top;
};

void Push(struct Stack* s, char c)
{
	if(s->top < STACK_MAX_SIZE-1)
	{
		s->top++;
		s->v[s->top] = c;
	}
	else
	{
		printf("Stack overflow!\n");
		exit(1);
	}
}

char Pop(struct Stack* s)
{
	if (s->top >=0)
	{
		char tmp = s->v[s->top];
		s->top--;
		return tmp;
	}
	else
	{
		printf("Stack underflow!\n");
		exit(1);
	}
}

int main()
{
	struct Stack s;
	s.top = -1;
	char string[49];

	//getting the string from the user
	fgets(string, STACK_MAX_SIZE, stdin);
	string[strlen(string) - 1] = '\0';

	//storing the string into the stack
	for (int i = 0; i < strlen(string); i++)
	{
		Push(&s, string[i]);
	}

	//spitting it back into the string
	for (int i = 0; i < strlen(string); i++)
	{
		string[i] = Pop(&s);
	}

	printf("\nReversed String:\n%s\n",string);

	return 0;
}