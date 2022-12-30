/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:14:21 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/30 17:52:18 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// Name : draw_line
// Description : draw a line between two points
// It will use my breisenham function,
// but it will also draw the line in the iso projection
// Parameters : t_point *line (the chained list that contains the map)
// Return : void
void	draw_line(t_point *map, t_data *img)
{
	int		i;
	t_line	line;
	t_point	*lower;

	mlines(&line);
	while (map)
	{
		lower = map->next;
		i = 0;
		while (i <= map->loop)
		{
			pt_map(line.p1, map, i);
			if (i + 1 <= map->loop)
				pm_clip(&line, map, img, i + 1);
			if (lower)
				pm_clip(&line, lower, img, i);
			i++;
		}
		map = map->next;
	}
	free(line.p1);
	free(line.p2);
}

void	convert_iso(t_point *p)
{
	int		i;
	int		x0;
	int		y0;

	i = -1;
	x0 = (((1 - 1) * cos(0.463646)) * p->size_p) + 70;
	y0 = (((1 + 1 + 1) * sin(0.463646) - 1) * p->size_p) + 200;
	p->iso_x = (int *)malloc(sizeof(int) * (p->loop + 1));
	if (!p->iso_x)
		return ;
	p->iso_y = (int *)malloc(sizeof(int) * (p->loop + 1));
	if (!p->iso_y)
		return ;
	while (++i <= p->loop)
	{
		p->iso_x[i] = ((p->x[i] - p->z[i]) * cos(0.46365) * p->size_p)
			- x0 + (WIN_WIDTH / 2);
		p->iso_y[i] = (((p->x[i] + p->z[i]) * sin(0.46365) - p->y[i])
				* p->size_p) - y0 + (WIN_HEIGHT / 2);
	}
}

// Name : map_to_iso
// Description : convert the map from cartesian to isometric
// Parameters : t_map *map
// Return : void
void	map_to_iso(t_point *map)
{
	put_pad(map);
	while (map)
	{
		convert_iso(map);
		map = map->next;
	}
}
