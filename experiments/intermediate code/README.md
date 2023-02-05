# Intermediate code
Implement Intermediate code generation for simple expressions.<br>
Here we are generating **postfix notation**.

## Algorithm
1. Initialize stack top to -1
2. Read the infix expression
3. Loop through the infix expression:
    1. If the current character is an alphabet, add it to the postfix string.
    2. If the current character is an opening parenthesis, push it onto the stack.
    3. If the current character is a closing parenthesis, pop all the operators from the stack and add them to the postfix string until an opening parenthesis is encountered. Pop the opening parenthesis.
    4. If the current character is an operator, pop all the operators with higher or equal precedence from the stack and add them to the postfix string. Push the current operator onto the stack.
4. Pop all the operators from the stack and add them to the postfix string.
5. Terminate the loop.
6. Call the three address code generator function with postfix string as the argument.
7. Initialize a temporary variable t1 to 90 and assign it to the result of the expression.
8. Loop through the postfix string:
    1. If the current character is an alphabet, push it onto the stack.
    2. If the current character is an operator, pop the two operands from the stack, generate the three address code by printing the assignment of the expression to a new temporary variable and push the temporary variable onto the stack.
9. Terminate the loop.
10. End.

## Output

```
❯ ./a.out

Enter an simple expression: (a+b)*(c+d)

Z := a + b
Y := c + d
X := Z * Y
```