/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthubthi <sthubthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:05:40 by sthubthi          #+#    #+#             */
/*   Updated: 2025/09/12 11:49:39 by sthubthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const unsigned char		*b1;
	const unsigned char		*b2;
	size_t					i;

	b1 = (const unsigned char *)ptr1;
	b2 = (const unsigned char *)ptr2;
	i = 0;
	if (num == 0)
		return (0);
	while (i < num)
	{
		if (b1[i] != b2[i])
			return (b1[i] - b2[i]);
		i++;
	}
	return (0);
}
