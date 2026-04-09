/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:00:05 by chutterm          #+#    #+#             */
/*   Updated: 2025/09/20 17:08:48 by chutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *string, char (*func)(unsigned int, char))
{
	size_t	index;
	char	*result;

	result = malloc((ft_strlen(string) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	index = 0;
	while (index < ft_strlen(string))
	{
		result[index] = (*func)(index, string[index]);
		index++;
	}
	result[index] = 0;
	return (result);
}
