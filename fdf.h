/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:14:07 by kdhrif            #+#    #+#             */
/*   Updated: 2022/11/30 20:16:39 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "mlx_linux/mlx.h"
# include <stdio.h>

// Defines the width and height of your window.
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
/* struct of the MLX img:
	- img_ptr to store the return value of mlx_new_image
	- data to store the return value of mlx_get_data_addr
	- bpp to store the return value of mlx_get_data_addr
	- size_line to store the return value of mlx_get_data_addr
	- endian to store the return value of mlx_get_data_addr
*/
typedef struct	s_data
{
	void	*img;
	char	*addr; // Here we have an int * even if the return value of mlx_get_data_addr is a char *.
	int		bpp;
	int		size_line;
	int		endian;
}				t_data;

/* struct of the MLX window:
	- mlx_ptr to store the return value of mlx_init
	- win_ptr to store the return value of mlx_new_window
	- img to store the return value of mlx_new_image
*/
typedef struct	s_win
{
	void	*mlx_ptr;
	void	*win;
	t_data	img;
}				t_mlx;

// Prototypes
void my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
