#include "monty.h"

/**
  * execute - Executes the opcode command
  * @content: Line content
  * @stack: stack
  * @lno: current line number
  * @file: Pointer to the monty file open
  *
  * Return: 0 on success and 1 on faliure
  */
int execute(char *content, stack_t **stack, unsigned int lno, FILE *file)
{
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
	char *opcode;
	int i = 0;

	opcode = strtok(content, " \n\t");
	if (opcode && opcode[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (instructions[i].opcode && opcode)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			instructions[i].f(stack, lno);
			return (0);
		}
		i++;
	}

	if (opcode && instructions[i].opcode == NULL)
	{
		fclose(file);
		free_stack(*stack);
		error_message("L%u: unknown instruction %s\n", lno, opcode);
	}
	return (1);
}
