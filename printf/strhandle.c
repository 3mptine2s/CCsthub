#include "ft_printf.h"

int	charhandler(char c)
{
	ftputc(c);
	return (1);
}

int	perchandler()
{
	ftputc('%');
	return (1);
}

void	putnstr(char *c, int n)
{
	while (*c && n--)
		write(1,c++,1);
}

int		strhandler(char *c)
{
	int len;

	len = 0;
	if (!c)
	{
		putnstr("(null)",6);
		return (6);
	}
	len = ftstrlen(c);
	putnstr(c,len);
	return (len);
}