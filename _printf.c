#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - A printf function that print formated string
 * @format: formated string
 * Return: Printed char arrays or strings
 */

int _printf(const char *format, ...)
{
int r, printed = 0, printed_chars = 0;
int flags, width, precision, size, buff_ind = 0;
va_list list;
char buffer[BUFF_SIZE];

if (format == NULL)
return (-1);

va_start(list, format);

for (r = 0; format && format[r] != '\0'; r++)
{
if (format[r] != '%')
{
buffer[buff_ind++] = format[r];
if (buff_ind == BUFF_SIZE)
print_buffer(buffer, &buff_ind);


/*** write(1, &format[r], 1); ***/

printed_chars++;
}
else
{
print_buffer(buffer, &buff_ind);
flags = get_flags(format, &r);
width = get_width(format, &r, list);
precision = get_precision(format, &r, list);
size = get_size(format, &r);
++r;
printed = handle_print(format, &r, list, buffer,
flags, width, precision, size);
if (printed == -1)
return (-1);
printed_chars += printed;
}
}

print_buffer(buffer, &buff_ind);

va_end(list);

return (printed_chars);
}

/**
 * print_buffer - Print buffered contents
 * @buffer: Charactor arrays
 * @buff_ind: Buffer Index to represent char length
 */

void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &buffer[0], *buff_ind);

*buff_ind = 0;
}
