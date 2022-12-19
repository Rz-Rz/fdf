/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:14:07 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/19 22:15:39 by kdhrif           ###   ########.fr       */
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
# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000
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
	int		*x;
	int		*y;
	int		*z;
	int		color;
	int		loop;
	int		*iso_x;
	int		*iso_y;
	struct s_point	*next;
}				t_point;

typedef struct pt
{
	int		x;
	int		y;
	int		z;
	int		color;
}				t_pt;

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
/* void	breisenham(int x, int y, int x2, int y2, t_data *img); */

// debugging.c
void	print_map(t_point *map);
void	which_octant(t_pt *pt1, t_pt *pt2);
void	which_quarter(t_pt *pt1, t_pt *pt2);
void	print_likemap(t_point *map);


// ft_split
int		ft_cntwrds(char const *s, char c);
char	*ft_strdupm(char *s, char c);
char	**ft_split(char const *s, char c);

// parsing_01
int		**converter(int fd, int **map, char **tmp);
t_point	*create_point(char *line, int y);
void	add_point(t_point *map, t_point *point);
void	check_err(int fd, char *line);
t_point	*parser(char **av);

// utils_01
void	ft_putstr(char *str);
void	free_split(char **split);
int		ft_splitlen(char **split);
char	*ft_realloc(char *str, int size);
int		ft_atoi(const char *nptr);

// utils_02
void	swap_pt(t_pt *pt1, t_pt *pt2);
int	ft_abs(int n);

// line_drawing
void	convert_iso(t_point *p);
void	map_to_iso(t_point *map);
void	draw_line(t_point *map, t_data *img);
void	center_map(t_point *map);
void bresenham(int x1, int y1, int x2, int y2, t_data *data);

// octant_2
int		eighth_octant(t_pt *pt1, t_pt *pt2);
int		seventh_octant(t_pt *pt1, t_pt *pt2);
int		sixth_octant(t_pt *pt1, t_pt *pt2);

// octant_1
int		first_octant(t_pt *pt1, t_pt *pt2);
int		second_octant(t_pt *pt1, t_pt *pt2);
int		third_octant(t_pt *pt1, t_pt *pt2);
int		fourth_octant(t_pt *pt1, t_pt *pt2);
int		fifth_octant(t_pt *pt1, t_pt *pt2);

// quarter
int		first_quarter(t_pt *pt1, t_pt *pt2);
int		second_quarter(t_pt *pt1, t_pt *pt2);
int		third_quarter(t_pt *pt1, t_pt *pt2);
int		fourth_quarter(t_pt *pt1, t_pt *pt2);

// breisenham
void	two_third_octant(t_pt *pt1, t_pt *pt2, t_data *data, int direction);
void	one_fourth_octant(t_pt *pt1, t_pt *pt2, t_data *data, int direction);
void breisenham_switch(t_pt *pt1, t_pt *pt2, t_data *data);
int		direction(t_pt *pt1, t_pt *pt2);

// free_function_01
void	free_map(t_point *map);

#endif
