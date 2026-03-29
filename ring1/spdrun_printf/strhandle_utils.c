/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhandle_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsongsit <nsongsit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 00:07:41 by nsongsit          #+#    #+#             */
/*   Updated: 2025/11/05 00:07:42 by nsongsit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * slen - compute string length
 * @str: string to measure
 *
 * Counts characters in string until null terminator.
 *
 * Return: number of characters in string
 */
int	slen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/**
 * putnstr - print limited string
 * @str: string to print
 * @n: maximum characters to print
 *
 * Prints up to n characters from string to stdout.
 * Stops at null terminator if reached before n.
 */
void	putnstr(const char *str, int n)
{
	while (*str && n--)
		write(STDOUT_FILENO, str++, 1);
}

/*
** Writes a single character to stdout.
** @param c: The character to write
*/
void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}
