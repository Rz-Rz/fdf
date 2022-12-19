/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:29:42 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/19 22:25:11 by kdhrif           ###   ########.fr       */
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
	t_point	*tmp;
	int y;

	y = -1;
	map = NULL;
	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	check_err(fd, line);
	while (line)
	{
					y++;
					tmp = create_point(line, y);
					if (!map)
									map = tmp;
					else
									add_point(map, tmp);
					free(line);
					line = get_next_line(fd);
	}
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
	int		i;

	split = ft_split(line, ' ');
	point = (t_point *)malloc(sizeof(t_point));
	point->loop = (ft_splitlen(split) - 1);
	point->x = (int *)malloc(sizeof(int) * (ft_splitlen(split)));
	i = -1;
	while (split[++i])
					point->x[i] = i;
	point->z = (int *)malloc(sizeof(int) * (ft_splitlen(split)));
	i = -1;
	while (split[++i])
		point->z[i] = y;
	point->y = (int *)malloc(sizeof(int) * (ft_splitlen(split)));
	point->next = NULL;
	i = -1;
	while (split[++i])
		point->y[i] = ft_atoi(split[i]) ;
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

void check_err(int fd, char *line)
{
	if (fd == -1)
	{
		ft_putstr("Error: file not found");
		exit(0);
	}
	if (!line)
	{
		ft_putstr("Error: file is empty");
		exit(0);
	}
}
