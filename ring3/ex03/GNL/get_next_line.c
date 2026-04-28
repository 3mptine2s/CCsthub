/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthubthi <sthubthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:05:09 by sthubthi          #+#    #+#             */
/*   Updated: 2025/11/15 17:24:12 by sthubthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>    // for open()
#include <unistd.h>   // for read(), close()
#include <stdlib.h>   // for malloc(), exit()
#include <stdio.h>    // for perror()
#include "get_next_line.h"

int	readcheck(int readbytes, char *testbuff, char *stash)
{
	if (readbytes < 0)
	{
		free(stash);
		free(testbuff);
		return (0);
	}
	return (1);
}

char	*read_to_nl(int fd, char *stash)
{
	char		*joined;
	char		*testbuff;
	ssize_t		readbytes;

	readbytes = 1;
	testbuff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!testbuff)
		return (free(stash), NULL);
	while ((readbytes > 0) && (!(ft_strchr(stash, '\n'))))
	{
		readbytes = read(fd, testbuff, BUFFER_SIZE);
		if (!(readcheck(readbytes, testbuff, stash)))
			return (NULL);
		testbuff[readbytes] = '\0';
		joined = ft_strjoin_free(stash, testbuff);
		if (!joined)
			return (NULL);
		stash = joined;
	}
	free(testbuff);
	if (stash[0] == '\0')
		return (free(stash), NULL);
	return (stash);
}

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || fd > 999 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
	{
		stash = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	stash = read_to_nl(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = extract_line(stash, '\n');
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = update_stash(stash);
	return (line);
}

// int main()
// {
// 	int 	fd = open("test.txt",O_RDONLY);
// 	int i = 2;
// 	while (i < 100)
// 	{
// 		printf("%s",get_next_line(fd));
// 		i++;
// 	}
// }