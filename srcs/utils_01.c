/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:18:21 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/04 18:54:13 by kdhrif           ###   ########.fr       */
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

// Name : ft_realloc
// Description : realloc the string
// Input : char *str, int size
// Output : char *str
char	*ft_realloc(char *str, int size)
{
	char	*new_str;
	int		i;

	i = 0;
	if (!(new_str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	free(str);
	return (new_str);
}

