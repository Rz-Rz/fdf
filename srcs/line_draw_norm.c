/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw_norm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 19:21:55 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/26 19:25:28 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	pt_map(t_pt *pt, t_point *map, int i)
{
	pt->x = map->iso_x[i];
	pt->y = map->iso_y[i];
	pt->z = map->y[i];
	if (map->is_vanilla)
		pt->color = vanilla_vert_color(map, pt);
	else
		pt->color = map->color[i];
}

void	pm_clip(t_line *line, t_point *map, t_data *img, int i)
{
	pt_map(line->p2, map, i);
	lineclip(line, img);
}

void	pt_pt(t_pt *pt1, t_pt *pt2)
{
	pt1->x = pt2->x;
	pt1->y = pt2->y;
	pt1->z = pt2->z;
	pt1->color = pt2->color;
}
