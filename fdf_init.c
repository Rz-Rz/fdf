/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:14:42 by kdhrif            #+#    #+#             */
/*   Updated: 2022/11/30 20:19:37 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
				void *mlx;
				void *mlx_win;
				t_data img;

				mlx = mlx_init();
				mlx_win = mlx_new_window(mlx, 1920, 1080, "fdf");
				img.img = mlx_new_image(mlx, 1920, 1080);
				img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.size_line, &img.endian);
				my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
				mlx_put_image_to_window(mlx,  mlx_win, img.img, 0, 0);
				mlx_loop(mlx);
				return (0);
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
				char *dst;

				dst = data->addr + (y * data->size_line + x * (data->bpp / 8));
				*(unsigned int*)dst = color;
}
