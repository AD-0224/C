#include <unistd.h>

void    print_hex(int n)
{
    char hex_digit[] = "0123456789abcdef";
    if (n >= 16)
        print_hex (n / 16);
    write(1, &hex_digit[n % 16], 1);
}
int main (int argc, char **argv)
{
    if (argc == 2)
    {
        int n = 0;
        int i = 0;
        while (argv[1][i] != '\0')
        {
            n = n * 10 + (argv[1][i] - '0');
            i++;
        }
        print_hex(n);
    }
    write(1, "\n", 1);
    return (0);
}