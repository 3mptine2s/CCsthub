/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsongsit <nsongsit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 00:08:01 by nsongsit          #+#    #+#             */
/*   Updated: 2025/11/05 00:08:03 by nsongsit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * fmtcheck - process printf format specifier
 * @a: format character to process
 * @args: va_list of arguments to format
 *
 * Processes single format specifier and prints corresponding argument.
 * Supported formats:
 * %c - character
 * %s - string
 * %p - pointer
 * %d/%i - decimal integer
 * %u - unsigned integer
 * %x - lowercase hexadecimal
 * %X - uppercase hexadecimal
 * %% - percent sign
 * For invalid format chars, prints %<char>.
 *
 * Return: number of characters printed
 */
int	fmtcheck(char a, va_list args)
{
	if (a == 'c')
		return (fmtchar(args));
	else if (a == 's')
		return (fmtstr(args));
	else if (a == 'p')
		return (fmtptr(va_arg(args, void *)));
	else if (a == 'd' || a == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (a == 'u')
		return (fmtuint(va_arg(args, int)));
	else if (a == 'x')
		return (fmthex(va_arg(args, int), 0));
	else if (a == 'X')
		return (fmthex(va_arg(args, int), 1));
	else if (a == '%')
		return (fmtpct());
	else
	{
		write(STDOUT_FILENO, "%", 1);
		write(STDOUT_FILENO, &a, 1);
		return (2);
	}
}

/**
 * ft_printf - formatted output to stdout
 * @inp: format string
 * @...: variable arguments to format
 *
 * Implements subset of printf functionality. Processes format string,
 * replacing format specifiers with formatted arguments. Supported
 * format specifiers are documented in fmtcheck function.
 * Returns -1 on NULL input string.
 *
 * Return: total number of characters printed, or -1 on error
 */
int	ft_printf(const char *inp, ...)
{
	va_list	args;
	int		count;

	if (!inp)
		return (-1);
	va_start(args, inp);
	count = 0;
	while (*inp)
	{
		while (*inp)
		{
			if (*inp == '%')
				count += fmtcheck(*++inp, args);
			else
			{
				write(STDOUT_FILENO, inp, 1);
				count ++;
			}
			inp++;
		}
	}
	return (count);
}
