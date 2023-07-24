#include <unistd.h>
#include "main.h"

#define BUFF_SIZE 100

/************************* WRITE HANDLE *************************/
int handle_write_char(char c, char buffer[], int flags, int width)
{
    int i = 0;
    char padd = ' ';

    if (flags & F_ZERO)
        padd = '0';

    buffer[i++] = c;
    buffer[i] = '\0';

    if (width > 1)
    {
        buffer[BUFF_SIZE - 1] = '\0';
        for (i = 0; i < width - 1; i++)
            buffer[BUFF_SIZE - i - 2] = padd;

        if (flags & F_MINUS)
            return (write(1, &buffer[0], 1) +
                    write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
        else
            return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
                    write(1, &buffer[0], 1));
    }

    return (write(1, &buffer[0], 1));
}

/************************* WRITE NUMBER *************************/
int write_number(int is_negative, int ind, char buffer[], int flags, int width, int precision)
{
    int length = BUFF_SIZE - ind - 1;
    char padd = ' ', extra_ch = 0;

    if ((flags & F_ZERO) && !(flags & F_MINUS))
        padd = '0';
    if (is_negative)
        extra_ch = '-';
    else if (flags & F_PLUS)
        extra_ch = '+';
    else if (flags & F_SPACE)
        extra_ch = ' ';

    return write_num(ind, buffer, flags, width, precision, length, padd, extra_ch);
}

int write_num(int ind, char buffer[], int flags, int width, int prec, int length, char padd, char extra_c)
{
    // Implementation of the write_num function (as provided in the original code)
    // ...

    return write(1, &buffer[ind], length); // Replace this with the correct return value.
}

/************************* WRITE POINTER *************************/
int write_pointer(char buffer[], int ind, int length, int width, int flags, char padd, char extra_c, int padd_start)
{
    // Implementation of the write_pointer function (as provided in the original code)
    // ...

    return write(1, &buffer[ind], BUFF_SIZE - ind - 1); // Replace this with the correct return value.
}
