#include "monty.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/**
  * error_message - Prints error messages to stderr
  * @format: Error message
  *
  */
void error_message(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
	exit(EXIT_FAILURE);
}
