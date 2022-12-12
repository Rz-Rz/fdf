/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:05:55 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/09 23:24:33 by kdhrif           ###   ########.fr       */
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

