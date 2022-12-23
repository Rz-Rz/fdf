/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:14:07 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/23 18:04:07 by kdhrif           ###   ########.fr       */
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
# define WIN_WIDTH 2000
# define WIN_HEIGHT 1500

// mlx keycode 
# define KEYPRESS 2
# define KEYRELEASE 3
# define BUTTONPRESS 4
# define BUTTONRELEASE 5
# define MOTIONNOTIFY 6
# define ENTERNOTIFY 7
# define LEAVENOTIFY 8
# define FOCUSIN 9
# define FOCUSOUT 10
# define KEYMAPNOTIFY 11
# define EXPOSE 12
# define GRAPHICSEXPOSE 13
# define NOEXPOSE 14
# define VISIBILITYNOTIFY 15
# define CREATENOTIFY 16
# define DESTROYNOTIFY 17
# define UNMAPNOTIFY 18
# define MAPNOTIFY 19
# define MAPREQUEST 20
# define REPARENTNOTIFY 21
# define CONFIGURENOTIFY 22
# define CONFIGUREREQUEST 23
# define GRAVITYNOTIFY 24


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
	struct	s_point	*next;
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
	t_point *map;
	t_data	*img;
}				t_mlx;

// Prototypes
void	pixel_put(t_data *data, int x, int y, int color);
/* void	breisenham(int x, int y, int x2, int y2, t_data *img); */

// debugging.c
void	print_map(t_point *map);
void	which_octant(t_pt *pt1, t_pt *pt2);
void	which_quarter(t_pt *pt1, t_pt *pt2);
void	print_likemap(t_point *map);

// hooks.c
int		key_hook(int keycode, t_mlx *vars);

// ft_split
int		ft_cntwrds(char const *s, char c);
char	*ft_strdupm(char *s, char c);
char	**ft_split(char const *s, char c);

// parsing_01
int		**converter(int fd, int **map, char **tmp);
t_point	*create_point(char *line, int y);
void	add_point(t_point *map, t_point *point);
void	check_err(char *line, t_point *map, int fd);
t_point	*parser(char **av);

// parsing_02
void	check_fd(int fd, char *line, t_point *map);

// utils_01
void	ft_putstr(char *str);
void	free_split(char **split);
int		ft_splitlen(char **split);
char	*ft_realloc(char *str, int size);
int		ft_atoi(const char *nptr);

// utils_02
void	swap_pt(t_pt *pt1, t_pt *pt2);
int		ft_abs(int n);
int		ft_isdigit(int c);
int		ft_isalphanumeric(int c);
int		ft_isalpha(int c);

// line_drawing
void	convert_iso(t_point *p);
void	map_to_iso(t_point *map);
void	draw_line(t_point *map, t_data *img);
void	center_map(t_point *map);

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

// breisenham_01
void	two_third_octant(t_pt *pt1, t_pt *pt2, t_data *data, int direction);
void	one_fourth_octant(t_pt *pt1, t_pt *pt2, t_data *data, int direction);
void	breisenham_switch(t_pt *pt1, t_pt *pt2, t_data *data);
int		direction(t_pt *pt1, t_pt *pt2);

// breisenham_02
void	brei_sw_norm(t_pt *pt1, t_pt *pt2, t_data *data, int dir);

// free_function_01
void	free_map(t_point *map);
int		fdf_exit(t_mlx *mlx);

// lineclip 
int		region_code(t_pt *pt);
void	lineclip(t_pt *pt1, t_pt *pt2, t_data *data);

// error
int		line_check(char *line);
int		ft_count_numbers(char *line);
void	fdf_error(t_point *map, char *line, int fd);

#endif
