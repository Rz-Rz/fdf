/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octant.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:17:36 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/16 18:59:58 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// Name : first_octant
// Description : This function will determine if the two point
// are in the first octant.
// Parameters : t_pt *pt1, t_pt *pt2
// Return : int
int	first_octant(t_pt *pt1, t_pt *pt2)
{
	int		dx;
	int		dy;

	dx = pt2->x - pt1->x;
	dy = pt2->y - pt1->y;
	if (dx >= 0 && dy >= 0 && dx >= dy)
		return (1);
	return (0);
}

// Name : second_octant
// Description : This function will determine if the two point
// are in the second octant.
// Parameters : t_pt *pt1, t_pt *pt2
// Return : int
int	second_octant(t_pt *pt1, t_pt *pt2)
{
	int		dx;
	int		dy;

	dx = pt2->x - pt1->x;
	dy = pt2->y - pt1->y;
	if (dx >= 0 && dy >= 0 && dx < dy)
		return (1);
	return (0);
}

// Name : third_octant
// Description : This function will determine if the two point
// are in the third octant.
// Parameters : t_pt *pt1, t_pt *pt2
// Return : int
int	third_octant(t_pt *pt1, t_pt *pt2)
{
	int		dx;
	int		dy;

	dx = pt2->x - pt1->x;
	dy = pt2->y - pt1->y;
	if (dx <= 0 && dy >= 0 && - dx < dy)
		return (1);
	return (0);
}

// Name : fourth_octant
// Description : This function will determine if the two point
// are in the fourth octant.
// Parameters : t_pt *pt1, t_pt *pt2
// Return : int
int	fourth_octant(t_pt *pt1, t_pt *pt2)
{
	int		dx;
	int		dy;

	dx = pt2->x - pt1->x;
	dy = pt2->y - pt1->y;
	if (dx <= 0 && dy >= 0 && - dx >= dy)
		return (1);
	return (0);
}

// Name : fifth_octant
// Description : This function will determine if the two point
// are in the fifth octant.
// Parameters : t_pt *pt1, t_pt *pt2
// Return : int
int	fifth_octant(t_pt *pt1, t_pt *pt2)
{
	int		dx;
	int		dy;

	dx = pt2->x - pt1->x;
	dy = pt2->y - pt1->y;
	if (dx <= 0 && dy <= 0 && dx <= dy)
		return (1);
	return (0);
}
