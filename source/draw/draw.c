/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:40 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/18 15:09:39 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_bool	is_path_free(t_scene scene, t_ray ray, t_vec3 light)
{
	t_time	time;
	t_vec3	at;
	float	t;

	time.index = -1;
	time.time = __INT_MAX__;
	hit_sphere(&time, ray, scene.sphere, scene.count.sphere);
	at = vec3_div(vec3_sub(light, ray.origin), ray.direction);
	t = at.y;
	// // t = vec3_len(at);
	if (time.time < 0.0 || time.time > t)
	{
		return (TRUE);
	}
	else 
	{
		return (FALSE);
	}
}

t_vec3	reflect(t_vec3 rd, t_vec3 n)
{
	return (vec3_sub(rd, vec3_mulv(vec3_mulv(n, vec3_dot(n, rd)), 2.0)));
}

// float	draw_plane(t_ray ray, t_vec3 center, t_vec3 vector)
// {
// 	(void)vector;
// 	return (-(vec3_dot(ray.origin, center))) / vec3_dot(ray.direction, center);
// }

float	draw_plane(t_ray ray, t_vec3 center, t_vec3 vector)
{
	// (void)vector;
	(void)center;
	return (-(vec3_dot(ray.origin, vector))) / vec3_dot(ray.direction, vector);
}

static int	get_min_index(t_pln *planes, int count)
{
	float	min;
	int		i;
	int		index;

	min = __INT_MAX__;
	index = -1;
	i = 0;
	while (i < count)
	{
		if (planes[i].time >= 0 && planes[i].time < min)
		{
			min = planes[i].time;
			index = i;
		}
		i += 1;
	}
	return (index);
}

void	hit_plane(t_time *time, t_ray ray, t_pln *planes, int count)
{
	int		index;
	int		i;

	i = 0;
	while (i < count)
	{
		planes[i].time = draw_plane(ray, planes[i].location, \
													planes[i].vector);
		i += 1;
	}
	index = get_min_index(planes, count);
	if (index == -1)
	{
		return ;
	}
	if (planes[index].time < time->time)
	{
		time->index = index;
		time->time = planes[index].time;
		time->type = PLANE;
	}
}

t_vec3	ray_cast(t_scene scene, t_ray ray)
{
	t_time	time;

	time.index = -1;
	time.time = __INT_MAX__;
	hit_axes(&time, scene, ray);
	hit_sphere(&time, ray, scene.sphere, scene.count.sphere);
	hit_plane(&time, ray, scene.plane, scene.count.plane);
	if (time.index == -1)
	{
		return (vec3_newv(-1.0));
	}

	t_vec3	allcolor;
	t_vec3	color;


	allcolor = vec3_newv(0.0);
	if (time.type == SPHERE)
	{
		color = scene.sphere[time.index].color;
		t_ray	newray;
		int		i;

		i = 0;
		allcolor = vec3_add(allcolor, vec3_mul(scene.sphere[time.index].color, vec3_mulv(scene.ambient.color, scene.ambient.lighting)));
		while (i < scene.count.light)
		{
			color = scene.sphere[time.index].color;
			newray.origin = ray_pos(ray, time.time);
			newray.direction = vec3_norm(vec3_sub(scene.light[i].location, newray.origin));

			if (is_path_free(scene, newray, scene.light[i].location) == FALSE)
			{	
				i += 1;
				continue;
			}

			t_vec3	normal;
			t_vec3	diffuse;
			t_vec3	reflected;
			t_vec3	specular;

			normal = vec3_norm(vec3_add(vec3_sub(ray.origin, scene.sphere[time.index].location), vec3_mulv(ray.direction, time.time)));

			reflected = reflect(ray.direction, normal);
			reflected = vec3_mapv(vec3_mulv(scene.light[i].color, vec3_dot(newray.direction, reflected)), 0.0, maxf);
			specular = vec3_mapv(reflected, 16.0, powf);
			diffuse = vec3_mapv(vec3_mulv(scene.light[i].color, vec3_dot(newray.direction, normal)), 0.0, maxf);
			color = vec3_mulv(vec3_mul(color, diffuse), scene.light[i].intensity);
			color = vec3_add(color, specular);
			color = vec3_add(color, vec3_mul(color, specular));

			allcolor = vec3_add(allcolor, color);
			i += 1;
		}

	}
	else if (time.type == LINE)
	{
		if (time.index == 0)
		{
			return (vec3_new(0.8, 0.2, 0.2));
		}
		if (time.index == 1)
		{
			return (vec3_new(0.2, 0.8, 0.2));
		}
		if (time.index == 2)
		{
			return (vec3_new(0.2, 0.2, 0.8));
		}
	}
	else if (time.type == PLANE)
	{
		color = scene.plane[time.index].color;
		allcolor = vec3_add(allcolor, vec3_mul(color, vec3_mulv(scene.ambient.color, scene.ambient.lighting)));
	}

	return (allcolor);
}

t_vec3	ray_trace(t_scene scene, t_ray ray)
{
	t_vec3	color;

	color = ray_cast(scene, ray);
	if (color.x == -1.0 && color.y == -1.0 && color.z == -1.0)
	{
		return (vec3_new(0.1333, 0.1137, 0.1586));
	}
	color = color_trim(color);
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
			ray = ray_new(pixel, scene.camera, scene.option.matrix);
			color = ray_trace(scene, ray);
			write_pixels(scene.view, pixel, color, scene.option.block);
			pixel.x += scene.option.block;
		}
		pixel.y += scene.option.block;
	}
}

void	draw(t_scene scene)
{
	_draw(scene);
	mlx_put_image_to_window(scene.mlx.mlx, scene.mlx.win, scene.mlx.canvas, 0, 0);
}
