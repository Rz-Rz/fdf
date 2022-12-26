/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:49:16 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/26 18:49:23 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	vanilla_vert_color(t_point *map, t_pt *pt)
{
	int		color;
	double	divisor;
	double	dec_pcnt;

	divisor = map->max_h - map->min_h;
	if (divisor != 0)
		dec_pcnt = (pt->z - map->min_h) / divisor;
	else
		dec_pcnt = 0.0;
	color = color_lint(C_MIN, C_MAX, dec_pcnt);
	return (color);
}
