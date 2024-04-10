/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:28:05 by muribe-l          #+#    #+#             */
/*   Updated: 2024/04/10 14:38:00 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (argc != 2 && argc != 4)
		return (ft_printf("posible arguments:\n- mandelbrot\n- julia 0 0\n"), 1);
	f.name = argv[1];
	if (argc == 4)
	{
		f.julia_x = ft_atodbl(argv[2]);
		f.julia_y = ft_atodbl(argv[3]);
		if (!ft_strncmp(argv[1], "julia", max_str_len(argv[1], "julia"))
		&& (!is_number(argv[2]) || !is_number(argv[3])))
			return (ft_printf("posible arguments:\n- mandelbrot\n- julia 0 0\n"), 1);
	}
	if (!ft_strncmp(argv[1], "mandelbrot", max_str_len(argv[1], "mandelbrot"))
		|| !ft_strncmp(argv[1], "julia", max_str_len(argv[1], "julia")))
	{
		fractal_init(&f);
		fractal_render(&f);
		mlx_loop(f.mlx);
		exit_free_all(&f);
	}
	else
		ft_printf("posible arguments:\n- mandelbrot\n- julia 0 0\n");
	return (0);
}
