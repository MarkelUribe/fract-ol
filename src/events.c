/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:27:40 by muribe-l          #+#    #+#             */
/*   Updated: 2024/04/09 15:11:55 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	julia_track(int x, int y, t_fractol *f)
{
	if (!ft_strncmp(f->name, "julia", 5))
	{
		f->julia_x = scale_pixel(x, -2, 2, WIN_X) * f->zoom;
		f->julia_y = scale_pixel(y, 2, -2, WIN_Y) * f->zoom;
		fractal_render(f);
	}
	return (0);
}

int	close_handler(t_fractol *f)
{
	exit_free_all(f);
	return (1);
}

int	mouse_handler(int button, int x, int y, t_fractol *f)
{
	if (button == 5)
	{
		f->zoom *= 1.15;
	}
	else if (button == 4)
	{
		f->zoom *= 0.85;
	}
	x = y;
	fractal_render(f);
	return (0);
}

int	key_handler(int keysym, t_fractol *f)
{
	if (keysym == XK_Escape)
		exit_free_all(f);
	else if (keysym == XK_plus)
		f->iterations += 1;
	else if (keysym == XK_minus)
		f->iterations -= 1;
	else if (keysym == XK_Up)
		f->shift_y += (0.5 * f->zoom);
	else if (keysym == XK_Down)
		f->shift_y -= (0.5 * f->zoom);
	else if (keysym == XK_Left)
		f->shift_x -= (0.5 * f->zoom);
	else if (keysym == XK_Right)
		f->shift_x += (0.5 * f->zoom);
	fractal_render(f);
	return (0);
}
