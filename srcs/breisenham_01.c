/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breisenham_01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:44:40 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/25 20:01:59 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// Name : breisenham_switch
// Description : This function will decide which function to
// use to draw the line
// depending on the slope of the line. If dy > dx, we will use the function
// two_third_octant to draw the line. If dx >= dy, we will use the function
// one_fourth_octant to draw the line. If the lines are of octant 5, 6, 7 or 8,
// we will swap the coordinates of the line to draw it.
// Parameters : t_pt *pt1, t_pt *pt2, t_data *data
// Return : void
void	breisenham_switch(t_pt *pt1, t_pt *pt2, t_data *data)
{
	int	dx;
	int	dy;
	int	dir;

	dx = pt2->x - pt1->x;
	dy = pt2->y - pt1->y;
	dir = 0;
	if (ft_abs(dy) > ft_abs(dx))
		brei_sw_norm(pt1, pt2, data, dir);
	else
	{
		if (dx < 0 && dy < 0)
		{
			swap_pt(pt1, pt2);
			dir = direction(pt1, pt2);
			one_fourth_octant(pt1, pt2, data, dir);
		}
		else
		{
			dir = direction(pt1, pt2);
			one_fourth_octant(pt1, pt2, data, dir);
		}
	}
}

// Name: one_fourth_octant
// Description: This function will draw the line for the first and
// the fourth octant
// of the cartesian plan. Where DeltaX >= DeltaY, so we increment x as the
// main axis, and y when the error is greater than 0.
// Parameters: t_pt *pt1, t_pt *pt2, t_data *data
// Return: void
void	one_fourth_octant(t_pt *pt1, t_pt *pt2, t_data *data, int dir)
{
	int		error;
	t_pt	*pt;
	int		cnt;

	pt = malloc(sizeof(t_pt));
	cnt = get_dx(pt1, pt2);
	error = get_dy(pt1, pt2) * 2 - get_dx(pt1, pt2);
	pt->x = pt1->x;
	pt->y = pt1->y;
	pt->color = pt1->color;
	pt->color = get_color(pt, pt1, pt2);
	pixel_put(data, pt->x, pt->y, pt->color);
	while (cnt--)
	{
		if (error >= 0)
		{
			pt->y++;
			error += get_dy(pt1, pt2) * 2 - get_dx(pt1, pt2) * 2;
		}
		else
			error += get_dy(pt1, pt2) * 2;
		pt->x += dir;
		pt->color = get_color(pt, pt1, pt2);
		pixel_put(data, pt->x, pt->y, pt->color);
	}
	free(pt);
}

// Name: two_third_octant
// Description: This function will draw the line for the second and
// the third octant
// of the cartesian plan. Where DeltaX <= DeltaY, so we increment y as the
// main axis, and x when the error is greater than 0.
// Parameters: t_pt *pt1, t_pt *pt2, t_data *data
// Return: void
void	two_third_octant(t_pt *pt1, t_pt *pt2, t_data *data, int dir)
{
	int		error;
	t_pt	*pt;
	int		cnt;

	pt = malloc(sizeof(t_pt));
	cnt = get_dy(pt1, pt2);
	error = get_dx(pt1, pt2) * 2 - get_dy(pt1, pt2);
	pt->x = pt1->x;
	pt->y = pt1->y;
	pt->color = pt1->color;
	pt->color = get_color(pt, pt1, pt2);
	pixel_put(data, pt->x, pt->y, pt->color);
	while (cnt--)
	{
		if (error >= 0)
		{
			pt->x += dir;
			error += get_dx(pt1, pt2) * 2 - get_dy(pt1, pt2) * 2;
		}
		else
			error += get_dx(pt1, pt2) * 2;
		pt->y++;
		pt->color = get_color(pt, pt1, pt2);
		pixel_put(data, pt->x, pt->y, pt->color);
	}
	free(pt);
}

// name : direction
// description : This function will decide which direction to draw the line
// if dx < 0, we will draw the line from right to left, so direction = -1
// if dx >= 0, we will draw the line from left to right, so direction = 1
// Parameters : t_pt *pt1, t_pt *pt2
// Return : int
int direction(t_pt *pt1, t_pt *pt2) {
	int dx;

	dx = pt2->x - pt1->x;
	if (dx < 0)
		return (-1);
	else
		return (1);
}
