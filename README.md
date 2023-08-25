###MONTY
# 0x19. C - Stacks, Queues - LIFO, FIFO
**About:** This is a simple interpreter for Monty Bytecodes. The interpreter reads a bytecode file and executes the bytecode commands provided.
### The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.
### Monty ByteCode files
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument.
### Compilation & Output
These codes were compiled using: ```gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty```
All output is printed on ```stdout```
Any error message is printed on ```stderr```
#### USAGE
Clone this repository to your local machine by running ```git clone https://github.com/moses946/monty.py```
Navigate to the ```monty``` directory
Compile the files to an executable:
```console
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```
Execute the monty file:
```console
./monty <file>
```