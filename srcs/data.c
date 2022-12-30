/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:07:13 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/30 13:16:11 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_pad(t_point *p)
{
	int	hypothenuse;
	int	min;

	if (p == NULL)
		return (0);
	hypothenuse = sqrt(pow(p->size_x, 2) + pow(p->size_y, 2));
	min = WIN_HEIGHT;
	if (WIN_WIDTH < min)
		min = WIN_WIDTH;
	min -= 20;
	return ((min / hypothenuse) / 2);
}

void	get_map_size(t_point *map)
{
	t_point	*root;
	int		i;

	i = 0;
	if (map == NULL)
		return ;
	root = map;
	while (i <= map->loop)
		i++;
	root->size_x = i;
	root->size_y = ft_lstsize(root);
	while (root)
	{
		root->size_x = map->size_x;
		root->size_y = map->size_y;
		root = root->next;
	}
}

void	put_pad(t_point *p)
{
	int	pad;

	get_map_size(p);
	pad = get_pad(p);
	while (p)
	{
		p->size_p = pad;
		p = p->next;
	}
}

void	get_maxmin_z(t_point *map)
{
	int		max;
	int		min;
	int		i;
	t_point	*tmp;

	tmp = map;
	max = 0;
	min = 0;
	while (tmp)
	{
		i = -1;
		while (++i <= tmp->loop)
		{
			if (tmp->y[i] > max)
				max = tmp->y[i];
			if (tmp->y[i] < min)
				min = tmp->y[i];
		}
		tmp = tmp->next;
	}
	put_maxmin_z(map, max, min);
}

void	put_maxmin_z(t_point *map, int max, int min)
{
	while (map)
	{
		map->min_h = min;
		map->max_h = max;
		map = map->next;
	}
}
