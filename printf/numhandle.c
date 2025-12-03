#include "ft_printf.h"

void	puthexup(unsigned int n)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	if (n >= 16)
		puthexup(n / 16);
	write(1, &hex[n % 16], 1);
}

void	puthexlow(unsigned int n)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
		puthexlow(n / 16);
	write(1, &hex[n % 16], 1);
}

int		hexput(unsigned int n, int caps)
{
	int	len;

	if (n == 0)
		return (write(1, "0", 1));
	len = 0;
	if (caps)
		puthexup(n);
	else
		puthexlow(n);
	while (n && ++len)
		n /= 16;
	return (len);
}

int	numlen(long n)
{
	int		len;
	long	num;

	len = 0;
	num = n;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num = -(num);
		len++;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}


int	ft_putnbr(long nb)
{
	long	n;
	char	tmp;

	n = nb;
	if (n < 0)
	{
		n = (-1) * n;
		write(1, "-", 1);
	}
	if (n < 10)
	{
		tmp = n + '0';
		write(1, &tmp, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		tmp = n % 10 + '0';
		write(1, &tmp, 1);
	}
	return (numlen(nb));
}
