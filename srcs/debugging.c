/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:05:55 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/16 16:40:10 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// Name : print_map
// Description : print the map
// Parameters : t_map *map
// Return : void
void	print_map(t_point *map)
{
	int	j;

	while (map)
	{
		j = 0;
		while (j < map->loop)
		{
			printf("x: %d ", map->x[j]);
			printf("y: %d ", map->y[j]);
			printf("z: %d ", map->z[j]);
			printf(" ");
			/* printf("x: %d ", map->iso_x[j]); */
			/* printf("y: %d ", map->iso_y[j]); */
			j++;
		}
		printf("\n");
		map = map->next;
	}
}

// Name : which_octant
// Description : print the octant of the line using the function 
// in octant.c and octant_2.c 
// Parameters : t_point *pt1, t_point *pt2 
// Return : void
void	which_octant(t_pt *pt1, t_pt *pt2)
{
	int	octant;

	octant = 0;
	if (first_octant(pt1, pt2))
		printf("first octant\n");
	if (second_octant(pt1, pt2))
		printf("second octant\n");
	if (third_octant(pt1, pt2))
		printf("third octant\n");
	if (fourth_octant(pt1, pt2))
		printf("fourth octant\n");
	if (fifth_octant(pt1, pt2))
		printf("fifth octant\n");
	if (sixth_octant(pt1, pt2))
		printf("sixth octant\n");
	if (seventh_octant(pt1, pt2))
		printf("seventh octant\n");
	if (eighth_octant(pt1, pt2))
		printf("eigth octant\n");
}

// Name : which_quarter 
// Description : print the quarter of the line using the function
// in quarter.c
// Parameters : t_point *pt1, t_point *pt2
// Return : void
void	which_quarter(t_pt *pt1, t_pt *pt2)
{
	int	quarter;

	quarter = 0;
	if (first_quarter(pt1, pt2))
		printf("first quarter\n");
	if (second_quarter(pt1, pt2))
		printf("second quarter\n");
	if (third_quarter(pt1, pt2))
		printf("third quarter\n");
	if (fourth_quarter(pt1, pt2))
		printf("fourth quarter\n");
}
