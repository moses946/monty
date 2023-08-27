#include "monty.h"

/**
  * swap - Swaps the two top elements of the stack
  * @stack: Stack
  * @line_number: Current line number
  *
  */
void swap(stack_t **stack, unsigned int line_number)
{
	stack *h;
	int aux;

	h = *stack;
	while(h->prev)
		h = h->prev;
	if (!h->next)
	{
		free_stack(h);
		fclose(buf.file);
		error_message("L%u: can't swap, stack too short", line_number);
	}
	aux = h->n;
	h->n = (h->next)->n;
	(h->next)->n = aux;
}
