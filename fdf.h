/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:14:07 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/08 18:25:06 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "mlx_linux/mlx.h"
# include "srcs/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

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
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}				t_data;


typedef struct s_point
{
	int*		x;
	int		y;
	int*		z;
	int		color;
	int loop;
	void *next;
}				t_point;

/* struct of the MLX window:
	- mlx_ptr to store the return value of mlx_init
	- win_ptr to store the return value of mlx_new_window
	- img to store the return value of mlx_new_image
*/
typedef struct s_win
{
	void	*mlx_ptr;
	void	*win;
	t_data	img;
}				t_mlx;

// Prototypes
void	pixel_put(t_data *data, int x, int y, int color);
void	bresenham(int x, int y, int x2, int y2, t_data *img);

// debugging.c
void	print_map(t_point *map);

// ft_split
int		ft_cntwrds(char const *s, char c);
char	*ft_strdupm(char *s, char c);
char	**ft_split(char const *s, char c);

// parsing_01
int	**converter(int fd, int **map, char **tmp);
t_point	*create_point(char *line);
void	add_point(t_point *map, t_point *point);
void check_err(int fd, char *line);
t_point	*parser(char **av);

// utils_01
void	ft_putstr(char *str);
void	free_split(char **split);
int	ft_splitlen(char **split);
char	*ft_realloc(char *str, int size);
int		ft_atoi(const char *nptr);

#endif
