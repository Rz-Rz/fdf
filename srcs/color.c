/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 21:36:13 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/25 16:43:27 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return (placement / distance);
}

int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	get_color(t_pt *current, t_pt *start, t_pt *end)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current->color == end->color)
		return (current->color);
	if (get_dx(start, end) > get_dy(start, end))
		percentage = percent(start->x, end->x, current->x);
	else
		percentage = percent(start->y, end->y, current->y);
	red = get_light((start->color >> 16) & 0xFF,
			(end->color >> 16) & 0xFF, percentage);
	green = get_light((start->color >> 8) & 0xFF,
			(end->color >> 8) & 0xFF, percentage);
	blue = get_light(start->color & 0xFF, end->color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
