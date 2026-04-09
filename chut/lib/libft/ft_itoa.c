/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 18:33:33 by chutterm          #+#    #+#             */
/*   Updated: 2025/09/20 16:37:21 by chutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	numlen(long nbr)
{
	long	len;

	len = 0;
	if (nbr < 0)
	{
		len++;
		nbr = -nbr;
	}
	if (nbr == 0)
		len++;
	while (nbr)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

char	*ft_itoa(int num)
{
	long	len;
	char	*result;
	long	chr;

	chr = num;
	len = numlen(chr);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (chr < 0)
	{
		result[0] = '-';
		chr *= -1;
	}
	else if (chr == 0)
		result[0] = '0';
	while (chr)
	{
		result[--len] = (chr % 10) + '0';
		chr /= 10;
	}
	return (result);
}
