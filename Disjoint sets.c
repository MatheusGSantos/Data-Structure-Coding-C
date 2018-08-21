#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Node
{
	int value;
	struct Node* next;
};


int main(int argc, char const *argv[])
{
	char *set1;
	char *set2;
	struct Node* Union = NULL;

	fgets(set1, 35, stdin);
	fgets(set2, 35, stdin);

	for (int i = 0; i < strlen(set1); ++i)
	{
		if(isdigit(set1[i]))
		{

		}
	}


	return 0;
}