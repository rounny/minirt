/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnvtosh <ivnvtosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:40 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/09 19:16:25 by ivnvtosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_vec3	ray_cast(t_scene scene, t_ray ray)
{
	t_time	time;

	hit_sphere(&time, ray, scene.sphere, scene.count.sphere);

	if (time.index == -1)
	{
		return (vec3_newv(-1.0));
	}

	t_vec3	color;
	// t_vec3	normal;

	color = scene.sphere[time.index].color;
	// normal = vec3_norm(vec3_add(vec3_sub(ray.origin, scene.sphere[time.index].location), vec3_mulv(ray.direction, time.time)));
	return (color);
}

t_vec3	ray_trace(t_scene scene, t_ray ray)
{
	t_vec3	color;

	color = ray_cast(scene, ray);
	if (color.x == -1.0 && color.y == -1.0 && color.z == -1.0)
	{
		return (vec3_newv(1.0));
	}
	return (color);
}

void	_draw(t_scene scene)
{
	t_ray	ray;
	t_vec3	color;
	t_vec2	pixel;


	pixel.y = 0;
	while (pixel.y < HEIGHT)
	{
		pixel.x = 0;
		while  (pixel.x < WIDTH)
		{
			ray = ray_new(pixel, scene.camera, scene.matrix);
			color = ray_trace(scene, ray);
			write_pixels(scene.view, pixel, color, scene.block);
			pixel.x += scene.block;
		}
		pixel.y += scene.block;
	}
}

void	draw(t_scene scene)
{
	_draw(scene);
	mlx_put_image_to_window(scene.mlx.mlx, scene.mlx.win, scene.mlx.canvas, 0, 0);
}
