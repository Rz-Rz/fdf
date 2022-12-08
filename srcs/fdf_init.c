/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:14:42 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/08 18:50:51 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int ac, char **av)
{
				/* void	*mlx; */
				/* void	*mlx_win; */
				/* t_data	img; */
				t_point *map;

				if (ac != 2)
								ft_putstr("usage: ./fdf <filename>");
				map = parser(av);
				/* mlx = mlx_init(); */
				/* mlx_win = mlx_new_window(mlx, 1920, 1080, "fdf"); */
				/* img.img = mlx_new_image(mlx, 1920, 1080); */
				/* img.addr = mlx_get_data_addr(img.img, &img.bpp, */
				/* 		&img.size_line, &img.endian); */
				/* bresenham(50, 100, 400, 400, &img); */
				/* mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0); */
				/* mlx_loop(mlx); */
				return (0);
}

void	pixel_put(t_data *data, int x, int y, int color)
{
				char	*dst;

				dst = data->addr + (y * data->size_line + x * (data->bpp / 8));
				*(unsigned int *)dst = color;
}

void	bresenham(int x, int y, int x2, int y2, t_data *img)
{
				int	p;
				int	dx;
				int	dy;

				dx = x2 - x;
				dy = y2 - y;
				p = 2 * dy - dx;
				while (x <= x2)
				{
								pixel_put(img, x, y, 0x00FF0000);
								x++;
								if (p < 0)
												p = p + 2 * dy;
								else
								{
												p = p + 2 * dy - 2 * dx;
												y++;
								}
				}
}
