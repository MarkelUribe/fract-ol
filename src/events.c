/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:27:40 by muribe-l          #+#    #+#             */
/*   Updated: 2024/04/08 13:23:37 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	key_handler(int keysym, t_fractol *f)
{
	ft_printf("%d\n", keysym);
	if (keysym == XK_Escape)
		exit_free_all(f);
	else if (keysym == XK_plus)
		f->iterations++;
	else if (keysym == XK_minus)
	else if (keysym == XK_Up)
	else if (keysym == XK_Down)
	else if (keysym == XK_Left)
	else if (keysym == XK_Right)
	return (0);
}