#include "monty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFSIZE 1024

instruction_t instructions[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop},
	{NULL, NULL}
};

/**
  * main - Entry point
  * @argc: Argument count
  * @argv: Argument vector
  *
  * Return: Always 0 on success
  */
int main(int argc, char **argv)
{
	FILE *file_ptr;
	stack_t *stack = NULL;
	char buffer[BUFSIZE];
	char *opcode, *argument;
	int n, i, found;
	unsigned int line_number = 0;

	if (argc != 2)
		error_message("USAGE: monty file\n");
	file_ptr = fopen(argv[1], "r");
	if (file_ptr == NULL)
		error_message("Error: Can't open file %s\n", argv[1]);
	while (fgets(buffer, BUFSIZE, file_ptr))
	{
		found = 0;
		i = 0;
		line_number++;
		opcode = strtok(buffer, " \n");
		argument = strtok(NULL, " \n");
		while (instructions[i].opcode != NULL)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				if (strcmp("push", opcode) == 0)
				{
					n = atoi(argument);
					if (n == 0 && strcmp(argument, "0") != 0)
						error_message("L%ld: usage: push integer\n", line_number);
					instructions[i].f(&stack, n);

				}
				else
					instructions[i].f(&stack, line_number);
				found = 1;
				break;
			}
			i++;
		}
		if (!found)
			error_message("L%ld: unknown instruction %s\n", line_number, opcode);
	}
	return (0);
}