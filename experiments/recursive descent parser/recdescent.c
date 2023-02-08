// E7Recursive descent calculator
// E->TE'
// T->FT'
// E'->+TE'|-TE'|ep
// T'->*FT'|/FT'|ep
// F->(E)|alnum
#include <stdio.h>
#include <string.h>
#include <ctype.h>
char input[10];
int i, error;
void E();
void T();
void Eprime();
void Tprime();
void F();
int main()
{
    i = 0;
    error = 0;
    printf("\nEnter an arithmetic expression   :  "); 
    scanf("%s", input);
    E();
    if (strlen(input) == i && error == 0)
        printf("\nString accepted..!!!\n");
    else
        printf("\nString rejected..!!!\n");
}
void E()
{
    T();
    Eprime();
}
void Eprime()
{
    if (input[i] == '+' || input[i] == '-')
    {
        i++;
        T();
        Eprime();
    }
}
void T()
{
    F();
    Tprime();
}
void Tprime()
{
    if (input[i] == '*' || input[i] == '/')
    {
        i++;
        F();
        Tprime();
    }
}
void F()
{
    if (isalnum(input[i]))
        i++;
    else if (input[i] == '(')
    {
        i++;
        E();
        if (input[i] == ')')
            i++;

        else
            error = 1;
    }
    else
        error = 1;
}