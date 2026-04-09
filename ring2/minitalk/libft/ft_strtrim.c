/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthubthi <sthubthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:06:00 by sthubthi          #+#    #+#             */
/*   Updated: 2025/09/12 12:01:46 by sthubthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static	int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	char	*trimmed;
	int		start;
	int		end;
	int		i;

	i = 0;
	start = 0;
	end = ft_strlen((char *)s) - 1;
	if (s == NULL || set == NULL)
		return (NULL);
	while (s[start] && is_sep(s[start], (char *)set))
		start++;
	while (end > start && is_sep(s[end], (char *)set))
		end--;
	trimmed = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!trimmed)
		return (NULL);
	while (start <= end)
		trimmed[i++] = s[start++];
	trimmed[i] = '\0';
	return (trimmed);
}

// #include <stdio.h>
// int main()
// {
// 	char *s = "  Hello, World!  ";
// 	char *set = " H!";
// 	char *result = ft_strtrim(s, set);
// 	if (result)
// 	{
// 		printf("Trimmed string: '%s'\n", result); // Expected: "Hello, World!"
// 		free(result);
// 	}
// 	return 0;
// }