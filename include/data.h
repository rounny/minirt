/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnvtosh <ivnvtosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:15:04 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/09 18:26:56 by ivnvtosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "bool.h"
# include "matrix.h"
# include "vec2.h"
# include "vec3.h"

enum e_type
{
	NIL,
	SPHERE,
	PLANE,
	CYLINDER,
};

typedef int	t_type;

struct s_view
{
	char	*buffer;
	int		pixel;
	int		line;
	int		endian;
};

struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*canvas;
};

struct s_amb // полное название
{	
	t_vec3	color; // change rgb to color
	float	lighting; // am_l to lightng
	int		flag_A;
};

struct s_cam
{
	int flag_C;
	t_vec3	location;
	t_vec3	rotation;
	int		fov;
	float	focus;
};

struct s_light
{
	int		flag_L;
	t_vec3	location;
	t_vec3	color;
	float	intensity;
};

struct s_pln
{
	int		flag_pl;
	t_vec3	location;
	t_vec3	vector;
	t_vec3	color;
};

struct s_sphere
{
	t_vec3	location;
	t_vec3	rotation;
	t_vec3	scale;
	t_vec3	color;
	float	radius;
	t_vec2	time;
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

struct s_count
{
	int sphere;
	int	i_sph;
	int	plane;
	int	i_pln;
	int	cylinder;
	int	i_clnd;
};

struct s_object
{
	int		type;
	void	*target;
};

struct s_scene
{
	int 			fd;
	int				count_argc;
	int				count_line;
	int				flag_line;
	struct s_view	view;
	struct s_mlx	mlx;
	struct s_cam	camera;
	struct s_count	count;
	struct s_amb	ambient;
	struct s_light	light;
	struct s_sphere	*sphere;
	struct s_pln	*plane;
	struct s_clnd	*cylinder;
	struct s_vec2	mouse;
	struct s_object	object;
	t_bool			move;
	t_bool			pressed;
	t_mat			matrix;
	int				block;
	t_bool			smooth;
};

typedef struct s_amb	t_amb;
typedef struct s_view	t_view;
typedef struct s_mlx	t_mlx;
typedef struct s_cam	t_cam;
typedef struct s_count	t_count;
typedef struct s_pln	t_pln;
typedef struct s_sphere	t_sphere;
typedef struct s_clnd	t_clnd;
typedef struct s_light	t_light;
typedef struct s_object	t_object;
typedef struct s_scene	t_scene;

#endif // DATA_H
