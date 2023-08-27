#include "monty.h"

/**
  * push - Pushes an element to stack
  * @stack: Stack
  * @line_number: Current line number
  *
  * Description: The function pushes an integer to the stack in LIFO order
  */
void push(stack_t **stack, unsigned int line_number)
{
	int n, j = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] < 48 || bus.arg[j] > 57)
			{
				free_stack(*stack);
				fclose(bus.file);
				error_message("L%u: usage: push integer\n", line_number);
			}
		}
		n = atoi(bus.arg);
		if (bus.lifi == 0)
			addnode(stack, n);
	}
	else
	{
		fclose(bus.file);
		free_stack(*stack);
		error_message("L%u: usage: push integer\n", line_number);
	}
}

