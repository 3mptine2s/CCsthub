/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 20:03:43 by chutterm          #+#    #+#             */
/*   Updated: 2025/09/14 20:49:56 by chutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	size_t			index;
	unsigned char	*s1_temp;
	unsigned char	*s2_temp;

	index = 0;
	s1_temp = (unsigned char *) s1;
	s2_temp = (unsigned char *) s2;
	while (index < len)
	{
		if (s1_temp[index] != s2_temp[index])
			return (s1_temp[index] - s2_temp[index]);
		index++;
	}
	return (0);
}
