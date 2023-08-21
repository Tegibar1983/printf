#include "main.h"

/*** Pointer Printer functions ***/
/**
* print_pointer - Function that prints pointer variable
* @types: Function parameter types
* @buffer: Handle printing array buffers
* @flags: Flag calculator
* @width: Parameter for get width variable
* @precision: Parameter that specifeies precision
* @size: Parameter that specifies Size
* Return: Char nums to be printed
*/

int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char extra_c = 0, padd = ' ';
int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;

/*** variable Length = 2, for "0x" ***/


unsigned long num_addrs;
char map_to[] = "0123456789abcdef";
void *addrs = va_arg(types, void *);
UNUSED(width);
UNUSED(size);
if (addrs == NULL)
return (write(1, "(nil)", 5));
buffer[BUFF_SIZE - 1] = '\0';
UNUSED(precision);
num_addrs = (unsigned long)addrs;
while (num_addrs > 0)
{
buffer[ind--] = map_to[num_addrs % 16];
num_addrs /= 16;
length++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';
if (flags & F_PLUS)
extra_c = '+', length++;
else if (flags & F_SPACE)
extra_c = ' ', length++;
ind++;

/***return (write(1, &buffer[r], BUFF_SIZE - r - 1)); prototype ***/

return (write_pointer(buffer, ind, length,
width, flags, padd, extra_c, padd_start));
}


/***Print non printables function ***/
/**
* print_non_printable - Fun that prints ascii codes for not printaable hexa
* @types: Parameter types
* @buffer: Array buffer that handles printing
* @flags: Flags calculator
* @width: Parameter for get width
* @precision: Parameter that specifies precision
* @size: Parameter size specifier
* Return: Char nums to be printed
*/

int print_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int r = 0, offset = 0;
char *s = va_arg(types, char *);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (s == NULL)
return (write(1, "(null)", 6));
while (s[r] != '\0')
{
if (is_printable(s[r]))
buffer[r + offset] = s[r];
else
offset += append_hexa_code(s[r], buffer, r + offset);
r++;
}
buffer[r + offset] = '\0';
return (write(1, buffer, r + offset));
}


/*** Reverse print functions ***/
/**
* print_reverse - Function that prints reversed strings
* @types: Parameter types
* @buffer: Array buffer that handle printing
* @flags: Active flags calculator or estimator
* @width: Parameter get width
* @precision: Parameter that specifies precision
* @size: Parametr for zize specifiers
* Return: Char nums to be printed
*/

int print_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char *s;
int r, count = 0;
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(size);
s = va_arg(types, char *);
if (s == NULL)
{
UNUSED(precision);
s = ")Null(";
}
for (r = 0; s[r]; r++)
;
for (r = r - 1; r >= 0; r--)
{
char a = s[r];
write(1, &a, 1);
count++;
}
return (count);
}


/*** function that print strings at rot13 ***/
/**
* print_rot13string - Function that prints a string at rot13
* @types: Parameter types
* @buffer: Array buffer that handle printing
* @flags: Active flags calculator or estimator
* @width: Paramter for get width
* @precision: Parameter for orecision specifiers
* @size: Parameter for size specifier
* Return: Char nums to beprinted
*/

int print_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char x;
char *s;
unsigned int r, q;
int count = 0;
char in[] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char out[] =
"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
s = va_arg(types, char *);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (s == NULL)
s = "(AHYY)";
for (r = 0; s[r]; r++)
{
for (q = 0; in[q]; q++)
{
if (in[q] == s[q])
{
x = out[q];
write(1, &x, 1);
count++;
break;
}
}
if (!in[q])
{
x = s[r];
write(1, &x, 1);
count++;
}
}
return (count);
}
