/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:17:43 by muribe-l          #+#    #+#             */
/*   Updated: 2024/04/25 15:08:25 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	data_init(t_fractol *f)
{
	f->scape_value = SCAPE_VALUE;
	f->iter = ITERATIONS;
	f->shift_x = 0.0;
	f->shift_y = 0.0;
	f->zoom = 1.0;
}

static void	events_init(t_fractol *f)
{
	mlx_hook(f->win, KEYPRESS, (1L << 0), key_handler, f);
	mlx_hook(f->win, BUTTONPRESS, (1L << 2), mouse_handler, f);
	mlx_hook(f->win, DESTROYNOTIFY, (1L << 17), close_handler, f);
}
	/* mlx_hook(f->win, MOTIONNOTIFY, (1L<<6), julia_track, f); */

void	fractal_init(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		error_free_all(f);
	f->win = mlx_new_window(f->mlx, WIN_X, WIN_Y, f->name);
	if (!f->win)
		error_free_all(f);
	f->img.img_ptr = mlx_new_image(f->mlx, WIN_X, WIN_Y);
	if (!f->img.img_ptr)
		error_free_all(f);
	f->img.pixels_ptr = mlx_get_data_addr(f->img.img_ptr, &f->img.bpp,
			&f->img.line_len, &f->img.endian);
	data_init(f);
	events_init(f);
}
