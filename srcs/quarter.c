/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quarter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:35:41 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/15 19:36:34 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../fdf.h" 

// Name : first_quarter
// Description: This function will determine if the two point 
// are in the first quarter of the cartesian plan.
// Parameters: t_pt *pt1, t_pt *pt2
// Return: int
int	first_quarter(t_pt *pt1, t_pt *pt2)
{
	if (pt1->x < pt2->x && pt1->y < pt2->y)
		return (1);
	return (0);
}

// Name : second_quarter
// Description: This function will determine if the two point
// are in the second quarter of the cartesian plan.
// Parameters: t_pt *pt1, t_pt *pt2
// Return: int
int	second_quarter(t_pt *pt1, t_pt *pt2)
{
	if (pt1->x > pt2->x && pt1->y < pt2->y)
		return (1);
	return (0);
}

// Name : third_quarter
// Description: This function will determine if the two point
// are in the third quarter of the cartesian plan.
// Parameters: t_pt *pt1, t_pt *pt2
// Return: int
int	third_quarter(t_pt *pt1, t_pt *pt2)
{
	if (pt1->x > pt2->x && pt1->y > pt2->y)
		return (1);
	return (0);
}

// Name : fourth_quarter
// Description: This function will determine if the two point
// are in the fourth quarter of the cartesian plan.
// Parameters: t_pt *pt1, t_pt *pt2
// Return: int
int	fourth_quarter(t_pt *pt1, t_pt *pt2)
{
	if (pt1->x < pt2->x && pt1->y > pt2->y)
		return (1);
	return (0);
}
