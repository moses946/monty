#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
  * add - Adds the two top elements of the stack
  * @stack: Stack
  * @line_number: Line number
  *
  */
void add(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
	{
		fclose(bus.file);
		free_stack(*stack);
		error_message("L%ld: can't add, stack too short", line_number);
	}
	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;
	if ((*stack)->next == NULL)
	{
		fclose(bus.file);
		free_stack(*stack);
		error_message("L%ld: can't add, stack too short", line_number);
	}
	((*stack)->next)->n += (*stack)->n;
	pop(stack, line_number);
}
