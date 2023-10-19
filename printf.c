#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: The format/character string
 * @...: The variable arguments of the function
 *
 * Return: The number of characters printed,
 * excluding the null byte used to end output to strings.
 */
int _printf(const char *format, ...)
{
	/* Declare and initalize variables */
	int fcount = 0, i;
	va_list vargs;

	/* Check if format is NULL */
	if (!(*format))
		return (-1);

	/* Parse format string to print */
	va_start(vargs, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			fcount += format_handler(vargs, format[i]);
		}
		else
			fcount += print_char(format[i]);
	}

	/* Free va_list */
	va_end(vargs);

	/* Return the number of characters printed */
	return (fcount);
}
