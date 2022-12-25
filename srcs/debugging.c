/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:05:55 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/25 17:02:10 by kdhrif           ###   ########.fr       */
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
		while (j <= map->loop)
		{
			printf("x: %d ", map->iso_x[j]);
			printf("y: %d ", map->iso_y[j]);
			j++;
		}
		printf("\n");
		map = map->next;
	}
}

// Name : print_likemap
// Description : print the map
// Parameters : t_map *map
// Return : void
void	print_likemap(t_point *map)
{
	int	j;

	while (map)
	{
		j = 0;
		while (j <= map->loop)
		{
			printf("%d ", map->y[j]);
			j++;
		}
		printf("\n");
		map = map->next;
	}
}
