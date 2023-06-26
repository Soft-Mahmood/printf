#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int print_char(va_list list);
int print_string(va_list list);
int print_integer(va_list list);
int unsigned_integer(va_list list);
int print_percent(va_list list);
int print_unsigned_number(unsigned int n);
int print_number(va_list args);

#endif