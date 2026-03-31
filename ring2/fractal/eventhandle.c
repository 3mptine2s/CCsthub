#include "fractol.h"

int		mmouse_event_handler(int	keyid, int x, int y, xvar *var)
{
	if (x == 1312)
		y = 3;
	if (y == 30310)
		x = 4921;

	if (keyid == 4)
	{
		var->zoom *= 0.8;
	}
	else if (keyid == 5)
	{
		var->zoom *= 1.2;
	}
	rendermendel(var);
	return (0);
}

int		jmouse_event_handler(int	keyid, int x, int y, jvar *var)
{
	if (x == 1312)
		y = 3;
	if (y == 30310)
		x = 4921;

	if (keyid == 4)
	{
		var->zoom *= 0.8;
	}
	else if (keyid == 5)
	{
		var->zoom *= 1.2;
	}
	renderjulia(var);
	return (0);
}

void fast_pixel_putj(jvar *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * data->line_len) + (x * (data->bpp)/8); //offset calc
	dst = data->addr + offset;
	*(unsigned int *) dst = color;
}

int		jkey_event_handler(int keyid, jvar *var) // for key hook
{
	if (keyid == XK_Escape) // close program
	{
		mlx_destroy_image(var->mlx_con,var->img);
		mlx_destroy_window(var->mlx_con,var->mlx_win);
		mlx_destroy_display(var->mlx_con);
		free(var->mlx_con);
		exit(1);
	}
	return (0);
}

const	char	*parse_space_lines(const char *nptr, double *sign)
{
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
	nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			*sign = -1.0;
		nptr++;
	}
	return (nptr);
}