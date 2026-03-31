#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx_linux/mlx.h"
# include <X11/keysym.h>
# include <stdlib.h>

# define MAX_WIN_WID 	800
# define MAX_WIN_H		800

typedef struct svar
{
	void	*mlx_con; //free mlx_destroy_display free prio (img, win, dis) or small to big
	void	*mlx_win; //free mlx_destroy_window
	void	*img; //free mlx_destroy_image
	char	*addr;
	int	 	bpp; //bit per pix
	int	 	line_len; //bytes per one horizontal line
	int	 	endian; // how the cpu read (no need to bother)
	double	zoom;
} xvar;

typedef struct dvar
{
	void	*mlx_con; //free mlx_destroy_display free prio (img, win, dis) or small to big
	void	*mlx_win; //free mlx_destroy_window
	void	*img; //free mlx_destroy_image
	char	*addr;
	int	 	bpp; //bit per pix
	int	 	line_len; //bytes per one horizontal line
	int	 	endian; // how the cpu read (no need to bother)
	double	zoom;
	double	real;
	double	imag;
} jvar;

typedef	struct scomplex
{
	double	real;
	double	imag;
}	tcomplex;

double			xtocoord(int pix, int screensize, double math_min, double math_max);
tcomplex		complex_square(tcomplex z);//z squared
int				stresstestmendel(tcomplex C);		
int				ft_strncmp(const char *s1, const char *s2);
int 			createmendel(); // for mendel
int				mmouse_event_handler(int keyid, int x, int y, xvar *var);
int				key_event_handler(int keyid, xvar *var); // for key hook
int 			createjulia(double num1, double num2); // for julia
void			fast_pixel_put(xvar *data, int x, int y, int color);
double			ft_atoi(const char *nptr);
int				jmouse_event_handler(int	keyid, int x, int y, jvar *var);
void 			fast_pixel_putj(jvar *data, int x, int y, int color);
void			renderjulia(jvar *mlx);
void			rendermendel(xvar *mlx);
int				jkey_event_handler(int keyid, jvar *var); // for key hook
int				ft_printf(const char *inp, ...);
const	char	*parse_space_lines(const char *nptr, double *sign);
#endif