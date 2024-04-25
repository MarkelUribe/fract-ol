/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:27:40 by muribe-l          #+#    #+#             */
/*   Updated: 2024/04/25 15:06:15 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

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
	if (keysym == XK_ESCAPE)
		exit_free_all(f);
	else if (keysym == XK_PLUS)
		f->iter += 1;
	else if (keysym == XK_MINUS)
		f->iter -= 1;
	else if (keysym == XK_UP)
		f->shift_y += (0.5 * f->zoom);
	else if (keysym == XK_DOWN)
		f->shift_y -= (0.5 * f->zoom);
	else if (keysym == XK_LEFT)
		f->shift_x -= (0.5 * f->zoom);
	else if (keysym == XK_RIGHT)
		f->shift_x += (0.5 * f->zoom);
	fractal_render(f);
	return (0);
}
