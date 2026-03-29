/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uinthandle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsongsit <nsongsit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 00:07:33 by nsongsit          #+#    #+#             */
/*   Updated: 2025/11/05 00:07:34 by nsongsit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * fmtuint - format and print unsigned integer passed as int
 * @n: integer value (may be negative when representing unsigned)
 *
 * Interprets the signed int value as an unsigned 32-bit quantity when
 * the value is negative. For non-negative inputs, it delegates to
 * ft_putnbr(n). For negative inputs it computes the equivalent
 * unsigned value by adding 4294967296 (2^32) and prints that using
 * ft_putnbr.
 *
 * Return: number of characters printed
 */
int	fmtuint(int n)
{
	unsigned long	num;

	if (n >= 0)
		return (ft_putnbr(n));
	num = (unsigned long)n + 4294967296;
	return (ft_putnbr(num));
}
