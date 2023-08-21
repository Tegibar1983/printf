#include "main.h"

/**
* is_printable - Examines chars to be printable or not
* @c: Parameter argument to be checked
* Return: one (1) if char is printed, 0 if not printed
*/

int is_printable(char x)
{
if (x >= 32 && x < 127)
return (1);
return (0);
}

/**
* append_hexa_code - Append ASCCI with hexadecimal buffer code
* @buffer: strings or char arrays
* @r: padd start index
* @ascii_code: American standard code for information interchange
* Return: 3 for success
*/

int append_hexa_code(char ascii_code, char buffer[], int r)
{
char map_to[] = "0123456789ABCDEF";

/*** hexadecimal code format long num ***/

if (ascii_code < 0)
ascii_code *= -1;
buffer[r++] = '\\';
buffer[r++] = 'x';
buffer[r++] = map_to[ascii_code / 16];
buffer[r] = map_to[ascii_code % 16];
return (3);
}

/**
* is_digit - Checks charactor if digit or not
* @x: Charactors to be assessed
* Return: (1) if x is digit num, 0 for non digits
*/

int is_digit(char x)
{
if (x >= '0' && x <= '9')
return (1);
return (0);
}

/**
* convert_size_number - Function that casts num size
* @num: Num caster parameter argument
* @size: Cast number indicator
* Return: Value of nums being casted
*/

long int convert_size_number(long int num, int size)
{
if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((short)num);
return ((int)num);
}

/**
* convert_size_unsgnd - Function that casts nums of specified size
* @num: Casted number
* @size: Casted number indicator
* Return: Value of num casted
*/

long int convert_size_unsgnd(unsigned long int num, int size)
{
if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((unsigned short)num);
return ((unsigned int)num);
}
