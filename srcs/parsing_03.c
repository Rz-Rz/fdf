/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_03.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:28:24 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/25 17:40:11 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	malloc_stuff(t_point *point, char **split, int y)
{
	int	i;

	point->x = (int *)malloc(sizeof(int) * (ft_splitlen(split)));
	if (!point->x)
		return (0);
	i = -1;
	while (split[++i])
		point->x[i] = i;
	point->z = (int *)malloc(sizeof(int) * (ft_splitlen(split)));
	if (!point->z)
		return (0);
	i = -1;
	while (split[++i])
		point->z[i] = y;
	point->y = (int *)malloc(sizeof(int) * (ft_splitlen(split)));
	if (!point->y)
		return (0);
	i = -1;
	while (split[++i])
		point->y[i] = ft_atoi(split[i]);
	i = -1;
	return (1);
}

// Name: line_check
// Description: check if the line is valid:
// to be valid it must no be empty
// it must have the same number of numbers as the first line
// it must contain only numbers, letters, commas and space
// Input: char *line
// Output: int (0 if valid, 1 if not)
int	line_check(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			i++;
		else if (line[i] == '-' && ft_isdigit(line[i + 1]))
			i++;
		else if (ft_isalphanumeric(line[i]))
			i++;
		else if (line[i] == ',')
			i++;
		else if (line[i] == '\n' && line[i + 1] == '\0')
			return (0);
		else
			return (1);
	}
	return (0);
}

// Name: ft_count_numbers
// Description: count the number of numbers in a string
// Input: char *line
// Output: int (the number of numbers)
int	ft_count_numbers(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] != ' ' && line[i] != '\0')
			count++;
		while (line[i] != ' ' && line[i] != '\0')
			i++;
	}
	return (count);
}
