/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 19:55:45 by chutterm          #+#    #+#             */
/*   Updated: 2025/09/13 20:23:43 by chutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t			index;
	unsigned char	*d_temp;
	unsigned char	*s_temp;

	index = 0;
	d_temp = (unsigned char *)dest;
	s_temp = (unsigned char *)src;
	if (!d_temp && !s_temp)
		return (NULL);
	while (index < len)
	{
		d_temp[index] = s_temp[index];
		index++;
	}
	return (dest);
}
