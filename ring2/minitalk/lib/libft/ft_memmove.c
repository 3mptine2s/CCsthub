/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 20:08:33 by chutterm          #+#    #+#             */
/*   Updated: 2025/09/13 20:28:44 by chutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*d_temp;
	unsigned char	*s_temp;

	d_temp = (unsigned char *)dest;
	s_temp = (unsigned char *)src;
	if (d_temp > s_temp)
	{
		while (len-- > 0)
			d_temp[len] = s_temp[len];
	}
	else
		ft_memcpy(dest, src, len);
	return (dest);
}
