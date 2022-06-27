/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:16:15 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/27 13:36:58 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WIDTH	1080
# define HEIGHT	720
// libft
// # include "./libft/libft.h" // 
// mlx
# include "mlx.h"
# include "vec3.h"
# include "vec2.h"
// printf
# include <stdio.h>
// exit
# include <stdlib.h>
// open
# include <fcntl.h>
// read
#include <unistd.h>

typedef struct s_scene	t_scene;
typedef struct s_view	t_view;
typedef struct s_clnd	t_clnd;
typedef struct s_pln	t_pln;
typedef struct s_sph	t_sph;
typedef struct s_lgt	t_lgt;
typedef struct s_cam	t_cam;
typedef struct s_amb	t_amb;
typedef struct s_mlx	t_mlx;
typedef struct s_vec3 	t_vec3;

struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*canvas;
};

struct s_amb // полное название
{	
	int		flag_A;
	float	lighting; // am_l to lightng
	t_vec3	color; // change rgb to color
};

struct s_cam
{
	int		flag_C;
	int		fov; // INT or FLOAT
	t_vec3	coordinates;
	t_vec3	vector;

};

struct s_lgt
{
	int		flag_L;
	float	bright;
	t_vec3	color;
	t_vec3	coordinates;
};

struct s_sph
{
	int		flag_sp;
	float	diameter;
	t_vec3	coordinates;
	t_vec3	color;

};

struct s_pln
{
	int		flag_pl;
	t_vec3	coordinates;
	t_vec3	vector;
	t_vec3	color;
};

struct s_clnd
{
	int		flag_cy;
	float	diameter;
	float	height;
	t_vec3	coordinates;
	t_vec3	vector;
	t_vec3	color;
};

struct s_view
{
	char	*buffer;
	int		pixel;
	int		line;
	int		endian;
};

struct s_scene
{
	int		fd;
	int		count_argc;
	int		count_line;
	int		flag_line;
	t_amb	ambient;
	t_cam	camera;
	t_lgt	light;
	t_sph	sphere;
	t_pln	plane;
	t_clnd	cylinder;
	t_mlx	mlx;
	t_view	view;
};

typedef struct s_scene	t_scene;
typedef struct s_view	t_view;
typedef struct s_clnd	t_clnd;
typedef struct s_pln	t_pln;
typedef struct s_sph	t_sph;
typedef struct s_lgt	t_lgt;
typedef struct s_cam	t_cam;
typedef struct s_amb	t_amb;
typedef struct s_mlx	t_mlx;

size_t	ft_strlen2(const char *str); //DELETE IN MAC 

void	ft_error(char *msg);
int		check_extention(char *s);
void	check_options(int ac, char **av, t_scene *scene);

void	parsing(t_scene *scene);
// void	parse_camera(t_rt *opt);
void	parse_camera(char *str, t_scene *scene);
void	parse_ambient_lightning(char *str, t_scene *scene);
// void	parse_ambient_lightning(char *str, t_amb *ambient);
// void	parse_ambient_lightning(t_rt *opt);
// void	parse_light(t_rt *opt);
void	parse_light(char *str, t_scene *scene);
void	parse_sphere(char *str, t_scene *scene);
void	parse_plane(char *str, t_scene *scene);
void	parse_cylinder(char *str, t_scene	*scene);

char	*ft_chrjoin(char *s1, char s2);
char	**get_line_file(int fd, t_scene *scene);

char	**ft_split_rt(char const *s, char c, t_scene *scene);
int		ft_atoi_rt(const char *str);
int		ft_atoi2(const char *str);
float	ft_atof(char *str, int *i);

t_vec3	parsing_color(char *str, int i, t_scene *scene);
t_vec3 parse_xyz(char *str, int *i);

void	count_separator(char *str, int *i, int *sep);
void	check_next_element(char *str, int i);
void	check_next_space(char *str, int *i);
void	check_digit(char *str, int i);
void	check_vector(t_vec3 vector);

void	launch_window(t_scene *scene);
float	maxf(float a, float b);
void	draw(t_scene scene);

#endif // MINIRT_H
