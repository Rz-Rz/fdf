/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:07:13 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/25 15:11:33 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int get_pad(t_point *p)
{
	int hypothenuse;
	int min;

	hypothenuse = sqrt(pow(p->size_x, 2) + pow(p->size_y, 2));
	min = WIN_HEIGHT;
	if (WIN_WIDTH < min)
		min = WIN_WIDTH;
	min -= 20;
	return ((min / hypothenuse) / 2);
}

void get_map_size(t_point *map)
{
	t_point *root;
	int x;
	int i;


	x = 0;
	i = 0;
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

void put_pad(t_point *p)
{
	int pad;

	get_map_size(p);
	pad = get_pad(p);
	while (p)
	{
		p->size_p = pad;
		p = p->next;
	}
}
