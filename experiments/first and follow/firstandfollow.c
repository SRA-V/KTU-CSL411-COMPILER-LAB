#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m , p, i , j ;
char production[10][10], f[10];
void follow(char c);
void first(char c);

int main() {
  int z;
  char c;
  printf("\nNo of prooductions : ");
  scanf("%d", &n);
  printf("\nEnter the productions :\n");
  for (i = 0; i < n; i++) {
    scanf("%s", production[i]);
    getchar(); // to remove error caused by enter key
  }
  do {
    printf("\nElement whose first & follow is to be found : ");
    scanf("%c", &c);

    m = 0;
    first(c);
    printf("First(%c)={", c);
    for (i = 0; i < m; i++)
      printf("%c ", f[i]);
    printf("}\n");
    strcpy(f, " ");

    m = 0;
    follow(c);
    printf("Follow(%c)={", c);
    for (i = 0; i < m; i++)
      printf("%c ", f[i]);
    printf("}\n");

    printf("\nContinue(0/1) : ");
    scanf("%d", &z);
    getchar(); // to remove error caused by enter key
  } while (z == 1);

  return (0);
}

void first(char c) {
  int k;
  if (!isupper(c))
    f[m++] = c;
  for (k = 0; k < n; k++) {
    if (production[k][0] == c) {
       if (islower(production[k][2]))
        f[m++] = production[k][2];
      else
        first(production[k][2]);
    }
  }
}

void follow(char c) {
  if (production[0][0] == c)
    f[m++] = '$';
  for (i = 0; i < n; i++) {
    for (j = 2; j < strlen(production[i]); j++) {
      if (production[i][j] == c) {
        if (production[i][j + 1] != '\0')
          first(production[i][j + 1]);
        if (production[i][j + 1] == '\0' && c != production[i][0])
          follow(production[i][0]);
      }
    }
  }
}