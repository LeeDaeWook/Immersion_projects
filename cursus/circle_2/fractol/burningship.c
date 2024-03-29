/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:37:47 by daewoole          #+#    #+#             */
/*   Updated: 2023/02/14 10:06:10 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	complex_squaring_b(t_set *set)
{
	set->x = 0;
	set->y = 0;
	set->k = 0;
	while (set->k <= ITERATION)
	{
		set->tmp = set->x;
		set->x = set->x * set->x - set->y * set->y + set->complex_a;
		set->y = fabs(2 * set->tmp * set->y) - set->complex_b;
		if (set->x * set->x + set->y * set->y > 4)
			break ;
		set->k++;
	}
	return (set->k);
}

void	burningship(t_vars *vars)
{
	vars->set->i = 0;
	while (vars->set->i <= vars->img_height)
	{
		vars->set->complex_b = vars->max_height - (vars->set->i * \
				(vars->max_height - vars->min_height) / vars->img_height);
		vars->set->j = 0;
		while (vars->set->j <= vars->img_width)
		{
			vars->set->complex_a = vars->min_width + (vars->set->j * \
					(vars->max_width - vars->min_width) / vars->img_width);
			vars->set->k = complex_squaring_b(vars->set);
			if (vars->set->k == ITERATION + 1)
				mlx_pixel_put_on_image(vars->img, vars->set->j, \
						vars->set->i, BLACK);
			else
				mlx_pixel_put_on_image(vars->img, vars->set->j, \
						vars->set->i, create_rgb(vars));
			(vars->set->j)++;
		}
		(vars->set->i)++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}
