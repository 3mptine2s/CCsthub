#include "ft_printf.h"

void	putptrlow(uintptr_t n)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
		putptrlow(n / 16);
	write(1, &hex[n % 16], 1);
}

int ptrput(uintptr_t ptr)
{
	int	len;

	if (ptr == 0)
		return (write(1, "0", 1));
	len = 0;
	putptrlow(ptr);
	while (ptr && ++len)
		ptr /= 16;
	return (len);
}

int ptrhandler(void *ptr)
{
	uintptr_t	cast;
	int			len;

	len = 0;
	cast = (uintptr_t)ptr;
	if (ptr == NULL)
	{
		putnstr("(nil)",5);
		return (5);
	}
	putnstr("0x",2);
	len += 2;
	len += ptrput(cast);
	return (len);
}

