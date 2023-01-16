# Epsilon closure of all states
Write a program to find ε – closure of all states of any given NFA with ε transition.
## Algorithm
```
1. Define and initialize necessary arrays and variables .
2. Ask the user to enter the number of states and store the value in n
3. Ask the user to enter the number of transitions and store the value in t
4. Ask the user to enter the transitions
5. For t states use scanf to get the values of s1, trans, and s2
	5.1 If trans is equal to e, set arr[s1][s2] to 1
6. Print a message "The epsilon closures are : "
7. For i in the range of 0 to n-1, print the current state
	7.1. For i in the range of 0 to n-1, set visited[i] to 0
	7.2. Set the visited array to 0
	7.3. Call the function closure(i)
8. Define Closure function.
	8.1. set the visited value of i to 1
	8.2. For all remaining states , check if E transition exist and is not visited. 
        8.2.1. If yes , call closure of that state.
	    8.2.2. Call closure of current state ( for missing states due to recursion )
```
## Output

```
❯ ./a.out

Enter the no of states: 4
Enter number of transitions:4
Enter transitions
0 e 1
0 e 2
1 e 3
2 e 0

The epsilon closures are : 
State q0 : {q0,q1,q3,q2}
State q1 : {q1,q3}
State q2 : {q2,q0,q1,q3}
State q3 : {q3}

```