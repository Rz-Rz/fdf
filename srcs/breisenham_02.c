/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breisenham_02.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:05:43 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/30 17:59:30 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// Name : brei_sw_norm
// Description : This function will decide which function to
// use to draw the line
//

void	brei_sw_norm(t_line *line, t_data *data, int dir)
{
	int	dy;

	dy = line->p2->y - line->p1->y;
	if (dy < 0)
	{
		swap_pt(line->p1, line->p2);
		dir = direction(line->p1, line->p2);
		two_third_octant(line, data, dir);
	}
	else
	{
		dir = direction(line->p1, line->p2);
		two_third_octant(line, data, dir);
	}
}

void	set_br(int *cnt, int *error, t_line *line, t_pt *pt)
{
	*cnt = get_dy(line->p1, line->p2);
	*error = get_dx(line->p1, line->p2) * 2 - get_dy(line->p1, line->p2);
	pt_pt(pt, line->p1);
	pt->color = get_color(pt, line->p1, line->p2);
}

void	set_br2(int *cnt, int *error, t_line *line, t_pt *pt)
{
	*cnt = get_dx(line->p1, line->p2);
	*error = get_dy(line->p1, line->p2) * 2 - get_dx(line->p1, line->p2);
	pt_pt(pt, line->p1);
	pt->color = get_color(pt, line->p1, line->p2);
}
