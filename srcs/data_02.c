/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:13:31 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/26 19:14:48 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	is_vanilla(t_point *map)
{
	int		i;
	t_point	*tmp;

	tmp = map;
	while (tmp)
	{
		i = -1;
		while (++i <= tmp->loop)
		{
			if (tmp->color[i] != 0xFFFFFF)
			{
				return (0);
			}
		}
		tmp = tmp->next;
	}
	return (1);
}

void	put_vanilla(t_point *map, int vanilla)
{
	t_point	*tmp;

	tmp = map;
	while (tmp)
	{
		tmp->is_vanilla = vanilla;
		tmp = tmp->next;
	}
}
