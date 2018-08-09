/*
////////////////////////////////////////////////////////////////////////////
This is Stack Exercise 4: RPN with stacks
Matheus Gama dos Santos, 08/09/2018 01:01
///////////////////////////////////////////////////////////////////////////
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STACK_MAX_SIZE 100


struct Stack
{
    int top;
    int v[STACK_MAX_SIZE];
};


void Push(struct Stack* s, int value)
{
	if (s->top < STACK_MAX_SIZE - 1)
	{
		s->top++;
		s->v[s->top] = value;
	}
	else
	{
		printf("Stack overflow!\n");
		exit(1);
	}
}


int Pop(struct Stack* s)
{
	if (s->top >= 0)
	{
		int tmp = s->v[s->top];
		s->top--;
		return tmp;
	}
	else
	{
		printf("Stack underflow!\n");
		exit(1);
	}
}


void Sum(struct Stack* s)
{
	int sum = Pop(s) + Pop(s);
	Push(s, sum);
}


void Subtract(struct Stack* s)
{
	int sub = -Pop(s) + Pop(s);
	Push(s, sub);
}


void Multiply(struct Stack* s)
{
	int multi = Pop(s) * Pop(s);
	Push(s, multi);
}


void Divide(struct Stack* s)
{
	int n2 = Pop(s);
	int n1 = Pop(s);
	int div = n1 / n2;
	Push(s, div);
}


int evaluate(char* string, int size, struct Stack* s)	//assuming there's no problem with the expression
{
	for (int i = 0; i < size; i++)
	{
		if (isdigit(string[i]))
		{
			int tmp = string[i] - '0';
			Push(s, tmp);
		}
		else if (string[i] == '*')
		{
			Multiply(s);
		}
		else if(string[i] == '+')
		{
			Sum(s);
		}
		else if (string[i] == '-')
		{
			Subtract(s);
		}
		else
		{
			Divide(s);
		}
	}
	return s->v[s->top];
}


int main(int argc, char const *argv[])
{
    struct Stack s;
	s.top = -1;
	char expression[50];

	printf("Insert Expression: ");
	fgets(expression, 50, stdin);
	expression[strlen(expression) - 1] = '\0';
	int result = evaluate(expression, strlen(expression), &s);

	printf("Result: %d\n",result);
    return 0;
}