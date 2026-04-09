/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 21:41:14 by chutterm          #+#    #+#             */
/*   Updated: 2025/09/14 21:06:58 by chutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int chr)
{
	size_t	index;

	index = 0;
	while (string[index] != '\0')
	{
		if (string[index] == (char) chr)
			return ((char *) &string[index]);
		index++;
	}
	if (string[index] == (char) chr)
		return ((char *) &string[index]);
	return (NULL);
}
