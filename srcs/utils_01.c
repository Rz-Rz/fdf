/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:18:21 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/25 17:42:06 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_atoi(const char *nptr)
{
	long long	nb;
	int			neg;

	nb = 0;
	neg = 0;
	while ((*nptr >= 9 && *nptr <= 13) || (*nptr == ' '))
		nptr++;
	while (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			neg++;
	while (*nptr >= '0' && *nptr <= '9')
		nb = nb * 10 + *nptr++ - '0';
	if (neg)
		nb *= -1;
	return ((int)nb);
}

// Name : free_split
// Description : free the split
// Input : char **split
// Output : void
void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

// Name: ft_putstr
// Parameters: char *str (the string to print)
// Return: void
// Description: this function will print the string
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

// Name : ft_splitlen
// Description : return the length of the split
// Input : char **split
// Output : int
int	ft_splitlen(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}
