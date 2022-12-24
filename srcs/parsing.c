/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:29:42 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/24 21:15:34 by kdhrif           ###   ########.fr       */
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
	int		fl_num;
	int 	y;

	y = -1;
	map = NULL;
	line = NULL;
	fd = open(av[1], O_RDONLY);
	check_fd(fd, line, map);
	line = get_next_line(fd);
	fl_num = ft_count_numbers(line);
	while (line)
	{
		check_err(line, map, fd);
		y++;
		tmp = create_point(line, y);
		if (tmp == NULL)
		{
			free_map(map, 1);
			return (NULL);
		}
		if (!map)
			map = tmp;
		else
			add_point(map, tmp);
		if (fl_num != ft_count_numbers(line))
		{
			ft_putstr("Error: Invalid map\n");
			fdf_error(map, line, fd, 1);
		}
		free(line);
		line = get_next_line(fd);
	}
	fd = close(fd);
	if (fd)
	{
		free_map(map, 1);
		return (NULL);
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
	if (!split)
		return (NULL);
	point = (t_point *)malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	point->loop = (ft_splitlen(split) - 1);
	point->x = (int *)malloc(sizeof(int) * (ft_splitlen(split)));
	if (!point->x)
		return (NULL);
	i = -1;
	while (split[++i])
					point->x[i] = i;
	point->z = (int *)malloc(sizeof(int) * (ft_splitlen(split)));
	if (!point->z)
		return (NULL);
	i = -1;
	while (split[++i])
		point->z[i] = y;
	point->y = (int *)malloc(sizeof(int) * (ft_splitlen(split)));
	if (!point->y)
		return (NULL);
	i = -1;
	while (split[++i])
		point->y[i] = ft_atoi(split[i]);
	i = -1;
	point->color = (int *)malloc(sizeof(int) * (ft_splitlen(split)));
	if (!point->color)
		return (NULL);
	while (split[++i])
		point->color[i] = ft_atoibase(split[i], "0123456789abcdef");
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

void check_err(char *line, t_point *map, int fd)
{
	int error;
	int loop;

	error = 0;
	if (!line)
	{
		ft_putstr("Error: file is empty\n");
		fdf_error(map, line, fd, 1);
	}
	error = line_check(line);
	if (error)
	{
		printf("Error: line %d is not valid\n", error);
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

// Name: line_check
// Description: check if the line is valid:
// to be valid it must no be empty
// it must have the same number of numbers as the first line
// it must contain only numbers, letters, commas and space
// Input: char *line
// Output: int (0 if valid, 1 if not)
int	line_check(char *line)
{
	int i;

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
	int i;
	int count;

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

// Name: parse_hex
// Description: parse a hex color
// Input: char *hex
// Output: int (the color)




void init_struct(t_point *point)
{
    point->x = NULL;
    point->y = NULL;
    point->z = NULL;
    point->color = 0;
    point->loop = 0;
    point->iso_x = NULL;
    point->iso_y = NULL;
    point->next = NULL;
}

