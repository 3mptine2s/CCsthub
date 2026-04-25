/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthubthi <sthubthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:05:52 by sthubthi          #+#    #+#             */
/*   Updated: 2025/09/12 11:53:46 by sthubthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len;
	int		len2;
	char	*joined;

	i = 0;
	len = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined = (char *)malloc(sizeof(char) * (len + len2 + 1));
	if (!joined)
		return (NULL);
	while (*s1)
	{
		joined[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		joined[i] = *s2;
		s2++;
		i++;
	}
	joined[i] = '\0';
	return (joined);
}

// #include <stdio.h>
// int main()
// {
// 	char *s1 = "Helloasfghasfh, ";
// 	char *s2 = "Woradjajald!";
// 	char *result = ft_strjoin(s1, s2);
// 	if (result)
// 	{
// 		printf("Joined string: %s\n", result); // Expected: "Hello, World!"
// 		free(result);
// 	}
// 	return 0;
// }