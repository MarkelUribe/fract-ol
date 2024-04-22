/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:57:24 by muribe-l          #+#    #+#             */
/*   Updated: 2024/04/22 13:15:23 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	free_all(t_fractol *f)
{
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	if (f->img.img_ptr)
		mlx_destroy_image(f->mlx, f->img.img_ptr);
	if (f->mlx)
		free(f->mlx);
}

void	exit_free_all(t_fractol *f)
{
	free_all(f);
	exit(EXIT_SUCCESS);
}

void	error_free_all(t_fractol *f)
{
	write(2, "error\n", 6);
	free_all(f);
	exit(EXIT_FAILURE);
}
