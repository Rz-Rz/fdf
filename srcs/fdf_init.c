/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:14:42 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/16 17:16:11 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_point	*map;
	t_pt *pt;
	t_pt *pt2;

	pt = malloc(sizeof(t_pt));
	pt2 = malloc(sizeof(t_pt));
	pt->x = 50;
	pt->y = 150;
	pt->color = 0x00FF0000;
	pt2->x = 100;
	pt2->y = 50;
	/* if (ac != 2) */
	/* { */
	/* 	ft_putstr("usage: ./fdf <filename>"); */
	/* 	return (0); */
	/* } */
	/* map = parser(av); */
	/* map_to_iso(map); */
	/* center_map(map); */
	/* print_map(map); */
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "fdf");
	img.img = mlx_new_image(mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bpp,
			&img.size_line, &img.endian);
	swap_pt(pt, pt2);
	which_quarter(pt, pt2);
	which_octant(pt, pt2);
	printf("dx = %d, dy = %d\n", pt2->x - pt->x, pt2->y - pt->y);
	draw_fq(pt, pt2, &img);
	/* draw_line(map, &img); */
	/* breisenham(500, 100, 100, 500, &img); */
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	free(pt);
	free(pt2);
	/* free_map(map); */
	return (0);
}

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}
