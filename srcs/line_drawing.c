/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:14:21 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/15 21:33:41 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// Name : draw_line
// Description : draw a line between two points
// It will use my breisenham function,
// but it will also draw the line in the iso projection
// Parameters : t_point *line (the chained list that contains the map)
// Return : void
/* void	draw_line(t_point *map, t_data *img) */
/* { */
/* 	int		i; */
/* 	t_point	*lower; */
/* 	int		j; */

/* 	while (map) */
/* 	{ */
/* 		lower = map->next; */
/* 		if (!lower) */
/* 			break ; */
/* 		i = 0; */
/* 		while (i < map->loop) */
/* 		{ */
/* 			j = i + 1; */
/* 			if (j >= map->loop) */
/* 				break ; */
/* 			breisenham(map->iso_x[i], map->iso_y[i], map->iso_x[j], \ */
/* 					map->iso_y[j], img); */
/* 			breisenham(map->iso_x[i], map->iso_y[i], lower->iso_x[i], \ */
/* 					lower->iso_y[i], img); */
/* 			i++; */
/* 		} */
/* 		map = map->next; */
/* 	} */
/* } */

// Name : breisenham
// Description : draw a line between two points
// Parameters : int x0, int y0, int x1, int y1, t_data *img
// Return : void
/* void	breisenham(int x0, int y0, int x1, int y1, t_data *img) */
/* { */
/* 	int	dx; */
/* 	int	dy; */
/* 	int	sx; */
/* 	int	sy; */
/* 	int	err; */
/* 	int	e2; */

/* 	dx = abs(x1 - x0); */
/* 	dy = abs(y1 - y0); */
/* 	sx = x0 < x1 ? 1 : -1; */
/* 	sy = y0 < y1 ? 1 : -1; */
/* 	err = (dx > dy ? dx : -dy) / 2; */
/* 	while (1) */
/* 	{ */
/* 		pixel_put(img, x0, y0, 0x00FFFFFF); */
/* 		if (x0 == x1 && y0 == y1) */
/* 			break ; */
/* 		e2 = err; */
/* 		if (e2 > -dx) */
/* 		{ */
/* 			err -= dy; */
/* 			x0 += sx; */
/* 		} */
/* 		if (e2 < dy) */
/* 		{ */
/* 			err += dx; */
/* 			y0 += sy; */
/* 		} */
/* 	} */
/* } */

// Name : center_map
// Description : center the map in the middle of the window
// Use the  WIN_WIDTH and WIN_HEIGHT define
// Parameters : t_point *map (the chained list that contains the map)
// Return : void
void	center_map(t_point *map)
{
	int	i;
	int	scale_factor;

	scale_factor = 3;
	while (map)
	{
		i = 0;
		while (i < map->loop)
		{
			map->x[i] = (map->x[i] * WIN_WIDTH * scale_factor) / 100;
			map->y[i] = (map->y[i] * WIN_HEIGHT * scale_factor) / 100;
			printf("x y : %d %d \n", map->x[i], map->y[i]);
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

	i = -1;
	p->iso_x = (int *)malloc(sizeof(int) * (p->loop + 1));
	p->iso_y = (int *)malloc(sizeof(int) * (p->loop + 1));
	while (++i < p->loop)
	{
		p->iso_x[i] = (p->x[i] - p->y[i]) * cos(0.523599);
		p->iso_y[i] = -p->z[i] + (p->x[i] +	p->y[i]) * sin(0.523599);
		/* p->iso_x[i] = abs((sqrt(2) / 2) * (p->x[i] - p->y[i])); */
		/* p->iso_y[i] = abs((sqrt(2/3) * p->z[i]) - (1 / sqrt(6) * (p->x[i] + p->y[i]))); */
		/* p->iso_x[i] = abs((p->x[i] + cos(0.523598) * p->z[i] - cos(0.523598) * p->y[i])); */
		/* p->iso_y[i] = abs((-p->y[i] * sin(0.523598) - p->z[i] * sin(0.523598))); */
		printf("iso_x : %d iso_y : %d \n", p->iso_x[i], p->iso_y[i]);
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
