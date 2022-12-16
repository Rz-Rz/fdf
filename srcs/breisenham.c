/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breisenham.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:44:40 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/16 18:52:41 by kdhrif           ###   ########.fr       */
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

	if ()
}

// Name: one_fourth_octant
// Description: This function will draw the line for the first and 
// the fourth octant
// of the cartesian plan. Where DeltaX >= DeltaY, so we increment x as the 
// main axis, and y when the error is greater than 0.
// Parameters: t_pt *pt1, t_pt *pt2, t_data *data
// Return: void
void	one_fourth_octant(t_pt *pt1, t_pt *pt2, t_data *data)
{
	int		dx;
	int		dy;
	int		error;
	int		x;
	int		y;

	dx = pt2->x - pt1->x;
	dy = pt2->y - pt1->y;
	error = 0;
	x = pt1->x;
	y = pt1->y;
	while (x <= pt2->x)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0x00FFFFFF);
		error += dy;
		if (error >= dx)
		{
			y++;
			error -= dx;
		}
		x++;
	}
}

// Name: fourth_quarter 
// Description: This function will draw the line in the fourth quarter of the
// cartesian plan. For the third and fourth octant.
// Parameters: t_pt *pt1, t_pt *pt2, t_data *data
// Return: void
void	draw_sq(t_pt *pt1, t_pt *pt2, t_data *data)
{
	int		dx;
	int		dy;
	int		d;
	int		de;
	int		dne;
	int		x;
	int		y;

	dx = pt2->x - pt1->x;
	dy = pt2->y - pt1->y;
	d = 2 * dy + dx;
	de = 2 * dy;
	dne = 2 * (dy + dx);
	x = pt1->x;
	y = pt1->y;
	pixel_put(data, x, y, pt1->color);
	if (third_octant(pt1, pt2))
	{
		while (x > pt2->x)
		{
			if (d <= 0)
				d += de;
			else
			{
				d += dne;
				y++;
			}
			x--;
			pixel_put(data, x, y, pt1->color);
		}
	}
	else if (fourth_octant(pt1, pt2))
	{
		while (y < pt2->y)
		{
			if (d <= 0)
				d += de;
			else
			{
				d += dne;
				x--;
			}
			y++;
			pixel_put(data, x, y, pt1->color);
		}
	}
}





