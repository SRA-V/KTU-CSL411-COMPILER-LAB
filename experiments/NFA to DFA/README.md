# NFA to DFA
## Algorithm
1. start
2. Insert transitions,final states,start states and symbols
3. inititialize states array with start state
4. initialize nfa states counter to 1 and nfa state pointer to 0
5. while state counter not equal to states pointer
    1. initialize s to empty
    2. for each symbol
        1. for each character in current state
            1. for each transition
                1. if transition is from current state character with current symbol
                    1. append the next state of transition to s 
        2. if s is empty print state[state pointer] symbol dead state
        3. else print state[state pointer] symbol s
            1. if s is not in states array add it
            2. Increment state counter
    3. Increment state pointer
6.for each state in state array
    1. if state contain any final state print the state
7. Stop
## Output
```
Number of transitions and final state:
4 1
Start state:
a
Final states:
c
Symbols:
12
Transitions:
a 1 a
a 2 a
a 2 b
b 2 c

a 1 a
a 2 ab
ab 1 a
ab 2 abc
abc 1 a
abc 2 abc
Final states:{abc,}
```
