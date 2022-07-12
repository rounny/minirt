/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:19 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/12 08:01:23 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_mlx	set_mlx(void)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Mini Ray Tracer");
	mlx.canvas = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	return (mlx);
}

t_view	set_view(void *canvas)
{
	t_view	view;
	int		pixel;
	int		line;
	int		endian;

	view.buffer = mlx_get_data_addr(canvas, &pixel, &line, &endian);
	view.pixel = pixel;
	view.line = line;
	view.endian = endian;
	return (view);
}

void	set_options(t_scene *scene)
{
	scene->camera.rotation = vec3_new(0.0, 26.0, 152.0);
	matrix_new(scene->option.matrix);
	matrix_rotate(scene->option.matrix, scene->camera.rotation);
	scene->option.smooth = FALSE;
	scene->option.block = 1;
	scene->press.key.direction = vec3_newv(0.0);
	scene->press.key.action = FALSE;
	scene->press.mouse.action = FALSE;
	scene->press.key.count = 0;
	scene->camera.fov = 60;
}

void	minirt(char *path)
{
	t_scene	scene;

	scene = (t_scene){};
	check_options(path, &scene);
	parsing(&scene);
	set_options(&scene);
	scene.mlx = set_mlx();
	scene.view = set_view(scene.mlx.canvas);
	draw(scene);
	event(&scene);
}
