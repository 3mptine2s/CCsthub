#include "mlx_linux/mlx.h"
#include <X11/keysym.h>
#include <math.h>
#include <stdlib.h>

typedef struct svar
{
	void	*mlx_con; //free mlx_destroy_display free prio (img, win, dis) or small to big
	void	*mlx_win; //free mlx_destroy_window
	void	*img; //free mlx_destroy_image
	char	*addr;
	int	 	bpp; //bit per pix
	int	 	line_len; //bytes per one horizontal line
	int	 	endian; // how the cpu read (no need to bother)
} xvar;

int event_handler(int keyid, xvar *var) // for key hook
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

int main(int argc, char *argv[])
{
    
}