/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:29:42 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/04 18:57:29 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

//Name: parser
// Parameters: char **av (the file name) 
// Return: int ** (the map) 
// Description: This function will parse the file and return the map
int	**parser(char **av)
{
	int		fd;
	int		**map;
	char	*line;
	char	**tmp;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	converter(fd, map, tmp);
	return (map);
}

//Name : converter
// Parameters: int fd (the file descriptor) 
// Return: int ** (the map)
// Description: This function will convert the map from a string to an int,
// and return the map
void	**converter(int fd, int **map, char **tmp)
{
	char	*line;
	int		**map_cpy;
	int		i;
	int		j;

	i = 0;
	while (1)
	{
		j = 0;
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tmp = ft_split(line, ' ');
		while (tmp[0][j])
		{
			map_cpy[i][j] = ft_atoi(tmp[j]);
			j++;
		}
		i++;
		free(line);
		free_split(tmp);
	}
	return (map);
}

// Name : cnt_x
// Parameters: char *line (the line of the map)
// Return: int (the number of x)
// Description: This function will count the number of x in the line
int	cnt_x(char *line)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			cnt++;
		i++;
	}
	return (cnt);
}
