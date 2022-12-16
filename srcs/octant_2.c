/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octant_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:49:26 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/15 19:51:11 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// Name : sixth_octant
// Description : This function will determine if the two point
// are in the sixth octant.
// Parameters : t_pt *pt1, t_pt *pt2
// Return : int
int	sixth_octant(t_pt *pt1, t_pt *pt2)
{
	int		dx;
	int		dy;

	dx = pt2->x - pt1->x;
	dy = pt2->y - pt1->y;
	if (dx <= 0 && dy <= 0 && dx > dy)
		return (1);
	return (0);
}

// Name : seventh_octant
// Description : This function will determine if the two point
// are in the seventh octant.
// Parameters : t_pt *pt1, t_pt *pt2
// Return : int
int	seventh_octant(t_pt *pt1, t_pt *pt2)
{
	int		dx;
	int		dy;

	dx = pt2->x - pt1->x;
	dy = pt2->y - pt1->y;
	if (dx <= 0 && dy <= 0 && dx <= dy)
		return (1);
	return (0);
}

// Name : eighth_octant
// Description : This function will determine if the two point
// are in the eighth octant.
// Parameters : t_pt *pt1, t_pt *pt2
// Return : int
int	eighth_octant(t_pt *pt1, t_pt *pt2)
{
	int		dx;
	int		dy;

	dx = pt2->x - pt1->x;
	dy = pt2->y - pt1->y;
	if (dx <= 0 && dy >= 0 && dx <= -dy)
		return (1);
	return (0);
}
