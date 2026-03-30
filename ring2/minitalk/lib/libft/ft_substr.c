/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:01:22 by chutterm          #+#    #+#             */
/*   Updated: 2025/09/16 17:55:36 by chutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *string, unsigned int start, size_t len)
{
	size_t	index;
	char	*result;

	if (!string)
		return (NULL);
	if (start >= ft_strlen(string))
		len = 0;
	else if (len > ft_strlen(string) - start)
		len = ft_strlen(string) - start;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	index = 0;
	while (index < len)
	{
		result[index] = string[start + index];
		index++;
	}
	result[index] = '\0';
	return (result);
}
