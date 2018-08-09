/*
////////////////////////////////////////////////////////////////////////////
This is Stack Exercise 5: 2 Stacks in one common array
Matheus Gama dos Santos, 08/09/2018 11:47
///////////////////////////////////////////////////////////////////////////
*/

#include <stdio.h>
#include <stdlib.h>
#define STACK_MAX_SIZE 4


struct Stack
{
	char v[STACK_MAX_SIZE];
	int top1;		//this stack goes frontwards
	int top2;		//this stack goes backwards
};


void Push(struct Stack* s, char c, int ar)
{
	if (s->top1 + 1 == s->top2)
	{
		printf("Stack overflow!\n");
		exit(1);
	}

	if (ar == 1)
	{
		s->top1++;
		s->v[s->top1] = c;
	}
	else
	{
		s->top2--;
		s->v[s->top2] = c;
	}
}


char Pop(struct Stack* s, int ar)
{
	if ( (ar == 1 && s->top1 < 0) || (ar == 2 && s->top2 > (STACK_MAX_SIZE - 1) ) )
	{
		printf("Stack underflow!\n");
		exit(1);
	}

	if (ar == 1)
	{
		char tmp = s->v[s->top1];
		s->top1--;
		return tmp;
	}
	else
	{
		char tmp = s->v[s->top2];
		s->top2++;
		return tmp;
	}
}


//void PrintStack(struct Stack* s, int n)		//for debugging
//{
//	int i;
//	if (n == 1)
//	{
//		for (i = 0; i <= s->top1; i++)
//		{
//			printf("Stack 1[%d]: %c\n", i, s->v[i]);
//		}
//	}
//	else
//	{
//		for (i = STACK_MAX_SIZE-1; i >= s->top2; i--)
//		{
//			printf("Stack 2[%d]: %c\n", (STACK_MAX_SIZE - (i+1) ), s->v[i]);
//		}
//	}
//}


int main(int argc, char const *argv[])
{
	struct Stack s;
	s.top1 = -1;
	s.top2 = STACK_MAX_SIZE;

	return 0;
}