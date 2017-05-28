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
| math_stack_opcodes.c | contains functions that perform math operations with node data (add, sub, mul, div, mod) |
| print_stack_opcodes.c     | contains functions that print elements of the list (pall, pint, pchar, pstr, prev) |
| push_stack_opcodes.c     | contains functions related to push node (push to beginning or end, check mode, switch mode)|
| stack_helper_funcs.c | contains helper functions (tokenize, list lenght, free list, is_int, is_empty)|

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
5. [math_stack_opcodes.c](math_stack_opcodes.c) - Includes all functions that deal with the environment:
  * ``add()`` - adds the top two elements of the stack, stores result in second element, and top element is removed
  * ``sub()`` - subtracts the top element from the second element, stores result in second element, and top element is removed
  * ``_div()`` - divides second element by the top element, stores result in second element, and top element is removed
  * ``mul()`` - multiplies the top two elements of the stack, stores result in second element, and top element is removed
  * ``mod()`` - computes the rest of the division of the second top element of the stack by the top element of the stack, stores result in second element, and top element is removed
6. [print_stack_opcodes.c](print_stack_opcodes.c) - Includes function to convert the environmental variable linked list into a double pointer array:
  * ``conv_list_to_array()`` - Converts the environmental linked list into a double pointer array
7. [push_stack_opcodes.c](push_stack_opcodes.c) - Includes functions to free memory:
  * ``free_input_list()`` - Frees the input linked list (Currently not in use)
  * ``free_env_list()`` - Frees the environmental variable linked list
  * ``free_env_array()`` - Frees the double pointer environmental variable array
  * ``free_path_array()`` - Frees the double pointer path array
  * ``free_mem()`` - Function that calls all the free functions
8. [stack_helper_funcs.c](stack_helper_funcs.c) - Includes a function to get the builtin functions:
  * ``*get_builtin_func()`` - Function pointer that points to the builtin function the user inputs
9. [AUTHORS](AUTHORS) - List of contributors.
10. [man_1_simple_shell](man_1_simple_shell) - Manual page for the shell.

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
After compiling, run the executable `./monty file`
```
$ ./monty bytecode/00.m
3
2
1
$
```
## Notes
Other builtins such as aliases, history, and or command separators are not supported and are currently in development.

## Known Bugs
There are no known bugs at the time.

### Authors
*Kimberly Wong* - [Github](https://github.com/kjowong) || [Twitter](https://twitter.com/kjowong) || [email](kimberly.wong@holbertonschool.com)

*Julija Lee* - [Github](https://github.com/FreeJules) || [Twitter](https://twitter.com/LeeJulija) || [email](julijalee@gmail.com)



#### Feedback and contributors welcomed. Reach out to either authors.


