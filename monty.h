#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

/**
  * struct stack_s - doubly linked list representation of a stack (or queue)
  * @n: integer
  * @prev: points to the previous element of the stack
  * @next: points to the next element of the stack
  *
  * Description: doubly linked list node structure
  * for stack, queues, LIFO, FIFO
  */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
  * struct instruction_s - opcode and its function
  * @opcode: the opcode
  * @f: function to handle the opcode
  *
  * Description: opcode and its function
  * for stack, queues, LIFO, FIFO
  */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
  * bus_s - global variables
  * @file: File
  * @content: line content
  * @counter: line number
  * @args: opcode argument
  * @lifo: option btw stack and queue
  *
  * Description: contains global variables used across all files
  */
typedef struct bus_s
{
	FILE *file;
	char *content;
	char *arg;
	int lifi;
} bus_t;
extern bus_t bus;

int execute(char *content, stack_t **stack, unsigned int line_number, FILE *file);
void free_stack(stack_t *stack);
void addnode(stack_t **head, int n);
void push(stack_t **stack, unsigned int n);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void error_message(const char *format, ...);

#endif /*MONTY_H*/
