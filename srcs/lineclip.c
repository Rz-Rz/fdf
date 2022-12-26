/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lineclip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:26:56 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/26 19:24:51 by kdhrif           ###   ########.fr       */
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
void	lineclip(t_line *line, t_data *data)
{
	t_clip	clip;

	clip.accept = 0;
	clip.done = 0;
	while (!clip.done)
	{
		clip.code1 = region_code(line->p1);
		clip.code2 = region_code(line->p2);
		if (clip.code1 == 0 && clip.code2 == 0)
		{
			clip.accept = 1;
			clip.done = 1;
		}
		else if (clip.code1 & clip.code2)
			clip.done = 1;
		else
			clip_plus(clip, line->p1, line->p2);
	}
	if (clip.accept)
		breisenham_switch(line, data);
}

void	clip_plus(t_clip clip, t_pt *pt1, t_pt *pt2)
{
	t_pt	tmp;

	if (clip.code1)
		clip.code_out = clip.code1;
	else
		clip.code_out = clip.code2;
	more_clip(clip, pt1, pt2, &tmp);
	if (clip.code_out == clip.code1)
	{
		pt1->x = tmp.x;
		pt1->y = tmp.y;
		clip.code1 = region_code(pt1);
	}
	else
	{
		pt2->x = tmp.x;
		pt2->y = tmp.y;
		clip.code2 = region_code(pt2);
	}
}

void	more_clip(t_clip clip, t_pt *pt1, t_pt *pt2, t_pt *tmp)
{
	if (clip.code_out & 8)
	{
		tmp->x = pt1->x + (pt2->x - pt1->x) * (WIN_HEIGHT - pt1->y)
			/ (pt2->y - pt1->y);
		tmp->y = WIN_HEIGHT - 2;
	}
	else if (clip.code_out & 4)
	{
		tmp->x = pt1->x + (pt2->x - pt1->x) * (-pt1->y) / (pt2->y - pt1->y);
		tmp->y = 0;
	}
	else if (clip.code_out & 2)
	{
		tmp->y = pt1->y + (pt2->y - pt1->y) * (WIN_WIDTH - pt1->x)
			/ (pt2->x - pt1->x);
		tmp->x = WIN_WIDTH - 2;
	}
	else if (clip.code_out & 1)
	{
		tmp->y = pt1->y + (pt2->y - pt1->y) * (-pt1->x) / (pt2->x - pt1->x);
		tmp->x = 0;
	}
}
