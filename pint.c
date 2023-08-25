#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
  * pint - Prints the value at the top of the stack
  * @stack: Stack
  * @line_number: current line number
  *
  */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
		error_message("L%ld: can't pint, stack empty\n", line_number);
	printf("%d\n", (*stack)->n);
}
