#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
  * swap - Swaps the two top elements of the stack
  * @stack: Stack
  * @line_number: Current line number
  *
  */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL)
	{
		fclose(bus.file);
		free_stack(*stack);
		error_message("L%ld: can't swap, stack too short", line_number);
	}
	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;
	if ((*stack)->next == NULL)
	{
		free_stack(*stack);
		fclose(bus.file);
		error_message("L%ld: can't swap, stack too short", line_number);
	}
	temp = *stack;
	*stack  = (*stack)->next;
	temp->next = (*stack)->next;
	temp->prev = *stack;
	((*stack)->next)->prev = temp;
	(*stack)->next = temp;
	(*stack)->prev = NULL;
}
