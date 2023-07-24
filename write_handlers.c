#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

// Define BUFF_SIZE and other flags and constants here

// Function prototype for the custom printf function
int my_printf(const char *format, ...);

// Helper function to print a single character
int print_char(char c)
{
    return write(1, &c, 1);
}

// Helper function to print a string
int print_string(const char *str, int precision)
{
    int printed_chars = 0;
    for (int i = 0; str[i] && (i < precision || precision == -1); i++)
    {
        printed_chars += print_char(str[i]);
    }
    return printed_chars;
}

// Helper function to print an integer with padding and precision
int print_integer(int num, int width, int precision, char padding, int flags)
{
    // Implementation to print an integer with specified width and precision
    // including leading zeros or space padding based on flags
    // and limiting the number of digits based on precision
    // ...
    // Your implementation here
}

// Helper function to print an unsigned integer with padding and precision
int print_unsigned(unsigned int num, int width, int precision, char padding, int flags)
{
    // Implementation to print an unsigned integer with specified width and precision
    // including leading zeros or space padding based on flags
    // and limiting the number of digits based on precision
    // ...
    // Your implementation here
}

// Main custom printf function
int my_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int printed_chars = 0;
    char ch;
    int width, precision;
    char padding;
    int flags;

    while (*format)
    {
        if (*format == '%')
        {
            format++; // Skip the '%'

            // Reset modifiers
            width = 0;
            precision = -1;
            padding = ' ';
            flags = 0;

            // Parse flags, width, and precision
            while (*format)
            {
                ch = *format;
                if (ch == '0' && width == 0 && precision == -1)
                {
                    padding = '0'; // Zero padding
                }
                else if (ch == '-')
                {
                    flags |= F_MINUS; // Left-justify
                    padding = ' ';    // Override zero padding
                }
                else if (ch == ' ')
                {
                    flags |= F_SPACE; // Add space prefix for positive numbers
                }
                else if (ch == '+')
                {
                    flags |= F_PLUS; // Add plus sign for positive numbers
                }
                else if (isdigit(ch))
                {
                    if (precision == -1)
                        width = width * 10 + (ch - '0');
                    else
                        precision = precision * 10 + (ch - '0');
                }
                else if (ch == '.')
                {
                    precision = 0;
                }
                else
                {
                    break;
                }
                format++;
            }

            // Process the conversion specifier
            if (*format)
            {
                ch = *format;
                if (ch == 'c')
                {
                    // Handle character
                    char c = va_arg(args, int);
                    printed_chars += print_char(c);
                }
                else if (ch == 's')
                {
                    // Handle string
                    const char *str = va_arg(args, const char *);
                    printed_chars += print_string(str, precision);
                }
                else if (ch == 'd' || ch == 'i')
                {
                    // Handle signed integer
                    int num = va_arg(args, int);
                    printed_chars += print_integer(num, width, precision, padding, flags);
                }
                else if (ch == 'u' || ch == 'o' || ch == 'x' || ch == 'X')
                {
                    // Handle unsigned integer
                    unsigned int num = va_arg(args, unsigned int);
                    printed_chars += print_unsigned(num, width, precision, padding, flags);
                }
                // Add other conversion specifiers as needed (e.g., 'f', 'e', 'g', etc.)
                else
                {
                    // Unknown conversion specifier, just print it as is
                    printed_chars += print_char(ch);
                }
            }
        }
        else
        {
            // Regular character, just print it
            printed_chars += print_char(*format);
        }
        format++;
    }

    va_end(args);
    return printed_chars;
}

// Example usage
int main()
{
    my_printf("Hello, %s! The number is %d and the float is %.2f\n", "John", 42, 3.14159);
    return 0;
}
