/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:56:21 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/18 13:51:14 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// Name : swap_pt
// Description : swap the two points
// Parameters : t_pt *pt1, t_pt *pt2
// Return : void
void	swap_pt(t_pt *pt1, t_pt *pt2)
{
	t_pt	tmp;

	tmp.x = pt1->x;
	tmp.y = pt1->y;
	pt1->x = pt2->x;
	pt1->y = pt2->y;
	pt2->x = tmp.x;
	pt2->y = tmp.y;
}

// Name : abs
// Description : return the absolute value of a number
// Parameters : int n
// Return : int
int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}