/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:27:54 by chutterm          #+#    #+#             */
/*   Updated: 2025/09/14 23:20:21 by chutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *string, int chr, size_t len)
{
	size_t			index;
	unsigned char	*string_temp;
	unsigned char	chr_temp;

	index = 0;
	string_temp = (unsigned char *) string;
	chr_temp = (unsigned char) chr;
	while (index < len)
	{
		if (string_temp[index] == chr_temp)
			return ((void *) &string_temp[index]);
		index++;
	}
	return (NULL);
}
