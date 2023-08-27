#include "monty.h"

/**
  * pall - Prints values on the stack
  * @stack: Stack
  * @line_number: Line Number
  *
  * Description: Prints all values from the stack
  */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

