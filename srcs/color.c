/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 21:36:13 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/26 18:51:22 by kdhrif           ###   ########.fr       */
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

double	ft_lint(double start, double end, double decimal_percent)
{
	if (start == end)
		return (start);
	return (start * (1.0 - decimal_percent) + (end * decimal_percent));
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

int	color_lint(int c1, int c2, double decimal_percent)
{
	int	r;
	int	g;
	int	b;

	if (c1 == c2)
		return (c1);
	if (decimal_percent == 0.0)
		return (c1);
	if (decimal_percent == 1.0)
		return (c2);
	r = (int)ft_lint(((c1 >> 16) & 0xFF), ((c2 >> 16) & 0xFF), decimal_percent);
	g = (int)ft_lint(((c1 >> 8) & 0xFF), ((c2 >> 8) & 0xFF), decimal_percent);
	b = (int)ft_lint((c1 & 0xFF), (c2 & 0xFF), decimal_percent);
	return (r << 16 | g << 8 | b);
}
