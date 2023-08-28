#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
  * mod - Divides the two top elements of the stack returning the rem
  * @stack: Stack
  * @line_number: Line number
  *
  */
void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fclose(bus.file);
		free_stack(*stack);
		error_message("L%ld: can't mod, stack too short\n", line_number);
	}
	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;
	if ((*stack)->next == NULL)
	{
		fclose(bus.file);
		free_stack(*stack);
		error_message("L%ld: can't mod, stack too short\n", line_number);
	}
	if ((*stack)->n == 0)
	{
		fclose(bus.file);
		free_stack(*stack);
		error_message("L%u: division by zero\n", line_number);
	}
	((*stack)->next)->n = ((*stack)->next)->n % (*stack)->n;
	pop(stack, line_number);
}
