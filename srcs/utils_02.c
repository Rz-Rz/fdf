/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:56:21 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/23 14:53:52 by kdhrif           ###   ########.fr       */
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

// Name: ft_isdigit
// Description: check if the char is a digit
// Parameters: int c
// Return: int
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// Name: ft_isalpha
// Description: check if the char is a letter
// Parameters: int c
// Return: int
int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}


// Name: ft_isalphanumeric
// Description: check if the char is a letter or a digit
// Parameters: int c
// Return: int
int	ft_isalphanumeric(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
