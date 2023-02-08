# Shift reduce parser
Construct a Shift Reduce Parser for a given language

## Algorithm

1. Initialize variables:
    1. buffer: to store the input string
    2. stk: to store the intermediate results
    3. len: to store the length of the input string
2. Input the string to be parsed and store it in the buffer
3. Set the length of the input string to the variable "len"
4. For each character in the buffer, check if it and the next character form "id".
5. If the next 2 characters are "id", shift and store both characters into the stack.
6. If the characters are not "id", shift the character into the stack.
7. Call the check function to reduce the stack according to the grammar.
8. In the check function, check for the patterns 'id', 'E + E', 'E * E', and '(E)'.
9. If any of the patterns is found, replace it with 'E' in the stack and update the stack.
10. Repeat steps 7-9 until the stack contains only one element and input becomes empty.

## Output

```
❯ ./a.out

GRAMMAR is 
 E->E+E 
 E->E*E 
 E->(E) 
 E->id 

Enter input string : id+id*id+id

stack    input   action

$id       +id*id+id$    SHIFT->id
$E        +id*id+id$    REDUCE TO E
$E+        id*id+id$    SHIFT->symbol +
$E+id        *id+id$    SHIFT->id
$E+E         *id+id$    REDUCE TO E
$E           *id+id$    REDUCE TO E
$E*           id+id$    SHIFT->symbol *
$E*id           +id$    SHIFT->id
$E*E            +id$    REDUCE TO E
$E              +id$    REDUCE TO E
$E+              id$    SHIFT->symbol +
$E+id              $    SHIFT->id
$E+E               $    REDUCE TO E
$E                 $    REDUCE TO E

```
