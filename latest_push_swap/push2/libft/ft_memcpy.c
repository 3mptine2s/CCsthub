/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthubthi <sthubthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:05:42 by sthubthi          #+#    #+#             */
/*   Updated: 2025/09/12 11:49:47 by sthubthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (destination == NULL && source == NULL)
	{
		return (NULL);
	}
	d = (unsigned char *)destination;
	s = (const unsigned char *)source;
	if (d == s || num == 0)
		return (destination);
	i = 0;
	while (i < num)
	{
		d[i] = s[i];
		i++;
	}
	return (destination);
}
