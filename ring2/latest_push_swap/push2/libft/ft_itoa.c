/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthubthi <sthubthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:05:39 by sthubthi          #+#    #+#             */
/*   Updated: 2025/09/12 12:10:07 by sthubthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static	int	getlength(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static	void	numiter(char *num, int n, int pos)
{
	num[pos] = '\0';
	pos--;
	while (pos >= 0)
	{
		num[pos] = n % 10 + '0';
		n /= 10;
		pos--;
	}
}

static void	intmin(char *numarr)
{
	numarr[0] = '-';
	numarr[1] = '2';
	numarr[2] = '1';
	numarr[3] = '4';
	numarr[4] = '7';
	numarr[5] = '4';
	numarr[6] = '8';
	numarr[7] = '3';
	numarr[8] = '6';
	numarr[9] = '4';
	numarr[10] = '8';
	numarr[11] = '\0';
}

char	*ft_itoa(int n)
{
	int		len;
	char	*num;

	len = getlength(n);
	num = malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	if (n == -2147483648)
	{
		intmin(num);
		return (num);
	}
	if (n < 0)
	{
		num[0] = '-';
		numiter(num + 1, -n, len - 1);
	}
	else
		numiter(num, n, len);
	num[len] = '\0';
	return (num);
}

// int	main(void)
// {
// 	char	*num;

// 	num = (char *)ft_itoa(-2147483648);
// 	printf("%s\n", num);
// 	free(num);
// 	return (0);
// }
