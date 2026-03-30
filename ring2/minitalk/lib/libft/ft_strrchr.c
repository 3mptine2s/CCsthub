/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 22:26:53 by chutterm          #+#    #+#             */
/*   Updated: 2025/09/13 22:28:58 by chutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int chr)
{
	size_t	index;
	char	*result;

	index = 0;
	result = NULL;
	while (string[index] != '\0')
	{
		if (string[index] == (char) chr)
			result = ((char *) &string[index]);
		index++;
	}
	if (string[index] == (char) chr)
		result = ((char *) &string[index]);
	return (result);
}
