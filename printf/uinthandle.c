#include "ft_printf.h"

int	uinthandler(int n)
{
	unsigned long	num;

	if (n >= 0)
		return (ft_putnbr(n));
	num = (unsigned long)n + 4294967296;
	return (ft_putnbr(num));
}
