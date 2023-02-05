#include <stdio.h>
#include <string.h>
int main()
{
    FILE *f = fopen("input.txt", "r+");
    char res[3], op[2], op1[2], op2[2], eq[2];
    while (fscanf(f, "%s %s %s %s %s", res, eq, op1,op, op2) != EOF)
    {
        printf("MOV AX,[%s]\n", op1);
        switch (op[0])
        {
        case '+':
            printf("ADD AX,[%s]\n", op2);
            break; // AX=AX+memory
        case '-':
            printf("SUB AX,[%s]\n", op2);
            break; // AX=AX-memory
        case '*':
            printf("MOV BX,[%s]\nMUL BX\n", op2);
            break; // AX=AX*BX
        case '/':
            printf("MOV BX,[%s]\nDIV BX\n", op2);
            break; // Quotient in AX reminder in DX
        }
        printf("MOV [%s],AX\n", res);
    }
}