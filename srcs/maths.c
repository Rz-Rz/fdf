/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 21:47:12 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/25 13:13:16 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int get_dx(t_pt *start, t_pt *end)
{
	return (abs(end->x - start->x));
}

int get_dy(t_pt *start, t_pt *end)
{
	return (abs(end->y - start->y));
}

int get_slope(t_pt start, t_pt end)
{
	return ((end.y - start.y) / (end.x - start.x));
}


