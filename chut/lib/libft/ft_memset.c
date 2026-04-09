/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 18:51:32 by chutterm          #+#    #+#             */
/*   Updated: 2025/09/13 21:31:19 by chutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *string, int chr, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)string;
	while (len > 0)
	{
		*ptr = (unsigned char)chr;
		ptr++;
		len--;
	}
	return (string);
}
