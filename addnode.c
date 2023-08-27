#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
  * addnode - Pushes an element to stack
  * @head: head of the stack
  * @n: Element to be pushed to stack
  *
  * Description: The function pushes an integer to the stack in LIFO order
  */
void addnode(stack_t **head, int n)
{
	stack_t *new_elem, *aux;

	aux = *head;
	new_elem = malloc(sizeof(stack_t));
	if (new_elem == NULL)
		error_message("Error: malloc failed\n");
	new_elem->n = n;
	new_elem->prev = NULL;
	if (aux)
		aux->prev = new_elem;
	new_elem->next = *head;
	*head = new_elem;
}

