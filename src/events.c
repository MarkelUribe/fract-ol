/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:27:40 by muribe-l          #+#    #+#             */
/*   Updated: 2024/03/22 16:29:36 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	key_handler(int keysym, t_fractol *f)
{
	if (keysym == XK_Escape)
		exit_free_all(f);
	else if (keysym == XK_plus)
		f->iterations++;

	return (0);
}