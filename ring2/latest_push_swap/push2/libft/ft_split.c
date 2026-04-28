/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthubthi <sthubthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:05:48 by sthubthi          #+#    #+#             */
/*   Updated: 2025/09/12 16:55:55 by sthubthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *str, char c_sep)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	if (str == NULL)
		return (0);
	if (c_sep == '\0')
		return (1);
	if (str[i] != c_sep)
	{
		cnt++;
		i++;
	}
	while (str[i] != '\0' && str[i] == c_sep)
		i++;
	while (str[i] != '\0')
	{
		if (str[i] != c_sep && str[i - 1] == c_sep)
			cnt++;
		i++;
	}
	return (cnt);
}

static char	*ft_spliter(const char *str, char c_sep, int start_idx)
{
	int		i;
	int		size;
	char	*word;

	i = start_idx;
	size = 0;
	while (str[i] != '\0' && str[i] != c_sep)
	{
		i++;
		size++;
	}
	word = malloc(sizeof(char) * (size + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		word[i] = str[start_idx + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static	char	**ft_empty_arr(void)
{
	char	**arr;

	arr = malloc(sizeof(char *));
	arr[0] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		size;
	char	**arr;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) == 0)
		return (ft_empty_arr());
	size = ft_count_words(s, c);
	arr = malloc(sizeof(char *) * (size + 1));
	if (arr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size)
	{
		while (s[j] != '\0' && s[j] == c)
			j++;
		arr[i] = ft_spliter(s, c, j);
		j += ft_strlen(arr[i]);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

// #include <stdlib.h>

// static	int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// static	int	is_sep(char c, char *charset)
// {
// 	int	i;

// 	i = 0;
// 	while (charset[i] != '\0')
// 	{
// 		if (c == charset[i])
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// static	char	*dup_strft(char *src, int start, int end)
// {
// 	char	*res;
// 	int		i;

// 	res = malloc(sizeof(char) * (end - start + 2));
// 	if (!res)
// 		return (NULL);
// 	i = 0;
// 	while (i < end - start)
// 	{
// 		res[i] = src[start + i];
// 		i++;
// 	}
// 	res[i] = '\0';
// 	return (res);
// }

// static	char	**ft_empty_arr(void)
// {
// 	char	**arr;

// 	arr = malloc(sizeof(char *));
// 	arr[0] = NULL;
// 	return (arr);
// }

// char	**ft_split(char *str, char *charset)
// {
// 	char	**res;
// 	int		start;
// 	int		i_tab;
// 	int		i;

// 	i = 0;
// 	start = 0;
// 	i_tab = 0;
// 	if (ft_strlen(str) == 0)
// 		return (ft_empty_arr());
// 	res = malloc(sizeof(char *) * (ft_strlen(str) + 1));
// 	if (!res)
// 		return (NULL);
// 	while (str[i])
// 	{
// 		while (str[i] && is_sep(str[i], charset))
// 			i++;
// 		start = i;
// 		while (str[i] && !is_sep(str[i], charset))
// 			i++;
// 		if (start < i)
// 			res[i_tab++] = dup_strft(str, start, i);
// 	}
// 	res[i_tab] = NULL;
// 	return (res);
// }

// #include <stdio.h>
// int main()
// {
// 	char **result;
// 	int i;

// 	result = ft_split("Hello,,World! This is a test.", ", !.");
// 	i = 0;
// 	while (result[i])
// 	{
// 		printf("Substring %d: '%s'\n", i, result[i]);
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);
// 	return 0;
// }