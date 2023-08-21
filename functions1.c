#include "main.h"

/*** Function that prints unsigned Number ***/
/**
* print_unsigned - Function that prints unsigned number
* @types: Parameter count types
* @buffer: Buffer array handler parameters
* @flags: Active flags calculator
* @width: Parameters for get width
* @precision: Parameter of precision specifiers
* @size: Parameter for size specifiers
* Return: Char nums to be printed
*/

int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int r = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
num = convert_size_unsgnd(num, size);
if (num == 0)
buffer[r--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buffer[r--] = (num % 10) + '0';
num /= 10;
}
r++;
return (write_unsgnd(0, r, buffer, flags, width, precision, size));
}


/*** Function that prints unsigned num in Octal***/

/**
* print_octal - function that prints unsigned number octal num
* @types: Function parameter types
* @buffer: Array of buffers to printed
* @flags: Active flag calculators or estimators
* @width: Parameter get width
* @precision: Parameter for precision specifiers
* @size: Parameter for size specifiers
* Return: Char nums to be printed
*/

int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int r = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;
UNUSED(width);
num = convert_size_unsgnd(num, size);
if (num == 0)
buffer[r--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buffer[r--] = (num % 8) + '0';
num /= 8;
}
if (flags & F_HASH && init_num != 0)
buffer[r--] = '0';
r++;
return (write_unsgnd(0, r, buffer, flags, width, precision, size));
}


/*** Function that prints unsigned num in hexdecimal form ***/

/**
* print_hexadecimal - Fun that prints unsigned num in hexdecimal form
* @types: Parameter types
* @buffer: Array of buffers that handles printing
* @flags: Active flag calculators or estimators
* @width: Parameter that get width
* @precision: Parameter that specifies precision
* @size: Parameter that specifies size
* Return: char nums to be printed
*/

int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789abcdef", buffer,
flags, 'x', width, precision, size));
}


/*** Function that prints unsigned num in upper hexadecimal form ***/

/**
* print_hexa_upper - Function that prints upper hexadecimal num
* @types: Parameter types
* @buffer: Array Buffer for prints handling
* @flags: Active flag calculator
* @width: Parameter for get width
* @precision: Parameter that specifies precision
* @size: Parameter for size specifier
* Return: Charactors nums to be printed
*/

int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789ABCDEF", buffer,
flags, 'X', width, precision, size));
}


/*** Function that prints HEXX NUM in low of upper case ***/

/**
* print_hexa - Fun that prints hexadecimal number in lower or upper case
* @types: Parameter arguments
* @map_to: Mapped array values
* @buffer: Array of buffers that handles printing
* @flags: Active flag calculator or estimator
* @flag_ch: Ch active flags calculator or estimator
* @width: Parameter for get width
* @precision: Parameter for precision specifiers
* @size: Parameter for size specifier
* Return: Charactors nums to be printed
*/

int print_hexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
int r = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;
UNUSED(width);
num = convert_size_unsgnd(num, size);
if (num == 0)
buffer[r--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buffer[r--] = map_to[num % 16];
num /= 16;
}
if (flags & F_HASH && init_num != 0)
{
buffer[r--] = flag_ch;
buffer[r--] = '0';
}
r++;
return (write_unsgnd(0, r, buffer, flags, width, precision, size));
}
