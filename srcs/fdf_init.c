/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:14:42 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/26 20:46:31 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_data	img;
	t_point	*map;

	if (ac != 2)
		wr_args();
	map = parser(av);
	get_maxmin_z(map);
	map_to_iso(map);
	put_vanilla(map, is_vanilla(map));
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
	{
		fdf_error(map, NULL, 0, 2);
		return (-1);
	}
	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "fdf");
	if (!mlx.win)
	{
		fdf_error(map, NULL, 0, 2);
		return (-1);
	}
	mlx.map = map;
	mlx.img = &img;
	img.img = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp,
			&img.size_line, &img.endian);
	draw_line(map, &img);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, img.img, 0, 0);
	mlx_hook(mlx.win, DESTROYNOTIFY, 0, fdf_exit, &mlx);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
