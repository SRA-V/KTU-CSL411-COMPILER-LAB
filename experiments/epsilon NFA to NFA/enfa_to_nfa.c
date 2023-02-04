#include <stdio.h>
#include <string.h>
char enfa[20][3], final[30];
int ntrans;
int isin(char c, char str[])
{
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == c)
            return 1;
    return 0;
}
void add(char str[], char c)
{
    if (!isin(c, str))
    {
        int len = strlen(str);
        str[len] = c;
        str[len + 1] = '\0';
    }
}
void addstate(char c1, char c2)
{
    for (int i = 0; i < ntrans; i++)
        if (enfa[i][0] == c2 && enfa[i][1] != 'e')
            printf("%c %c %c\n", c1, enfa[i][1], enfa[i][2]);
        else if(enfa[i][0] == c2 && enfa[i][1] == 'e'&&enfa[i][2]!=c1)
            addstate(c1,enfa[i][2]);
}
int main()
{
    int i;
    printf("Enter number of transitions:");
    scanf("%d", &ntrans);
    printf("Enter transitions as \nstate symbol state\n");
    for (i = 0; i < ntrans; i++)
        scanf(" %c %c %c", &enfa[i][0], &enfa[i][1], &enfa[i][2]);
    printf("Final states:");
    scanf("%s", final);
    printf("NFA transitions\n");
    for (i = 0; i < ntrans; i++)
        if (enfa[i][1] != 'e')
            printf("%c %c %c\n", enfa[i][0], enfa[i][1], enfa[i][2]);
        else
            addstate(enfa[i][0], enfa[i][2]);
    for (i = ntrans - 1; i >= 0; i--)
        if (isin(enfa[i][2], final) && enfa[i][1] == 'e')
            add(final, enfa[i][0]);
    printf("Final states : {%s}", final);
}
