/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:40 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/13 22:02:38 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_vec3	ray_cast(t_scene scene, t_ray ray)
{
	t_time	time;

	time.index = -1;
	time.time = __INT_MAX__;
	hit_sphere(&time, ray, scene.sphere, scene.count.sphere);
	hit_axes(&time, scene, ray);

	if (time.index == -1)
	{
		return (vec3_newv(-1.0));
	}

	t_vec3	color;
	// t_vec3	normal;

	// color = vec3_newv(-1.0);
	if (time.type == SPHERE)
	{
		color = scene.sphere[time.index].color;
	}
	if (time.type == LINE)
	{
		if (time.index == 0)
		{
			return (vec3_new(1.0, 0.0, 0.0));
		}
		if (time.index == 1)
		{
			return (vec3_new(0.0, 1.0, 0.0));
		}
		if (time.index == 2)
		{
			return (vec3_new(0.0, 0.0, 1.0));
		}
	}
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

void	_draw(t_scene scene, t_vec2 start, t_vec2 end)
{
	t_ray	ray;
	t_vec3	color;
	t_vec2	pixel;

	pixel.y = start.y;
	while (pixel.y < end.y)
	{
		pixel.x = start.x;
		while  (pixel.x < end.x)
		{
			ray = ray_new(pixel, scene.camera, scene.option.matrix);
			color = ray_trace(scene, ray);
			write_pixels(scene.view, pixel, color, scene.option.block);
			pixel.x += scene.option.block;
		}
		pixel.y += scene.option.block;
	}
}

#include <pthread.h>

struct s_thread
{
	t_scene	*scene;
	int		i;
};

typedef struct s_thread	t_thread;

#define TH_KERL	4

void	*lol(void *pointer)
{
	t_thread	kek;
	t_scene		scene;
	int			i;

	kek = *(t_thread *)pointer;
	scene = *kek.scene;
	i = kek.i;
	_draw(scene, vec2_new(WIDTH / TH_KERL * i, 0), vec2_new(WIDTH / TH_KERL * (i + 1), HEIGHT));
	return (NULL);
}

void	draw(t_scene scene)
{
	pthread_t	thread[TH_KERL];
	t_thread	kek[TH_KERL];
	int			i;

	i = 0;
	while (i < TH_KERL)
	{
		kek[i].i = i;
		kek[i].scene = &scene;
		pthread_create(&thread[i], NULL, lol, &kek[i]);
		i += 1;
	}
	i = 0;
	while (i < TH_KERL)
	{
		pthread_join(thread[i], NULL);
		i += 1;
	}
	mlx_put_image_to_window(scene.mlx.mlx, scene.mlx.win, scene.mlx.canvas, 0, 0);
}
