#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char c) {
    stack[++top] = c;
}
char pop() {
    return stack[top--];
}
int priority(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    for (i = 0; infix[i]; i++) 
        if (isalpha(infix[i]))
            postfix[j++] = infix[i];
        else if (infix[i] == '(')
            push(infix[i]);
        else if (infix[i] == ')') {
            while (stack[top] != '(')
                postfix[j++] = pop();
            pop();
        } else {
            while (priority(stack[top]) >= priority(infix[i]))
                postfix[j++] = pop();
            push(infix[i]);
        }
    while (top >= 0)
        postfix[j++] = pop();
    postfix[j] = '\0';
}
void threeadd(char *str){
    top=-1;
    int t1=90;
    char t2,t3;
    for(int i=0;i<strlen(str);i++){
        if(isalpha(str[i])){
            push(str[i]);
        }else{
            t3=pop();
            t2=pop();
            printf("%c := %c %c %c\n",t1,t2,str[i],t3);
            push(t1--);
        }
    }
}
int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter an simple expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    threeadd(postfix);
    return 0;
}
