#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};
#define BUFSIZE 1024

/**
  * main - Entry point
  * @argc: Argument count
  * @argv: Argument vector
  *
  * Return: Always 0 on success
  */
int main(int argc, char **argv)
{
	FILE *file_ptr;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	char content[BUFSIZE];

	if (argc != 2)
		error_message("USAGE: monty file\n");
	file_ptr = fopen(argv[1], "r");
	bus.file = file_ptr;
	if (!file_ptr)
	{
		free_stack(stack);
		error_message("Error: Can't open file %s\n", argv[1]);
	}
	while (fgets(content, BUFSIZE, file_ptr))
	{
		line_number++;
		bus.content = content;
		execute(content, &stack, line_number, file_ptr);
	}
	fclose(file_ptr);
	free_stack(stack);
	return (0);
}
