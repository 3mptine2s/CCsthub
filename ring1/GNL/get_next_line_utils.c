/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthubthi <sthubthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:05:12 by sthubthi          #+#    #+#             */
/*   Updated: 2025/11/15 17:28:58 by sthubthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *src, char targ)
{
	int		j;
	int		i;
	char	*line;

	i = 0;
	j = 0;
	while ((src[i]) && (src[i] != targ))
		i++;
	if (src[i] == targ)
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = src[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*update_stash(char *stash)
{
	int		i;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	i++;
	new_stash = malloc(ft_strlen(stash + i) + 1);
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	ft_strcpy(&stash[i], new_stash);
	free(stash);
	return (new_stash);
}

void	ft_strcpy(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		s2[j] = s1[i];
		i++;
		j++;
	}
	s2[j] = '\0';
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*joined;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	joined = malloc(len + 1);
	if (!joined)
	{
		free(s2);
		return (free(s1), NULL);
	}
	while (s1 && s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		joined[i++] = s2[j++];
	joined[i] = '\0';
	free(s1);
	return (joined);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
