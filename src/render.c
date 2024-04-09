/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:19:14 by muribe-l          #+#    #+#             */
/*   Updated: 2024/04/09 13:01:06 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

static void	mandel_julia(t_point *z, t_point *c, t_fractol *f)
{
	if (!ft_strncmp(f->name, "julia", 5))
	{
		c->x = f->julia_x;
		c->y = f->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

void	handle_pixel(int x, int y, t_fractol *f)
{
	t_point	z;
	t_point	c;
	int		i;
	int		color;

	z.x = (scale_pixel(x, -2, 2, WIN_X) * f->zoom) + f->shift_x;
	z.y = (scale_pixel(y, 2, -2, WIN_Y) * f->zoom) + f->shift_y;
	mandel_julia(&z, &c, f);
	i = 0;
	while (i < f->iterations)
	{
		z = sum_p(square_p(z), c);
		if ((z.x * z.x) + (z.y * z.y) > f->scape_value)
		{
			color = scale_pixel(i, BLACK, WHITE, f->iterations);
			pixel_put(x, y, &f->img, color);
			return ;
		}
		i++;
	}
	pixel_put(x, y, &f->img, WHITE);
}

void	fractal_render(t_fractol *f)
{
	int	x;
	int	y;

	y = -1;
	while (y++ < WIN_Y - 1)
	{
		x = -1;
		while (x++ < WIN_X - 1)
			handle_pixel(x, y, f);
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img_ptr, 0, 0);
}
