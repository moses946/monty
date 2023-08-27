#include "monty.h"

/**
  * free_stack - frees the stack
  * @head: Pointer to the head of the stack
  *
  */
void free_stack(stack_t *head)
{
	while (head != NULL)
	{
		if (head->next == NULL)
		{
			free(head);
			break;
		}
		else
		{
			head = head->next;
			free(head->prev);
		}
	}
}
