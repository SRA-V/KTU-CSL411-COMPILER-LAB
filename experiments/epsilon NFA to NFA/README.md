# Epsilon NFA to NFA
## Algorithm
1. Start
2. Insert the epsilon nfa transitions anf final states
3. For each ε tranition a ε b replace it with new transition
  - if there are transition from b, add a new trasition from a with same symbol and state
4.  for any state there is an ε transition to final state add it to the set of final states
5.  Print the NFA without ε trantitions and final state
6.  Stop
## Output
