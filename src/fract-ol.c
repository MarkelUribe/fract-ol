/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:28:05 by muribe-l          #+#    #+#             */
/*   Updated: 2024/03/21 16:29:45 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (argc != 2)
	{
		ft_printf(
			"insert only one posible arguments:\n- mandelbrot\n- julia\n");
		exit(1);
	}
	f.name = argv[1];
	if (!ft_strncmp(argv[1], "mandelbrot", max_str_len(argv[1], "mandelbrot")))
	{
		fractal_init(&f);
		fractal_render(&f);
		mlx_loop(f.mlx);
		exit_free_all(&f);
	}
	else if (!ft_strncmp(argv[1], "julia", max_str_len(argv[1], "julia")))
	{
		fractal_init(&f);
		fractal_render(&f);
		mlx_loop(f.mlx);
		exit_free_all(&f);
	}
	else
		ft_printf("posible arguments:\n- mandelbrot\n- julia\n");
	return (0);
}
