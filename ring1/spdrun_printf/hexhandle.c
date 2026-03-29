/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexhandle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsongsit <nsongsit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 00:07:50 by nsongsit          #+#    #+#             */
/*   Updated: 2025/11/05 00:07:51 by nsongsit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * puthexlow - print unsigned int as lowercase hex
 * @n: number to convert and print
 *
 * Recursively prints number in hexadecimal format using
 * lowercase letters (a-f). Prints most significant digit first
 * by using recursion to reverse order.
 */
static void	puthexlow(unsigned int n)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
		puthexlow(n / 16);
	write(STDOUT_FILENO, &hex[n % 16], 1);
}

/**
 * puthexup - print unsigned int as uppercase hex
 * @n: number to convert and print
 *
 * Recursively prints number in hexadecimal format using
 * uppercase letters (A-F). Prints most significant digit first
 * by using recursion to reverse order.
 */
static void	puthexup(unsigned int n)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	if (n >= 16)
		puthexup(n / 16);
	write(STDOUT_FILENO, &hex[n % 16], 1);
}

/**
 * fmthex - format and print unsigned int as hex
 * @n: number to convert and print
 * @caps: flag for uppercase (1) or lowercase (0)
 *
 * Converts unsigned int to hexadecimal and prints it.
 * Handles special case of 0. Uses recursive helpers
 * puthexup or puthexlow based on caps flag.
 *
 * Return: number of characters printed
 */
int	fmthex(unsigned int n, int caps)
{
	int	len;

	if (n == 0)
		return (write(STDOUT_FILENO, "0", 1));
	len = 0;
	if (caps)
		puthexup(n);
	else
		puthexlow(n);
	while (n && ++len)
		n /= 16;
	return (len);
}
