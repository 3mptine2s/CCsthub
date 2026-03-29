/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:11:57 by naratass          #+#    #+#             */
/*   Updated: 2025/10/30 13:12:21 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# if defined (__linux__)
#  define PTRNULL "(nil)"
# elif defined (__APPLE__)
#  define PTRNULL "0x0"
# endif

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
int		ft_toupper(int c);
int		ft_fputchar(char c);
int		ft_fputstr(char *str);
int		ft_fputaddr(void *ptr);
int		ft_fputnbr_deci(long n);
int		ft_fputnbr_hex(unsigned int n, char format);
int		ft_funsignednbr(int n);

void	ft_fprint_nbr(char *buf, int cnt, char format);

#endif
