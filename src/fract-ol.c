/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:28:05 by muribe-l          #+#    #+#             */
/*   Updated: 2024/03/20 13:36:11 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void paint(t_fractol *f)
{
	int		i;
	int		j;

	i = 0;
	while (i < WIN_Y)
	{
		j = 0;
		while (j < WIN_X)
		{
			mlx_pixel_put(f->mlx, f->win, j, i, 0xff00ff);
			j++;
		}
		i++;
	}
}
void	init_window(t_fractol *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIN_X, WIN_Y, "fract-ol");
	mlx_hook(f->win, 17, 0, (void *)exit, f->mlx);
	paint(f);
	mlx_loop (f->mlx);
}

void	free_all(t_fractol *f)
{
	mlx_destroy_window(f->mlx, f->win);
	free(f->mlx);
	free(f);
}

int	main()
{
	t_fractol	f;

	init_window(&f);
	free_all(&f);
}
