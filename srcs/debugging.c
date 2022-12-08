/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:05:55 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/08 18:46:06 by kdhrif           ###   ########.fr       */
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
			printf("y: %d ", map->y);
			printf("z: %d ", map->z[j]);
			printf(" ");
			j++;
		}
		printf("\n");
		map = map->next;
	}
}

