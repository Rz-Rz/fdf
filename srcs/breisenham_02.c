/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breisenham_02.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:05:43 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/22 15:08:29 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// Name : brei_sw_norm
// Description : This function will decide which function to
// use to draw the line
//

void	brei_sw_norm(t_pt *pt1, t_pt *pt2, t_data *data, int dir)
{
	int	dy;

	dy = pt2->y - pt1->y;
	if (dy < 0)
	{
		swap_pt(pt1, pt2);
		dir = direction(pt1, pt2);
		two_third_octant(pt1, pt2, data, dir);
	}
	else
	{
		dir = direction(pt1, pt2);
		two_third_octant(pt1, pt2, data, dir);
	}
}
