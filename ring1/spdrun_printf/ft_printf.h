/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsongsit <nsongsit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 00:07:56 by nsongsit          #+#    #+#             */
/*   Updated: 2025/11/05 00:07:57 by nsongsit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

/* Main format functions */
int		ft_printf(const char *inp, ...);
int		fmtchar(va_list args);
int		fmtstr(va_list args);
int		fmtpct(void);
int		fmtptr(void *ptr);
int		ft_putnbr(long nb);
int		fmtuint(int n);
int		fmthex(unsigned int n, int caps);

/* String utilities */
int		slen(const char *str);
void	putnstr(const char *str, int n);
void	ft_putchar(char c);
int		numlen(long n);
#endif
