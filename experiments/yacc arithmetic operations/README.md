# Yacc arithmetic operations
Generate a YACC specification to recognize a valid arithmetic expression that uses operators +, – , *,/ and parenthesis.
## Algorithm

## Output
```
❯ lex lex.l 

❯ yacc -d yacc.y

❯ gcc lex.yy.c y.tab.c -w 

❯ ./a.out

Enter the expression: a+b
Valid Expression!

❯ ./a.out

Enter the expression: ab*
Invalid Expression!

```
