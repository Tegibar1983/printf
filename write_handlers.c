#include "main.h"

int handle_write_char(char c, char buffer[],
int flags, int width, int precision, int size)

/*** char is stored at left and paddind at buffer's right ***/

{
int r = 0;
char padd = ' ';
UNUSED(precision);
UNUSED(size);
if (flags & F_ZERO)
padd = '0';
buffer[r++] = c;
buffer[r] = '\0';
if (width > 1)
{
buffer[BUFF_SIZE - 1] = '\0';
for (r = 0; r < width - 1; r++)
buffer[BUFF_SIZE - r - 2] = padd;
if (flags & F_MINUS)
return (write(1, &buffer[0], 1) +
write(1, &buffer[BUFF_SIZE - r - 1], width - 1));
else
return (write(1, &buffer[BUFF_SIZE - r - 1], width - 1) +
write(1, &buffer[0], 1));
}
return (write(1, &buffer[0], 1));
}
int write_number(int is_negative, int ind, char buffer[],
int flags, int width, int precision, int size)
{
int length = BUFF_SIZE - ind - 1;
char padd = ' ', extra_ch = 0;
UNUSED(size);
if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';
if (is_negative)
extra_ch = '-';
else if (flags & F_PLUS)
extra_ch = '+';
else if (flags & F_SPACE)
extra_ch = ' ';
return (write_num(ind, buffer, flags, width, precision,
length, padd, extra_ch));
}

int write_num(int ind, char buffer[],
int flags, int width, int prec,
int length, char padd, char extra_c)
{
int r, padd_start = 1;
if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
return (0);

/*** print(".0d", 0) when nocharactor is to be printed ***/

if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
buffer[ind] = padd = ' ';

/*** Parameter width to be displayed with padding ' ' includeded ***/


if (prec > 0 && prec < length)
padd = ' ';
while (prec > length)
buffer[--ind] = '0', length++;
if (extra_c != 0)
length++;
if (width > length)
{
for (r = 1; r < width - length + 1; r++)
buffer[r] = padd;
buffer[r] = '\0';
if (flags & F_MINUS && padd == ' ')

/*** Additional charachtor assignment to the buffer left side ***/

{
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length) + write(1, &buffer[1], r - 1));
}
else if (!(flags & F_MINUS) && padd == ' ')


/*** Another charachtor assignment to the buffer another side ***/

{
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[1], r - 1) + write(1, &buffer[ind], length));
}
else if (!(flags & F_MINUS) && padd == '0')

/*** charachtor assignment to the buffer left padd ***/

{
if (extra_c)
buffer[--padd_start] = extra_c;
return (write(1, &buffer[padd_start], r - padd_start) +
write(1, &buffer[ind], length - (1 - padd_start)));
}

}
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length));
}

int write_unsgnd(int is_negative, int ind,
char buffer[],
int flags, int width, int precision, int size)

/*** nums being stored at the buffer right and starts at position r ***/

{

int length = BUFF_SIZE - ind - 1, r = 0;
char padd = ' ';
UNUSED(is_negative);
UNUSED(size);
if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
return (0);

/*** printf(".0d", 0) for no charactor to be printed ***/


if (precision > 0 && precision < length)
padd = ' ';
while (precision > length)
{
buffer[--ind] = '0';
length++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';
if (width > length)
{
for (r = 0; r < width - length; r++)
buffer[r] = padd;
buffer[r] = '\0';
if (flags & F_MINUS)

/** Additional charactor assignment to the buffer left ***/

{
return (write(1, &buffer[ind], length) + write(1, &buffer[0], r));
}

else
/** additional charactor assignment to left of padding  ***/
{
return (write(1, &buffer[0], r) + write(1, &buffer[ind], length));
}
}
return (write(1, &buffer[ind], length));
}

int write_pointer(char buffer[], int ind, int length,
int width, int flags, char padd, char extra_c, int padd_start)
{
int r;
if (width > length)
{
for (r = 3; r < width - length + 3; r++)
buffer[r] = padd;
buffer[r] = '\0';
if (flags & F_MINUS && padd == ' ')

/*** Additional charactor assigner the buffer left  ***/

{
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length) + write(1, &buffer[3], r - 3));
}

else if (!(flags & F_MINUS) && padd == ' ')

/*** Additional charactor assigner the buffer left side ***/

{
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[3], r - 3) + write(1, &buffer[ind], length));
}
else if (!(flags & F_MINUS) && padd == '0')
/*** Additional charactor assigner to the left of padd ***/
{
if (extra_c)
buffer[--padd_start] = extra_c;
buffer[1] = '0';
buffer[2] = 'x';
return (write(1, &buffer[padd_start], r - padd_start) +
write(1, &buffer[ind], length - (1 - padd_start) - 2));
}
}
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
