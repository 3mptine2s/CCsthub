#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int     fmtchecker(char c, va_list args);
int     ft_printf(const char *inp, ...);
void	putptrlow(uintptr_t n);
int     ptrput(uintptr_t ptr);
void	puthexup(unsigned int n);
void	puthexlow(unsigned int n);
int		hexput(unsigned int n, int caps);
int	    numlen(long n);
int	    ft_putnbr(long nb);
int     ptrhandler(void *ptr);
void	ftputc(char c);
int		pctprint();
int		ftstrlen(char *c);
int	    charhandler(char c);
int	    perchandler();
void	putnstr(char *c, int n);
int		strhandler(char *c);
int	    uinthandler(int n);

#endif