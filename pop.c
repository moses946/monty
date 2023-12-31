#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
  * pop - Removes the top element from the stack
  * @stack: Stack
  * @line_number: Current line number
  *
  */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *pop_elem;

	if (*stack == NULL)
	{
		fclose(bus.file);
		free_stack(*stack);
		error_message("L%ld: can't pop an empty stack\n", line_number);
	}
	pop_elem = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(pop_elem);
}
