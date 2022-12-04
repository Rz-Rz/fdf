/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:06:21 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/04 16:28:04 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_cntwrds(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			words++;
		while (s[i] != c && s[i])
			i++;
	}
	return (words);
}

char	*ft_strdupm(char *s, char c)
{
	int		i;
	int		d;
	char	*str;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	d = 0;
	while (s[d] != c && s[d])
	{
		str[d] = s[d];
		d++;
	}
	str[d] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		wrds;
	char	**strings;
	int		i;
	int		k;

	if (!s)
		return (NULL);
	wrds = ft_cntwrds(s, c);
	strings = malloc(sizeof(char *) * (wrds + 1));
	if (!strings)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			strings[k++] = ft_strdupm((char *)&s[i], c);
		while (s[i] != c && s[i])
			i++;
	}
	strings[k] = NULL;
	return (strings);
}
