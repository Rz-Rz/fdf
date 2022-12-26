/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:29:42 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/26 19:27:44 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// Name: parser
// Parameters: char **av (the file name)
// Return: t_point * (the chained list that contains the map)
// Description: this function will parse the file and create the chained list
// that contains the map
t_point	*parser(char **av)
{
	int		fd;
	char	*line;
	t_point	*map;
	int		y;

	y = -1;
	map = NULL;
	line = NULL;
	fd = open(av[1], O_RDONLY);
	check_fd(fd, line, map);
	line = get_next_line(fd);
	while (line)
	{
		check_err(line, map, fd);
		y++;
		map_add(&map, line, y);
		free(line);
		line = get_next_line(fd);
	}
	fd_done(fd, map);
	return (map);
}

// Name : create_point
// Description : create a point
// Input : char *line
// Output : t_point *point
t_point	*create_point(char *line, int y)
{
	t_point	*point;
	char	**split;
	int		success;
	int		i;

	split = ft_split(line, ' ');
	if (!split)
		return (NULL);
	point = (t_point *)malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	success = malloc_stuff(point, split, y);
	if (!success)
		return (NULL);
	point->color = (int *)malloc(sizeof(int) * (ft_splitlen(split)));
	i = -1;
	if (!point->color)
		return (0);
	while (split[++i])
		point->color[i] = ft_atoibase(split[i], "0123456789abcdef");
	point->loop = (ft_splitlen(split) - 1);
	point->next = NULL;
	free_split(split);
	return (point);
}

// Name : add_point
// Description : add a point to the chained list
// Input : t_point *map, t_point *point
// Output : void
void	add_point(t_point *map, t_point *point)
{
	t_point	*tmp;

	tmp = map;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = point;
}

void	check_err(char *line, t_point *map, int fd)
{
	int	error;

	error = 0;
	if (!line)
	{
		ft_putstr("Error: file is empty\n");
		fdf_error(map, line, fd, 1);
	}
	error = line_check(line);
	if (error)
	{
		ft_putstr("Error: invalid character\n");
		fdf_error(map, line, fd, 1);
		exit(0);
	}
}

// Name : check_fd
// Description : check if the file descriptor is valid
// Input : int fd
// Output : void
void	check_fd(int fd, char *line, t_point *map)
{
	if (fd < 0)
	{
		ft_putstr("Error: file not found\n");
		fdf_error(map, line, fd, 1);
	}
}
