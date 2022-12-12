/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:08:16 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/09 18:12:24 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// Name: free_map
// Parameters: t_point *map (the chained list that contains the map)
// Description: this function will free the chained list that contains the map
// Return: void
void	free_map(t_point *map)
{
	t_point	*tmp;

	while (map)
	{
		tmp = map;
		map = map->next;
		free(tmp->x);
		free(tmp->y);
		free(tmp->z);
		free(tmp);
	}
}
