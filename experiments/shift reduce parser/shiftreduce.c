#include <stdio.h>
#include <string.h>
int z = 0, i = 0, j = 0, len = 0;
char buffer[16], ac[20], stk[15], act[10];
void check();

int main() {
  printf("\nGRAMMAR is \n E->E+E \n E->E*E \n E->(E) \n E->id \n");
  printf("\nEnter input string : ");
  scanf("%s", buffer);
  len = strlen(buffer);
  printf("stack \t input \t action\n");
  for (i = 0; j < len; i++, j++) {
    if (buffer[j] == 'i' && buffer[j + 1] == 'd') {
      stk[i] = buffer[j];
      stk[i + 1] = buffer[j + 1];
      stk[i + 2] = '\0';
      buffer[j] = ' ';
      buffer[j + 1] = ' ';
      printf("\n$%s\t%s$\tSHIFT->id", stk, buffer);
      check();
    } else {
      stk[i] = buffer[j];
      stk[i + 1] = '\0';
      buffer[j] = ' ';
      printf("\n$%s\t%s$\tSHIFT->symbol %c", stk, buffer,stk[i]);
      check();
    }
  }
}
void check() {

  for (z = 0; z <= len; z++)
    if (stk[z] == 'i' && stk[z + 1] == 'd') {
      stk[z] = 'E';
      stk[z + 1] = '\0';
      printf("\n$%s\t%s$\tREDUCE TO E", stk, buffer);
      j++;
    }

  for (z = 0; z <= len; z++)
    if (stk[z] == 'E' && stk[z + 1] == '+' && stk[z + 2] == 'E') {
      stk[z] = 'E';
      stk[z + 1] = '\0';
      printf("\n$%s\t%s$\tREDUCE TO E", stk, buffer);
      i = i - 2;
    }

  for (z = 0; z <= len; z++)
    if (stk[z] == 'E' && stk[z + 1] == '*' && stk[z + 2] == 'E') {
      stk[z] = 'E';
      stk[z + 1] = '\0';
      printf("\n$%s\t%s$\tREDUCE TO E", stk, buffer);
      i = i - 2;
    }
    
  for (z = 0; z <= len; z++)
    if (stk[z] == '(' && stk[z + 1] == 'E' && stk[z + 2] == ')') {
      stk[z] = 'E';
      stk[z + 1] = '\0';
      printf("\n$%s\t%s$\tREDUCE TO E", stk, buffer);
      i = i - 2;
    }
}