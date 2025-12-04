#include "ft_printf.h"

void	ftputc(char c)
{
	write(1, &c, 1);
}

int	pctprint(void)
{
	ftputc('%');
	return (1);
}

int	ftstrlen(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}
