/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:14:42 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/25 14:01:59 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_data	img;
	t_point	*map;

	if (ac != 2)
	{
		ft_putstr("usage: ./fdf <filename>\n");
		return (0);
	}
	map = parser(av);
	map_to_iso(map);
	/* print_map(map); */
	/* print_likemap(map); */
	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "fdf");
	mlx.map = map;
	mlx.img	= &img;
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
