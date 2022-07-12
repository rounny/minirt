/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:40 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/13 01:10:48 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_bool	red(t_ray ray, t_vec3 origin)
{
	t_vec3	t;

	t.y = (origin.y - ray.origin.y) / ray.direction.y;
	t.z = (origin.z - ray.origin.z) / ray.direction.z;
	if ((int)t.y != (int)t.z)
	{
		return (FALSE);
	}
	// t.x = ray.origin.x + ray.direction.x * t.z;
	// if ((int)t.x != (int)t.y || (int)t.x != (int)t.z)
	// {
	// 	return (FALSE);
	// }
	return (TRUE);
}

t_bool	grean(t_ray ray, t_vec3 origin)
{
	t_vec3	t;

	t.x = (origin.x - ray.origin.x) / ray.direction.x;
	t.z = (origin.y - ray.origin.z) / ray.direction.z;
	if ((int)t.x != (int)t.z)
	{
		return (FALSE);
	}
	t.y = ray.origin.y + ray.direction.y * t.z;
	// if ((int)t.x != (int)t.y || (int)t.x != (int)t.z)
	// {
	// 	return (vec3_newv(-1.0));
	// }
	return (TRUE);
}

t_bool	blue(t_ray ray, t_vec3 origin)
{
	t_vec3	t;

	t.x = (origin.x - ray.origin.x) / ray.direction.x;
	t.y = (origin.y - ray.origin.y) / ray.direction.y;
	if ((int)t.x != (int)t.y)
	{
		return (FALSE);
	}
	t.z = ray.origin.z + ray.direction.z * t.x;
	// if ((int)t.x != (int)t.y || (int)t.x != (int)t.z)
	// {
	// 	return (vec3_newv(-1.0));
	// }
	return (TRUE);
}

t_vec3	hit_axes(t_scene scene, t_ray ray)
{
	if (red(ray, vec3_newv(0.0)) == TRUE)
	{
		return (vec3_new(1.0, 0.0, 0.0));
	}
	else if (grean(ray, vec3_newv(0.0)) == TRUE)
	{
		return (vec3_new(0.0, 1.0, 0.0));
	}
	else if (blue(ray, vec3_newv(0.0)) == TRUE)
	{
		return (vec3_new(0.0, 0.0, 1.0));
	}
	else if (scene.object.type != NIL)
	{
		t_sphere	sphere;

		sphere = *(t_sphere *)scene.object.target;
		if (scene.object.x == TRUE && red(ray, sphere.location) == TRUE)
		{
			return (vec3_new(1.0, 0.0, 0.0));
		}
		else if (scene.object.y == TRUE && grean(ray, sphere.location) == TRUE)
		{
			return (vec3_new(0.0, 1.0, 0.0));
		}
		else if (scene.object.z == TRUE && blue(ray, sphere.location) == TRUE)
		{
			return (vec3_new(0.0, 0.0, 1.0));
		}
		else
		{
			return (vec3_newv(-1.0));
		}
	}
	else
	{
		return (vec3_newv(-1.0));
	}
}

t_vec3	ray_cast(t_scene scene, t_ray ray)
{
	t_time	time;

	hit_sphere(&time, ray, scene.sphere, scene.count.sphere);

	if (time.index == -1)
	{
		return (hit_axes(scene, ray));
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
		return (vec3_new(0.1333, 0.1137, 0.1586));
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
