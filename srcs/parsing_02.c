/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:34:53 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/23 19:37:28 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// Name : fdf_error
// Description : print error message and exit the program
// and free the map and the line if needed. 
// Parameters : t_data *map : the map to free
// char *line : the line to free
// Return value : void
void fdf_error(t_point *map, char *line, int fd)
{
	if (map)
		free_map(map);
	if (line)
		free(line);
	close(fd);
}
