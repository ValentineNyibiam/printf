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
	int i, fcount = 0;
	va_list vargs;

	va_start(vargs, format);

	/* Check if format is NULL */
	if (format == NULL)
		return (-1);

	/* Parse format string to print */
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
			fcount += print_char(format[i]);
		else if (format[i] == '%')
		{
			format++;
			fcount += format_handler(format[i], vargs);
		}
	}

	/* Free va_list */
	va_end(vargs);

	/* Return the number of characters printed */
	return (fcount);
}

/**
 * print_char - Prints a character to the stdout
 * @ch: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately
 */
int print_char(char ch)
{
	return (write(1, &ch, 1));

}
