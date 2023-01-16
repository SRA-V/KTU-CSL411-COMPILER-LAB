#include <stdio.h>

int arr[10][10] ,visited[10];
int n, t, k, i, j, s1, s2;
char trans;

void closure(int i) {
    visited[i] = 1;
    for (j = 0; j < n; j++) {
        if (arr[i][j] == 1 && visited[j] != 1) {
            printf(",q%d", j);
            closure(j);
            closure(i);
        }
    }
}

int main() {

    printf("\nEnter the no of states: ");
    scanf("%d", &n);
    printf("Enter number of transitions:");
    scanf("%d", &t);

    printf("Enter transitions\n");
    for (i = 0; i < t; i++) {
        scanf("%d %c %d", &s1, &trans, &s2);
        if (trans == 'e') {
            arr[s1][s2] = 1;
        }
        printf("");
    }

    printf("\nThe epsilon closures are : ");
    for (i = 0; i < n; i++) {
        printf("\nState q%d : {q%d", i, i);
        for(int i =0; i<n;i++) visited[i] = 0;
        closure(i);
        printf("}");
    }

    printf("\n");
    return 0;
}
