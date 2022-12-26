/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:14:07 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/26 11:44:32 by kdhrif           ###   ########.fr       */
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

typedef struct s_clip
{
	int		code1;
	int		code2;
	int		accept;
	int		done;
	int		code_out;
}				t_clip;

typedef struct s_point
{
	int		*x;
	int		*y;
	int		*z;
	int		*color;
	int		loop;
	int		*iso_x;
	int		*iso_y;
	int		size_x;
	int		size_y;
	int		size_p;
	struct s_point	*next;
}				t_point;

typedef struct pt
{
	int		x;
	int		y;
	int		z;
	int		color;
}				t_pt;

typedef struct line
{
	t_pt	*p1;
	t_pt	*p2;
}				t_line;

/* struct of the MLX window:
	- mlx_ptr to store the return value of mlx_init
	- win_ptr to store the return value of mlx_new_window
	- img to store the return value of mlx_new_image
*/
typedef struct s_win
{
	void	*mlx_ptr;
	int		fl_num;
	int		size;
	void	*win;
	t_point	*map;
	t_data	*img;
}				t_mlx;

// Prototypes
void	pixel_put(t_data *data, int x, int y, int color);
/* void	breisenham(int x, int y, int x2, int y2, t_data *img); */

// data.c 
void	get_map_size(t_point *map);
int		get_pad(t_point *p);
void	put_pad(t_point *p);

// line_draw_norm.c
void	pt_map(t_pt *pt, t_point *map, int i);
void	pm_clip(t_line *line, t_point *map, t_data *img, int i);
void	pt_pt(t_pt *pt1, t_pt *pt2);

// maths.c
int		get_dy(t_pt *start, t_pt *end);
int		get_dx(t_pt *start, t_pt *end);
int		get_slope(t_pt start, t_pt end);

// color.c
int		get_color(t_pt *current, t_pt *start, t_pt *end);

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
t_point	*parser(char **av, t_mlx *mlx);

// parsing_02
void	check_fd(int fd, char *line, t_point *map);
void	map_add(t_point **map, char *line, int y);
void	fd_done(int fd, t_point *map);
void	generic_err(t_point *map, char *line, int fd);

// parsing_03
int		malloc_stuff(t_point *point, char **split, int y);

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

// utils_03 
int		ft_lstsize(t_point *p);
int		ft_strlen(char *str);
int		ft_atoibase(char *str, char *base);
int		atoibase_plus(char *str);

// line_drawing
void	convert_iso(t_point *p);
void	map_to_iso(t_point *map);
void	draw_line(t_point *map, t_data *img);
void	draw_line_n(t_line *line, t_point *map, t_point *lower, t_data *img);

// breisenham_01
void	two_third_octant(t_pt *pt1, t_pt *pt2, t_data *data, int direction);
void	one_fourth_octant(t_pt *pt1, t_pt *pt2, t_data *data, int direction);
void	breisenham_switch(t_pt *pt1, t_pt *pt2, t_data *data);
int		direction(t_pt *pt1, t_pt *pt2);

// breisenham_02
void	brei_sw_norm(t_pt *pt1, t_pt *pt2, t_data *data, int dir);

// free_function_01
void	free_map(t_point *map, int stage);
int		fdf_exit(t_mlx *mlx);

// lineclip.c 
int		region_code(t_pt *pt);
void	lineclip(t_line *line, t_data *data);
void	clip_plus(t_clip clip, t_pt *pt1, t_pt *pt2);
void	more_clip(t_clip clip, t_pt *pt1, t_pt *pt2, t_pt *tmp);

// error
int		line_check(char *line);
int		ft_count_numbers(char *line);
void	fdf_error(t_point *map, char *line, int fd, int stage);

#endif
