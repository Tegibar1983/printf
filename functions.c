#include "main.h"


/*** Print charactor files ***/

/**
 * print_char - Prints charactors
 * @types: Count of arguments
 * @buffer: Print buffer array handlers
 * @flags:  Active flags estimator
 * @width: Width of specifier
 * @precision: Precision specifier files
 * @size: Size of specifiers in the file
 * Return: print charactor of chars to be printed
 */

int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char x = va_arg(types, int);
return (handle_write_char(x, buffer, flags, width, precision, size));
}



/*** Print string files ***/
/**
 * print_string - Function that print strings
 * @types: Count of arguments
 * @buffer: Prints buffer arrays to be handled
 * @flags:  Active flags estimator
 * @width: Width calculator
 * @precision: Parameter that specifies Precision
 * @size: Parameter that specifies size
 * Return: List of charactors to be printed
 */


int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int length = 0, r;
char *s = va_arg(types, char *);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (s == NULL)
{
s = "(null)";
if (precision >= 6)
s = " ";
}
while (s[length] != '\0')
length++;
if (precision >= 0 && precision < length)
length = precision;
if (width > length)
{
if (flags & F_MINUS)
{
write(1, &s[0], length);
for (r = width - length; r > 0; r--)
write(1, " ", 1);
return (width);
}
else
{
for (r = width - length; r > 0; r--)
write(1, " ", 1);
write(1, &s[0], length);
return (width);
}
}
return (write(1, s, length));
}


/***Function that prints perecent sign***/

/**
 * print_percent - Function that prints percent sign
 * @types: count of arguments
 * @buffer: Array buffer that handles files to be printed
 * @flags:  Active flags to be estimated
 * @width: Width calculator
 * @precision: Parameter that specifies Precision
 * @size: Parameter that specifies size
 * Return: List of charactors to be printed
 */


int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
UNUSED(types);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
return (write(1, "%%", 1));
}


/*** Function that prints int***/
/**
 * print_int - Function that print Integers
 * @types: Count of arguments
 * @buffer: Array of buffer that handles print
 * @flags:  Active flags Estimator
 * @width: Width estimator file
 * @precision: Parameter that specifies Precision
 * @size: Parameter that specifies size
 * Return: List of charactors to be printed
 */

int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int r = BUFF_SIZE - 2;
int is_negative = 0;
long int m = va_arg(types, long int);
unsigned long int num;
m = convert_size_number(m, size);
if (m == 0)
buffer[r--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
num = (unsigned long int)m;
if (m < 0)
{
num = (unsigned long int)((-1) * m);
is_negative = 1;
}
while (num > 0)
{
buffer[r--] = (num % 10) + '0';
num /= 10;
}
r++;
return (write_number(is_negative, r, buffer, flags, width, precision, size));
}


/*** Function that prints Binary ***/

/**
 * print_binary - Function that prints a binary num
 * @types: count of arguments in the function
 * @buffer: Array buffer that handles print
 * @flags:  Active flags estimator
 * @width: Width estimator file
 * @precision: Parameter that specifies precision
 * @size: Parameter that calulates size
 * Return: List of charactors printed
 */


int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
unsigned int m, n, r, sum;
unsigned int z[32];
int count;
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
m = va_arg(types, unsigned int);
n = 2147483648;

/*** (2 ^ 31) ***/

z[0] = m / n;
for (r = 1; r < 32; r++)
{
n /= 2;
z[r] = (m / n) % 2;
}
for (r = 0, sum = 0, count = 0; r < 32; r++)
{
sum += z[r];
if (sum || r == 31)
{
char a = '0' + z[r];
write(1, &a, 1);
count++;
}
}
return (count);
}

