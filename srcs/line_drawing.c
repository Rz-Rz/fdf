/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:14:21 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/21 14:02:09 by kdhrif           ###   ########.fr       */
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
	pt1->color = 0xFFF000FF;
	pt2->color = 0xFFF000FF;
	while (map)
	{
		lower = map->next;
		i = 0;
		while (i <= map->loop)
		{
			j = i + 1;
			if (j >= map->loop)
				break ;
			pt1->x = map->iso_x[i];
			pt1->y = map->iso_y[i];
			pt2->x = map->iso_x[j];
			pt2->y = map->iso_y[j];
			breisenham_switch(pt1, pt2, img);
			if (lower)
			{
				pt2->x = lower->iso_x[i];
				pt2->y = lower->iso_y[i];
				breisenham_switch(pt1, pt2, img);
			}
			i++;
		}
		map = map->next;
	}
}

//Name : convert_iso
//Description : convert a point from cartesian to isometric
//It has to loop through the x int arrays and z int arrays
//It will populate the iso_x and iso_z arrays as well as
//iso_y int with the new values.
//Parameters : t_point *p
//Return : void
// 1:2 ratio
/* void	convert_iso(t_point *p) */
/* { */
/* 	int		i; */

/* 	i = -1; */
/* 	p->iso_x = (int *)malloc(sizeof(int) * (p->loop + 1)); */
/* 	p->iso_y = (int *)malloc(sizeof(int) * (p->loop + 1)); */
/* 	while (++i < p->loop) */
/* 	{ */
/* 					p->iso_x[i] = (p->x[i] - p->z[i]) * cos(0.46365); */
/* 					p->iso_y[i] = p->y[i] + (p->x[i] +	p->z[i]) * sin(0.46365); */
/* 	} */
/* } */

/* void	convert_iso(t_point *p) */
/* { */
/* 	int		i; */

/* 	i = -1; */
/* 	p->iso_x = (int *)malloc(sizeof(int) * (p->loop + 1)); */
/* 	p->iso_y = (int *)malloc(sizeof(int) * (p->loop + 1)); */
/* 	while (++i < p->loop) */
/* 	{ */
/* 			p->iso_x[i] = (p->x[i] - p->y[i]) * cos(0.523599); */
/* 			p->iso_y[i] = -p->z[i] + (p->x[i] +	p->y[i]) * sin(0.523599); */
/* 	} */
/* } */

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
	int size;

	i = -1;
	size = 30;
	yFocus = 1;
	xFocus = 1;
	zFocus = 1;
	xCenter = WIN_WIDTH / 2;
	yCenter = WIN_HEIGHT / 2;
	x0 = ((xFocus - zFocus) * cos(0.463646)) * size;
	y0 = ((xFocus + zFocus + 1) * sin(0.463646) - yFocus) * size;
	p->iso_x = (int *)malloc(sizeof(int) * (p->loop + 1));
	p->iso_y = (int *)malloc(sizeof(int) * (p->loop + 1));
	while (++i <= p->loop)
	{

					p->iso_x[i] = ((p->x[i] - p->z[i]) * cos(0.46365) * size) - x0 + xCenter;
					p->iso_y[i] = (((p->x[i] + p->z[i]) * sin(0.46365) - p->y[i]) * size) - y0 + yCenter;
					/* p->iso_x[i] = (p->x[i] - p->y[i]) * cos(0.523599); */
					/* p->iso_y[i] = -p->z[i] + (p->x[i] +	p->y[i]) * sin(0.523599); */
					/* p->iso_x[i] = (sqrt(2) / 2) * (p->x[i] - p->y[i]); */
					/* p->iso_y[i] = (sqrt(2/3) * p->z[i]) - (1 / sqrt(6) * (p->x[i] + p->y[i])); */
					/* p->iso_x[i] = (p->x[i] + cos(0.523598) * p->z[i] - cos(0.523598) * p->y[i]); */
					/* p->iso_y[i] = (-p->y[i] * sin(0.523598) - p->z[i] * sin(0.523598)); */
					/* printf("iso_x : %d iso_y : %d \n", p->iso_x[i], p->iso_y[i]); */
	}
}

// Name : map_to_iso
// Description : convert the map from cartesian to isometric
// Parameters : t_map *map
// Return : void
void	map_to_iso(t_point *map)
{
	while (map)
	{
		convert_iso(map);
		map = map->next;
	}
}
