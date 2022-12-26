/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:34:53 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/26 12:17:45 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// Name : fdf_error
// Description : print error message and exit the program
// and free the map and the line if needed. 
// Parameters : t_data *map : the map to free
// char *line : the line to free
// Return value : void
void	fdf_error(t_point *map, char *line, int fd, int stage)
{
	if (map)
		free_map(map, stage);
	if (line)
		free(line);
	if (fd != -1)
		close(fd);
	exit(0);
}

void	map_add(t_point **map, char *line, int y)
{
	t_point	*tmp;

	tmp = create_point(line, y);
	if (tmp == NULL)
	{
		free_map(*map, 1);
		return ;
	}
	if (!*map)
		*map = tmp;
	else
		add_point(*map, tmp);
}

void	fd_done(int fd, t_point *map)
{
	fd = close(fd);
	if (fd)
	{
		free_map(map, 1);
		return ;
	}
}

void	generic_err(t_point *map, char *line, int fd)
{
	ft_putstr("Error: Invalid map\n");
	fdf_error(map, line, fd, 1);
}
