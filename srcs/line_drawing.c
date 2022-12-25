/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:14:21 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/25 15:01:38 by kdhrif           ###   ########.fr       */
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
	int		j;
	t_pt	*pt1;
	t_pt	*pt2;
	t_point *lower;

	pt1 = malloc(sizeof(t_pt));
	pt2 = malloc(sizeof(t_pt));
	while (map)
	{
		lower = map->next;
		i = 0;
		while (i <= map->loop)
		{
			j = i + 1;
			pt1->x = map->iso_x[i];
			pt1->y = map->iso_y[i];
			pt1->color = map->color[i];
			if (j <= map->loop)
			{
				pt2->x = map->iso_x[j];
				pt2->y = map->iso_y[j];
				pt2->color = map->color[j];
				lineclip(pt1, pt2, img);
			}
			if (lower)
			{
				pt2->x = lower->iso_x[i];
				pt2->y = lower->iso_y[i];
				pt2->color = lower->color[i];
				lineclip(pt1, pt2, img);
			}
			i++;
		}
		map = map->next;
	}
	free(pt1);
	free(pt2);
}

void	convert_iso(t_point *p)
{
	int		i;
	int 	xCenter;
	int 	yCenter;
	int		x0;
	int		y0;
	int xFocus;
	int yFocus;
	int zFocus;

	i = -1;
	yFocus = 1;
	xFocus = 1;
	zFocus = 1;
	xCenter = WIN_WIDTH / 2;
	yCenter = WIN_HEIGHT / 2;
	x0 = (((xFocus - zFocus) * cos(0.463646)) * p->size_p) + 70;
	y0 = (((xFocus + zFocus + 1) * sin(0.463646) - yFocus) * p->size_p) + 200;
	p->iso_x = (int *)malloc(sizeof(int) * (p->loop + 1));
	p->iso_y = (int *)malloc(sizeof(int) * (p->loop + 1));
	while (++i <= p->loop)
	{

					p->iso_x[i] = ((p->x[i] - p->z[i]) * cos(0.46365) * p->size_p) - x0 + xCenter;
					p->iso_y[i] = (((p->x[i] + p->z[i]) * sin(0.46365) - p->y[i]) * p->size_p) - y0 + yCenter;
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
