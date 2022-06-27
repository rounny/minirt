/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:40 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/27 16:10:00 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_vec3	define_color(t_scene scene, t_vec3 ro, t_vec3 rd, t_vec2 it)
{
	t_vec3	light;
	t_vec3	n;
	t_vec3	reflected;
	t_vec3	color;
	float	diffuse;
	float	specular;

	light = vec3_norm(scene.light.coordinates);
	n = vec3_norm(vec3_add(vec3_sub(ro, scene.sphere.coordinates), vec3_mulv(rd, it.x)));
	diffuse = maxf(0.0, vec3_dot(light, n));
	reflected = reflect(vec3_norm(rd), n);
	specular = powf(maxf(0.0, vec3_dot(reflected, light)), 16.0);
	color = vec3_mulv(scene.sphere.color, 0.003921568627);
	color = vec3_mulv(color, (diffuse + specular) * 0.5);
	color = vec3_add(color, vec3_mulv(vec3_mulv(scene.ambient.color, 0.003921568627), scene.ambient.lighting));
	if (color.x > 1)
		color.x = 1;
	if (color.y > 1)
		color.y = 1;
	if (color.z > 1)
		color.z = 1;
	// vec3_print("color", color); 
	return (color);
}

// return -(dot(ro,p.xyz)+p.w)/dot(rd,p.xyz);
float	draw_plane(t_vec3 ro, t_vec3 rd, t_vec3 p, float w)
{
	return (-(vec3_dot(ro, p) + w)) / vec3_dot(rd, p);	
}

t_vec3	define_color_plane(t_scene scene, t_vec3 ro, t_vec3 rd, float it)
{
	t_vec3	light;
	t_vec3	n;
	float	diffuse;
	t_vec3	color;

	light = vec3_norm(scene.light.coordinates);
	n = vec3_norm(vec3_add(vec3_sub(ro, scene.plane.coordinates), vec3_mulv(rd, it)));
	diffuse = maxf(0.0, vec3_dot(light, n));
	color = vec3_mulv(scene.plane.color, 0.003921568627);
	color = vec3_mulv(color, (diffuse) * 0.5);
	color = vec3_add(color, vec3_mulv(vec3_mulv(scene.ambient.color, 0.003921568627), scene.ambient.lighting));
	if (color.x > 1)
		color.x = 1;
	if (color.y > 1)
		color.y = 1;
	if (color.z > 1)
		color.z = 1;
	return (color);
}

t_vec3	ray_tracing(t_scene scene, t_vec3 ro, t_vec3 rd)
{
	t_vec2	it;
	float	itp;
	
	it = draw_sphere(vec3_sub(ro, scene.sphere.coordinates), rd, scene.sphere.diameter / 2);
	itp = draw_plane(vec3_sub(ro, scene.plane.coordinates), rd, scene.plane.vector, -100);
	if (it.x >= 0.0 && (it.x < itp || itp < 0))
	{
		return (define_color(scene, ro, rd, it));
	}
	else if (itp >= 0.0)
	{
		return (define_color_plane(scene, ro, rd, itp));
	}
	else
	{
		return (vec3_mulv(scene.ambient.color, 0.003921568627));
	}
}

void	draw(t_scene scene)
{
	t_vec2	pixel;
	t_vec3	direction;
	t_vec3	col;

	pixel.y = 0.0;
	while (pixel.y < HEIGHT)
	{
		pixel.x = 0.0;
		while (pixel.x < WIDTH)
		{
			direction = vec3_norm(vec3_new(WIDTH / 2 / tanf(scene.camera.fov / 2 * M_PI / 180), pixel.x - WIDTH / 2.0, pixel.y - HEIGHT / 2.0));
			col = ray_tracing(scene, scene.camera.coordinates, direction);
			write_pixel(scene.view, pixel, col);
			pixel.x += 1.0;
		}
		pixel.y += 1.0;
	}
	mlx_put_image_to_window(scene.mlx.mlx, scene.mlx.win, scene.mlx.canvas, 0, 0);
}
