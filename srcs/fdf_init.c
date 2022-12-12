/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:14:42 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/11 18:57:14 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int ac, char **av)
{
				void	*mlx;
				void	*mlx_win;
				t_data	img;
				t_point *map;

				if (ac != 2)
				{
								ft_putstr("usage: ./fdf <filename>");
								return (0);
				}
				map = parser(av);
				map_to_iso(map);
				center_map(map);
				print_map(map);
				mlx = mlx_init();
				mlx_win = mlx_new_window(mlx, 1920, 1080, "fdf");
				img.img = mlx_new_image(mlx, 1920, 1080);
				img.addr = mlx_get_data_addr(img.img, &img.bpp,
						&img.size_line, &img.endian);
				draw_line(map, &img);
				breisenham(500, 100, 100, 500, &img);
				mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
				mlx_loop(mlx);
				free_map(map);
				return (0);
}

void	pixel_put(t_data *data, int x, int y, int color)
{
				char	*dst;

				dst = data->addr + (y * data->size_line + x * (data->bpp / 8));
				*(unsigned int *)dst = color;
}

