/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:29:29 by muribe-l          #+#    #+#             */
/*   Updated: 2024/03/21 16:47:21 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	max_str_len(char *s1, char *s2)
{
	int	s1l;
	int	s2l;

	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2);
	if (s1l > s2l)
		return (s1l);
	else
		return (s2l);
}
double	scale_pixel(double uns_num, double n_min, double n_max, double o_max)
{
	return ((n_max - n_min) * (uns_num - 0) / (o_max - 0) + n_min);
}

t_point	sum_p(t_point z1, t_point z2)
{
	t_point	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_point	square_p(t_point z)
{
	t_point	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}
