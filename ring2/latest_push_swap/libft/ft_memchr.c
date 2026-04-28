/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthubthi <sthubthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:05:39 by sthubthi          #+#    #+#             */
/*   Updated: 2025/09/12 11:49:26 by sthubthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *ptr, int ch, size_t count)
{
	const unsigned char	*s;
	unsigned char		c;
	size_t				i;

	s = (const unsigned char *)ptr;
	c = (unsigned char)ch;
	i = 0;
	while (i < count)
	{
		if (s[i] == c)
			return ((void *)(&s[i]));
		i++;
	}
	return (NULL);
}
