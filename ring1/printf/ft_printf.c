/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthubthi <sthubthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:06:39 by sthubthi          #+#    #+#             */
/*   Updated: 2025/12/03 19:25:44 by sthubthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fmtchecker(char c, va_list args)
{
	if (c == 'c')
		return (charhandler(va_arg(args, unsigned int)));
	else if (c == 's')
		return (strhandler(va_arg(args, char *)));
	else if (c == 'p')
		return (ptrhandler(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (uinthandler(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (hexput(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return (hexput(va_arg(args, unsigned int), 1));
	else if (c == '%')
		return (pctprint());
	else
	{
		write(1, "%", 1);
		write(1, &c, 1);
		return (2);
	}
}

int	ft_printf(const char *inp, ...)
{
	int		count;
	va_list	hello;

	if (!inp)
		return (-1);
	count = 0;
	va_start(hello, inp);
	while (*inp)
	{
		if (*inp == '%')
			count += fmtchecker(*++inp, hello);
		else
		{
			write(1, inp, 1);
			count++;
		}
		inp++;
	}
	va_end(hello);
	return (count);
}
