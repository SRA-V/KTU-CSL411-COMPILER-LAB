# First and Follow
Write a program to find First and Follow of any given grammar.

## Algorithm
1. Get the number of productions in the grammar.
2. Read the productions and store them in an array.
3. Get the element whose First and Follow need to be found.
4. Call the "first" function passing the element as argument.
    1. If its a terminal, add itself to the first array.
    2. Check if the Production rule start with passed element. If yes
        1. check if the first element after '=' is an uppercase(Non-terminal) or lowercase (terminal).
        2. If lower, add that to the first array.
        3. If upper, call first() on that element.
5. Call the "follow" function passing the element as argument.
    1. if its Starting production, add $ to follow array.
    2. For each production, check if the symbol appears in the production.If yes:
        1. If its not the last symbol in production, calculate the First of the symbol
        2. if it's the last, calculate the Follow of the first symbol of that production.
6. Print the First and Follow of the element.

## Output

```
❯ ./a.out

No of prooductions : 3

Enter the productions :
S=aAbc
A=c
A=d

Element whose first & follow is to be found : S
First(S)={a }
Follow(S)={$ }

Continue(0/1) : 1

Element whose first & follow is to be found : A
First(A)={c d }
Follow(A)={b }

Continue(0/1) : 0

```
