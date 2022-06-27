/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:37 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/27 13:33:46 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_mlx	set_mlx(void)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Mini Ray Tracing");
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

void	launch_window(t_scene *scene)
{
	scene->mlx = set_mlx();
	scene->view = set_view(scene->mlx.canvas);
	// scene.camera.location = vec3_new(-500.0, 0.0, 0.0);
	// scene.camera.rotation = vec3_new(0.0, 0.0, 0.0);
	// vec3_print("camera.lot", scene.camera.location);
	// vec3_print("camera.rot", scene.camera.rotation);
	// scene.fov = 60;
	// scene->focus = WIDTH / 2 / tanf(scene.fov / 2 * M_PI / 180); // add to draw
}
