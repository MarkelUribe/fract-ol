/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:28:41 by muribe-l          #+#    #+#             */
/*   Updated: 2024/03/22 16:29:34 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "libft.h"
# include "mlx.h"

# include <math.h>

# define WIN_X 1000
# define WIN_Y 1000

# define BLACK				0x000000 // RGB: (0, 0, 0)
# define WHITE				0xFFFFFF // RGB: (255, 255, 255)
# define RED				0xFF0000 // RGB: (255, 0, 0)
# define GREEN				0x008000 // RGB: (0, 128, 0)
# define BLUE				0x0000FF // RGB: (0, 0, 255)
# define YELLOW				0xFFFF00 // RGB: (255, 255, 0)
# define CYAN				0x00FFFF // RGB: (0, 255, 255)
# define MAGENTA			0xFF00FF // RGB: (255, 0, 255)
# define GRAY				0x808080 // RGB: (128, 128, 128)
# define ELECTRIC_BLUE		0x00FFFF // RGB: (0, 255, 255)
# define NEON_PINK			0xFF00FF // RGB: (255, 0, 255)
# define ACID_GREEN			0x00FF00 // RGB: (0, 255, 0)
# define PSYCHEDELIC_PURPLE	0xA020F0 // RGB: (160, 32, 240)
# define RAINBOW			0xFF0000 // RGB: (255, 0, 0)
# define LAVA_ORANGE		0xFFA500 // RGB: (255, 165, 0)
# define COSMIC_TURQUOISE	0x00FFFF // RGB: (0, 255, 255)
# define SOLAR_FLARE_YELLOW	0xFFFF00 // RGB: (255, 255, 0)
# define MAGENTA_MADNESS	0xFF00FF // RGB: (255, 0, 255)
# define GALACTIC_INDIGO	0x4B0082 // RGB: (75, 0, 130)

# define KeyPress 02
# define ButtonPress 04
# define DestroyNotify 17

# define KeyPressMask (1L<<0)
# define ButtonPressMask (1L<<2)
# define StructureNotifyMask (1L<<17)

# define XK_BackSpace 0xFF08
# define XK_Tab 0xFF09
# define XK_Escape 0xFF1B
# define XK_Left 0xFF51
# define XK_Up 0xFF52
# define XK_Right 0xFF53
# define XK_Down 0xFF54
# define XK_plus 0x002B
# define XK_minus 0x002D

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_img
{
	void 	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	t_img	img;
	char	*name;
	double	scape_value;
	int		iterations;
}	t_fractol;

void	free_all(t_fractol *f);
void	error_free_all(t_fractol *f);
void	exit_free_all(t_fractol *f);
void	fractal_init(t_fractol *f);
void	fractal_render(t_fractol *f);
int		max_str_len(char *s1, char *s2);
double	scale_pixel(double uns_num, double n_min, double n_max, double o_max);
t_point	sum_p(t_point z1, t_point z2);
t_point	square_p(t_point z);
int		key_handler(int keysym, t_fractol *f);
#endif