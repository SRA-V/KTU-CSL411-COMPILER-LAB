#include <stdio.h>
#include <stdlib.h>
struct node
{
	int state;
	struct node *link;
};
static int set[20], no_state, no_alpha, s, no_transition, no_final, start, finalstate[20], r, buffer[20];
char alphabet[20], c;
static int e_closure[20][20] = {0};
struct node *transition[20][20] = {NULL};
void print_e_closure(int i)
{
	int j;
	printf("{");
	for (j = 0; e_closure[i][j] != 0; j++)
		printf("q%d,", e_closure[i][j]);
	printf("}\t");
}
int findalpha(char c)
{
	int i;
	for (i = 0; i < no_alpha; i++)
		if (alphabet[i] == c)
			return i;

	return (999);
}
void findclosure(int x, int start)
{
	struct node *temp;
	int i;
	if (buffer[x])
		return;
	e_closure[start][c++] = x;
	buffer[x] = 1;
	if (alphabet[no_alpha - 1] == 'e' && transition[x][no_alpha - 1] != NULL)
	{
		temp = transition[x][no_alpha - 1];
		while (temp != NULL)
		{
			findclosure(temp->state, start);
			temp = temp->link;
		}
	}
}
void insert_trantbl(int r, char c, int s)
{
	int j;
	struct node *temp;
	j = findalpha(c);
	if (j == 999)
	{
		printf("error\n");
		exit(0);
	}
	temp = (struct node *)malloc(sizeof(struct node));
	temp->state = s;
	temp->link = transition[r][j];
	transition[r][j] = temp;
}

void unionclosure(int i)
{
	int j = 0, k;
	while (e_closure[i][j] != 0)
	{
		k = e_closure[i][j];
		set[k] = 1;
		j++;
	}
}
void findfinalstate()
{
	int i, j, k, t;
	for (i = 0; i < no_final; i++)
	{
		for (j = 1; j <= no_state; j++)
		{
			for (k = 0; e_closure[j][k] != 0; k++)
			{
				if (e_closure[j][k] == finalstate[i])
				{

					print_e_closure(j);
				}
			}
		}
	}
}

void main()
{
	int i, j, k, m, t, n;

	struct node *temp;
	printf("enter the number of alphabets?\n");
	scanf("%d", &no_alpha);
	getchar();
	printf("NOTE:- [ use letter e as epsilon]\n");

	printf("NOTE:- [e must be last character ,if it is present]\n");

	printf("\nEnter alphabets?\n");
	for (i = 0; i < no_alpha; i++)
	{

		alphabet[i] = getchar();
		getchar();
	}
	printf("Enter the number of states?\n");
	scanf("%d", &no_state);
	printf("Enter the start state?\n");
	scanf("%d", &start);
	printf("Enter the number of final states?\n");
	scanf("%d", &no_final);
	printf("Enter the final states?\n");
	for (i = 0; i < no_final; i++)
		scanf("%d", &finalstate[i]);
	printf("Enter no of transition?\n");
	scanf("%d", &no_transition);
	printf("NOTE:- [Transition is in the form--> qno   alphabet   qno]\n");
	printf("NOTE:- [States number must be greater than zero]\n");
	printf("\nEnter transition?\n");
	for (i = 0; i < no_transition; i++)
	{

		scanf("%d %c %d", &r, &c, &s);
		insert_trantbl(r, c, s);
	}

	printf("\n");

	for (i = 1; i <= no_state; i++)
	{
		c = 0;
		for (j = 0; j < 20; j++)

		{
			buffer[j] = 0;
			e_closure[i][j] = 0;
		}
		findclosure(i, i);
	}
	printf("Equivalent NFA without epsilon\n");
	printf("-----------------------------------\n");
	printf("start state:");
	print_e_closure(start);
	printf("\nAlphabets:");
	for (i = 0; i < no_alpha; i++)
		printf("%c ", alphabet[i]);
	printf("\n States :");
	for (i = 1; i <= no_state; i++)
		print_e_closure(i);

	printf("\nTnransitions are...:\n");

	for (i = 1; i <= no_state; i++)
	{

		for (j = 0; j < no_alpha - 1; j++)
		{
			for (m = 1; m <= no_state; m++)
				set[m] = 0;
			for (k = 0; e_closure[i][k] != 0; k++)
			{

				t = e_closure[i][k];
				temp = transition[t][j];
				while (temp != NULL)
				{

					unionclosure(temp->state);
					temp = temp->link;
				}
			}
			printf("\n");
			print_e_closure(i);
			printf("%c\t", alphabet[j]);
			printf("{");
			for (n = 1; n <= no_state; n++)
			{
				if (set[n] != 0)
					printf("q%d,", n);
			}
			printf("}");
		}
	}
	printf("\n Final states:");
	findfinalstate();
	printf("\n");
}
