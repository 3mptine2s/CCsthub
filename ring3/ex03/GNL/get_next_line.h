/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthubthi <sthubthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:05:14 by sthubthi          #+#    #+#             */
/*   Updated: 2025/11/15 17:30:20 by sthubthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_strcpy(char *s1, char *s2);
char	*extract_line(char *src, char targ);
char	*update_stash(char *stash);
char	*get_next_line(int fd);
char	*ft_strjoin_free(char *s1, char *s2);
int		ft_strlen(char const *str);
char	*ft_strchr(char *s, int c);

#endif
