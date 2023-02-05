# Backed of the compiler
Program to convert three address code into 8086 assembly instructions.

## Algorithm

1. Open the file "input.txt" for reading and writing.
2. Initialize variables res, op, op1, op2 and eq as character arrays.
3. Use fscanf function to read the input from the file and store in the variables.
4. Repeat steps 5 to 7 until end of file (EOF) is reached.
5. Print the assembly code to move the contents of op1 to the AX register.
6. Check the value of op[0] and perform the following operations based on its value:
    1. If op[0] is '+', print the assembly code to add the contents of op2 to AX register.
    2. If op[0] is '-', print the assembly code to subtract the contents of op2 from AX register.
    3. If op[0] is '*', print the assembly code to move the contents of op2 to BX register and multiply AX and BX.
    4. If op[0] is '/', print the assembly code to move the contents of op2 to BX register and divide AX by BX.
7. Print the assembly code to move the contents of AX to the memory location specified by res.
8. End.

## Output
The file **input.txt** contains the following
```
X = a + b
Y = X * c
Z = Y / e
```

```
❯ ./a.out

MOV AX,[a]
ADD AX,[b]
MOV [X],AX
MOV AX,[X]
MOV BX,[c]
MUL BX
MOV [Y],AX
MOV AX,[Y]
MOV BX,[e]
DIV BX
MOV [Z],AX
```
