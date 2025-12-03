/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dechandle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthubthi <sthubthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 00:08:12 by nsongsit          #+#    #+#             */
/*   Updated: 2025/12/02 12:33:19 by sthubthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * numlen - count digits in a long integer
 * @n: number to count digits of
 *
 * Calculate length of number when printed, including minus sign for negatives.
 *
 * Return: total number of digits that would be printed
 */
int	numlen(long n)
{
	int		len;
	long	num;
	int		neg;

	len = 0;
	num = n;
	neg = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num = -(num);
		neg = 1;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len + neg);
}

/**
 * ft_putnbr - print long integer recursively
 * @nb: number to print
 *
 * Prints number to stdout. Handles negative numbers by printing minus sign
 * and converting to positive. Uses recursion for multi-digit numbers.
 *
 * Return: number of characters printed
 */
int	ft_putnbr(long nb)
{
	long	n;
	char	tmp;

	n = nb;
	if (n < 0)
	{
		n = (-1) * n;
		write(STDOUT_FILENO, "-", 1);
	}
	if (n < 10)
	{
		tmp = n + '0';
		write(STDOUT_FILENO, &tmp, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		tmp = n % 10 + '0';
		write(STDOUT_FILENO, &tmp, 1);
	}
	return (numlen(nb));
}
