/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lineclip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:26:56 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/23 12:54:34 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// Name: region_code
// Description: This function will return the region code of a point
// Parameters: t_pt *pt
// Return: int
int	region_code(t_pt *pt)
{
	int	code;

	code = 0;
	if (pt->x < 0)
		code += 1;
	if (pt->x > WIN_WIDTH)
		code += 2;
	if (pt->y < 0)
		code += 4;
	if (pt->y > WIN_HEIGHT)
		code += 8;
	return (code);
}

// Name: lineclip
// Description: This function will clip a line if it is outside the window
// Parameters: t_pt *pt1, t_pt *pt2, t_data *data
// Return: void
void	lineclip(t_pt *pt1, t_pt *pt2, t_data *data)
{
	int		code1;
	int		code2;
	int		accept;
	int		done;
	int		x;
	int		y;
	int		code_out;

	accept = 0;
	done = 0;
	while (!done)
	{
		code1 = region_code(pt1);
		code2 = region_code(pt2);
		if (code1 == 0 && code2 == 0)
		{
			accept = 1;
			done = 1;
		}
		else if (code1 & code2)
			done = 1;
		else
		{
			if (code1)
				code_out = code1;
			else
				code_out = code2;
			if (code_out & 8)
			{
				x = pt1->x + (pt2->x - pt1->x) * (WIN_HEIGHT - pt1->y) / (pt2->y - pt1->y);
				y = WIN_HEIGHT - 2;
			}
			else if (code_out & 4)
			{
				x = pt1->x + (pt2->x - pt1->x) * (-pt1->y) / (pt2->y - pt1->y);
				y = 0;
			}
			else if (code_out & 2)
			{
				y = pt1->y + (pt2->y - pt1->y) * (WIN_WIDTH - pt1->x) / (pt2->x - pt1->x);
				x = WIN_WIDTH - 2;
			}
			else if (code_out & 1)
			{
				y = pt1->y + (pt2->y - pt1->y) * (-pt1->x) / (pt2->x - pt1->x);
				x = 0;
			}
			if (code_out == code1)
			{
				pt1->x = x;
				pt1->y = y;
				code1 = region_code(pt1);
			}
			else
			{
				pt2->x = x;
				pt2->y = y;
				code2 = region_code(pt2);
			}
		}
	}
	if (accept)
		breisenham_switch(pt1, pt2, data);
	}



