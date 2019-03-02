/*
 *	Print the string
 *	given on the
 *	standard output
*/

#include "print.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return 0;
}

int	ft_putstr(char *str)
{
	int i;

	i = 0;
	while(*(str + i) != '\0')
	{
		ft_putchar(*(str + i));
		i += 1;
	}
	return 0;
}
