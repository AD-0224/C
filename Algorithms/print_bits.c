#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	i = 8;
	while (i--)
	{
		if (octet & (1 << i)) // Vérifie si le bit à la position i est à 1.
			write (1, "1", 1);
		else
			write (1, "0", 1);
	}
}
