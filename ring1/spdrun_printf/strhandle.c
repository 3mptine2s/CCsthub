/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhandle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsongsit <nsongsit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 00:07:35 by nsongsit          #+#    #+#             */
/*   Updated: 2025/11/05 00:07:37 by nsongsit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * fmtstr - format and print string from args
 * @args: va_list containing string to print
 *
 * Extracts string from va_list and prints it.
 * Handles NULL pointer by printing "(null)".
 *
 * Return: number of characters printed
 */
int	fmtstr(va_list args)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	if (!str)
	{
		putnstr("(null)", 6);
		return (6);
	}
	len = slen(str);
	putnstr(str, len);
	return (len);
}

/**
 * fmtchar - format and print single character
 * @args: va_list containing character to print
 *
 * Extracts character from va_list and prints it.
 *
 * Return: always 1 (characters printed)
 */
int	fmtchar(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	ft_putchar(c);
	return (1);
}

/**
 * fmtpct - print percent sign
 *
 * Prints a single percent character to stdout.
 *
 * Return: always 1 (characters printed)
 */
int	fmtpct(void)
{
	ft_putchar('%');
	return (1);
}
