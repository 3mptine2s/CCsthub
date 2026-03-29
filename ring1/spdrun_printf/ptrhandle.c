/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptrhandle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthubthi <sthubthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 00:07:45 by nsongsit          #+#    #+#             */
/*   Updated: 2025/12/03 19:24:17 by sthubthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * putstr - write string to stdout
 * @str: null-terminated string to print
 *
 * Writes characters from string to stdout until null terminator is reached.
 */
static void	putstr(const char *str)
{
	while (*str)
		write(STDOUT_FILENO, str++, 1);
}

/**
 * puthex - convert number to hexadecimal string
 * @num: number to convert
 * @hex: buffer to store hexadecimal digits
 * @i: pointer to current position in buffer
 *
 * Converts number to hexadecimal representation, storing digits in
 * provided buffer. Updates buffer position through pointer i.
 * Digits are stored in reverse order for later reversal during printing.
 */
static void	puthex(uintptr_t num, char *hex, int *i)
{
	int	digit;

	while (num > 0)
	{
		digit = num % 16;
		if (digit < 10)
			hex[(*i)++] = digit + '0';
		else
			hex[(*i)++] = (digit - 10) + 'a';
		num /= 16;
	}
}

/**
 * fmtptr - format and print pointer value
 * @ptr: pointer to format
 *
 * Formats pointer as hexadecimal with "0x" prefix.
 * Prints "(nil)" for NULL pointers.
 * Uses local buffer to build reversed hex string,
 * then prints in correct order.
 *
 * Return: number of characters printed
 */
int	fmtptr(void *ptr)
{
	uintptr_t	num;
	char		hex[16];
	int			i;
	int			len;

	i = 0;
	num = (uintptr_t)ptr;
	if (ptr == NULL)
	{
		putstr("(nil)");
		return (5);
	}
	putstr("0x");
	puthex(num, hex, &i);
	len = i;
	while (i--)
		write(STDOUT_FILENO, &hex[i], 1);
	return (len + 2);
}
