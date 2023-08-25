#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
  * push - Pushes an element to stack
  * @stack: Stack
  * @n: Element to be pushed to stack
  *
  * Description: The function pushes an integer to the stack in LIFO order
  */
void push(stack_t **stack, unsigned int n)
{
	stack_t *new_elem;

	new_elem = malloc(sizeof(stack_t));
	if (new_elem == NULL)
		error_message("Error: malloc failed\n");
	new_elem->n = n;
	new_elem->prev = NULL;
	if (*stack ==  NULL)
	{
		new_elem->next = NULL;
		*stack = new_elem;
	}
	else
	{
		new_elem->next = *stack;
		(*stack)->prev = new_elem;
		*stack = new_elem;
	}
}

