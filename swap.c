#include "monty.h"

/**
  * swap - Swaps the two top elements of the stack
  * @stack: Stack
  * @line_number: Current line number
  *
  */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	int aux;

	h = *stack;
	if (!h)
	{
		fclose(bus.file);
		error_message("L%u: can't swap, stack too short\n", line_number);
	}
	while(h->prev)
		h = h->prev;
	if (!h->next)
	{
		free_stack(h);
		fclose(bus.file);
		error_message("L%u: can't swap, stack too short\n", line_number);
	}
	aux = h->n;
	h->n = (h->next)->n;
	(h->next)->n = aux;
}
