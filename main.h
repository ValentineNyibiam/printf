#ifndef MAIN_H
#define MAIN_H

/* Standard header files */
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

/* Protoypes */
int _printf(const char *format, ...);
int print_char(char ch);
int format_handler(char fchar, va_list vargs);
int print_string(char *str);
int print_num(int num);
int print_bin(unsigned int num);

#endif /* MAIN_H */
