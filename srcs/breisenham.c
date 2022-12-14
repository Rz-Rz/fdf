/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breisenham.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:44:40 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/14 22:04:21 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// Name : breisenham_switch 
// Description : This function will decide which function to use to draw the line
// depending on the slope of the line. 	 
// Parameters : t_pt *pt1, t_pt *pt2, t_data *data
// Return : void
void	breisenham_switch(t_pt *pt1, t_pt *pt2, t_data *data)
{
	int		dx;
	int		dy;

	dx = pt2->x - pt1->x;
	dy = pt2->y - pt1->y;
	if (dx == 0)
		breisenham_vertical(pt1, pt2, data);
	else if (dy == 0)
		breisenham_horizontal(pt1, pt2, data);
	else if (dx > 0 && dy > 0)
		breisenham_octant1(pt1, pt2, data);
	else if (dx < 0 && dy > 0)
		breisenham_octant2(pt1, pt2, data);
	else if (dx < 0 && dy < 0)
		breisenham_octant3(pt1, pt2, data);
	else if (dx > 0 && dy < 0)
		breisenham_octant4(pt1, pt2, data);
}
