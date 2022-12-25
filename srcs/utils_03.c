/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:28:26 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/25 14:20:23 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

//Name: ft_atoibase
//Parameters: char *str, char *base
//Description: convert a string to an int
//This function has a special behavior
//It start converting a string to an int only after
//it finds a comma <,> from the base string
//Return: int
int	ft_atoibase(char *str, char *base)
{
	int	i;
	int	j;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] == ',')
		i += 3;
	else 
		return (0xFFFFFF);
	while (str[i] && str[i] != ',')
	{
		j = 0;
		while (base[j] && base[j] != str[i])
			j++;
		if (base[j] == str[i])
			nb = nb * ft_strlen(base) + j;
		else
			return (nb * sign);
		i++;
	}
	return (nb * sign);
}

// Name: ft_strlen
// Parameters: char *str
// Description: return the length of a string
// Return: int
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// Name: ft_lstsize
// Parameters: t_point *p
// Description: return the number of elements in a chained list
// Return: int
int	ft_lstsize(t_point *p)
{
	int	i;

	i = 0;
	while (p)
	{
		i++;
		p = p->next;
	}
	return (i);
}
