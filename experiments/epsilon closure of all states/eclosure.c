#include <stdio.h>
#include <string.h>

char result[20][20], copy[3], states[20][20];

int add_state(char a[3], int i)
{
    int k;
    for (k = 0; k < i; k++)
    {
        if (strcmp(result[k], a) == 0)
        {
            return i;
        }
    }
    strcpy(result[i], a);

    return ++i;
}

void display(int n)
{
    int k = 0;
    printf("\n Epsilon closure of %s = { ", copy);
    while (k < n)
    {
        printf(" %s", result[k]);
        k++;
    }
    printf(" } \n");
}

void findclosure(char state[], int *i)
{
    FILE *INPUT;
    INPUT = fopen("input.dat", "r+");
    char state1[3], input[3], state2[3];
    int end, k;
    FILE *f;
    while (1)
    {
        end = fscanf(INPUT, "%s%s%s", state1, input, state2);
        if (end == EOF)
        {
            return;
        }

        if (strcmp(state, state1) == 0)
        {
            if (strcmp(input, "e") == 0)
            {
                *i = add_state(state2, *i);
                findclosure(state2, i);
            }
        }
    }
}

int main()
{

    char state[3], st1[3], st2[3], inp[3];
    int end, i = 0, n, k = 0, t;
    FILE *file = fopen("input.dat", "w");
    char state1[3], input[3], state2[3];
    printf("\n Enter the no of states: ");
    scanf("%d", &n);
    printf("\n Enter the states \n");
    for (k = 0; k < n; k++)
    {
        scanf("%s", states[k]);
    }
    printf("Enter number of transitions:");
    scanf("%d", &t);
    printf("Enter transitions\n");
    for (k = 0; k < t; k++)
    {
        scanf("%s%s%s", st1, inp, st2);
        fprintf(file, "%s %s %s\n", st1, inp, st2);
    }
    fclose(file);
    for (k = 0; k < n; k++)
    {
        i = 0;
        strcpy(state, states[k]);
        strcpy(copy, state);
        add_state(state, i++);
        findclosure(state, &i);
        display(i);
    }
    return 0;
}