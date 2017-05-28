# Monty

This project is about creating an intepreter that interprets and compiles Monty bytecode files. 

## Environment
Our Monty interpreter has been tested on Ubuntu 14.05.5 LTS

Tests done in VirtualBox on [Ubuntu](https://atlas.hashicorp.com/ubuntu/boxes/trusty64) via [Vagrant](https://www.vagrantup.com/)(1.9.1)

## Repository Breakdown
Once cloned over, the repository will contain the following files:

|   **File**    |  **Decription**                       |
|---------------|---------------------------------------|
| monty.h   | header file with prototypes           |
| main.c      | contains main function to Monty        |
| find_opcode.c | function pointer to find correct function |
| manipulate_stack_opcodes.c     | contains functions that manipulate the stack (pop, swap, nop, rotl, rotr) |
| math_stack_opcodes.c | contains functions that perform math operations on node data (add, sub, mul, div, mod) |
| print_stack_opcodes.c     | contains functions that print elements of the list (pall, pint, pchar, pstr, prev) |
| push_stack_opcodes.c     | contains functions related to push node (push to beginning or end, check mode, switch mode)|
| stack_helper_funcs.c | contains helper functions (tokenize, list length, free list, is_int, is_empty)|
| brainfuck | subdirectory with brainfuck programs |

## Description of File Structure
1. [monty.h](monty.h) - Header file that includes prototypes and structs
2. [main.c](main.c) - File includes the main monty function
  * ``main()`` - initializes global variable, opens file for reading, uses a loop to read file line by line
3. [find_opcode.c](find_opcode.c) - Function to find correct function pointer depending on opcode
  * ``find_opcode()`` - uses array of instruction_t structs to find appropriate function pointer depending on opcode
4. [manipulate_stack_opcodes.c](manipulate_stack_opcodes.c) - Functions that manipulate the stack:
  * ``pop()`` - removes the top element of the stack
  * ``swap()`` - swaps the top two elements of the stack
  * ``nop()`` - does nothing
  * ``rotl()`` - rotates the stack to the top, top element becomes the last one, and second element becomes the first one
  * ``rotr()`` - rotates the stack to the bottom, last element becomes the top element of the stack  
5. [math_stack_opcodes.c](math_stack_opcodes.c) - Functions that perform math operations on node data:
  * ``add()`` - adds the top two elements of the stack, stores result in second element, and top element is removed
  * ``sub()`` - subtracts the top element from the second element, stores result in second element, and top element is removed
  * ``_div()`` - divides second element by the top element, stores result in second element, and top element is removed
  * ``mul()`` - multiplies the top two elements of the stack, stores result in second element, and top element is removed
  * ``mod()`` - computes the rest of the division of the second top element of the stack by the top element of the stack, stores result in second element, and top element is removed
6. [print_stack_opcodes.c](print_stack_opcodes.c) - Functions that print elements of the list:
  * ``pall()`` - prints all the values on the stack, starting from the top of the stack
  * ``pint()`` - prints the value at the top of the stack, followed by a new line
  * ``pchar()`` - prints the char at the top of the stack, followed by a new line
  * ``pstr()`` - prints the string starting at the top of the stack, followed by a new line
  * ``prev()`` - prints all the elements of a list in reverse
7. [push_stack_opcodes.c](push_stack_opcodes.c) - Functions related to push node:
  * ``push_node()`` - adds new node to the beginning of doubly linked list (stack mode)
  * ``push_node_mode()`` - checks what mode we are using (stack or queues) and calls the appropriate push function
  * ``push_node_end()`` - function that adds new node to the end of doubly linked list (queue mode)
  * ``stack()`` - sets the format of the data to a stack (LIFO)
  * ``queue()`` - sets the format of the data to a queue (FIFO)
8. [stack_helper_funcs.c](stack_helper_funcs.c) - Helper functions:
  * ``tokenize()`` - tokenizes the line from Monty bytecode file
  * ``is_empty()`` - checks if line needs to be tokenized
  * ``is_int()`` - checks if string contains all digits
  * ``list_len()`` - returns the number of elements in a list
  * ``free_list()`` - frees a list

## How to Use
First step is to clone the repository into your directory
```
$ git clone https://github.com/kjowong/monty.git
```
Compile all the `.c` files in monty
```
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

## Example of Use
After compiling, run the executable `./monty` on your bytecode file.
```
$ ./monty 00.m
3
2
1
$
```
## Notes
Other functionalities are currently in development.

## Known Bugs
Currently the interpreter relies on the atoi function from the C standard library and overflows are not handled.

### Authors
*Kimberly Wong* - [Github](https://github.com/kjowong) || [Twitter](https://twitter.com/kjowong) || [email](kimberly.wong@holbertonschool.com)

*Julija Lee* - [Github](https://github.com/FreeJules) || [Twitter](https://twitter.com/LeeJulija) || [email](julijalee@gmail.com)



#### Feedback and contributors welcomed. Reach out to either authors.


