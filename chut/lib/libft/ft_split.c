/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 01:30:23 by chutterm          #+#    #+#             */
/*   Updated: 2025/09/20 16:25:11 by chutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_all(char **arr, int index)
{
	while (index-- > 0)
		free(arr[index]);
	free(arr);
	return (NULL);
}

static int	count_word(const char *string, char chr)
{
	size_t	count;
	int		word;

	count = 0;
	word = 0;
	while (*string)
	{
		if (*string != chr && word == 0)
		{
			word = 1;
			count++;
		}
		else if (*string == chr)
			word = 0;
		string++;
	}
	return (count);
}

char	**ft_split(const char *string, char chr)
{
	char		**result;
	size_t		index;
	size_t		len;

	result = malloc(sizeof(char *) * (count_word(string, chr) + 1));
	if (!string)
		return (NULL);
	index = 0;
	while (*string)
	{
		while (*string && *string == chr)
			string++;
		len = 0;
		while (string[len] && string[len] != chr)
			len++;
		if (len > 0)
		{
			result[index] = ft_substr(string, 0, len);
			if (!result[index++])
				return (free_all(result, index));
		}
		string += len;
	}
	result[index] = NULL;
	return (result);
}
