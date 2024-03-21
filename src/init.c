/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:17:43 by muribe-l          #+#    #+#             */
/*   Updated: 2024/03/21 16:57:10 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	hooks(int key, t_fractol *f)
{
	if (key == 53)
		exit_free_all(f);
}

void	data_init(t_fractol *f)
{
	f->scape_value = 2;
	f->iterations = 42;
}

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
	mlx_hook(f->win, 17, 0, (void *)exit, f);
	mlx_hook(f->win, 2, 0, (void *)hooks, f);
}