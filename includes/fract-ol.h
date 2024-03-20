/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:28:41 by muribe-l          #+#    #+#             */
/*   Updated: 2024/03/20 13:12:54 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "libft.h"
# include "mlx.h"

# define WIN_X 1280
# define WIN_Y 720

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
}	t_fractol;

#endif