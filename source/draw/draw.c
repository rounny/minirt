/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:40 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/15 11:24:06 by ccamie           ###   ########.fr       */
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
#include <sys/time.h>

struct s_thread
{
	t_scene	*scene;
	int		i;
};

typedef struct s_thread	t_thread;

#define TH_KERL	8


void	*lol(void *pointer)
{
	t_thread	kek;
	struct timeval	temp;
	long			time1;
	t_scene		scene;
	int			i;
	struct timeval	temp2;
	long			time2;
	
	gettimeofday(&temp, NULL);
	time1 = temp.tv_sec * 1000 + temp.tv_usec / 1000;
	kek = *(t_thread *)pointer;
	scene = *kek.scene;
	i = kek.i;
	_draw(scene, vec2_new(WIDTH / TH_KERL * i, 0), vec2_new(WIDTH / TH_KERL * (i + 1), HEIGHT));
	gettimeofday(&temp2, NULL);
	time2 = temp2.tv_sec * 1000 + temp2.tv_usec / 1000;
	printf("%d: %ld\n", i, time2 - time1);
	return (NULL);
}

void	draw(t_scene scene)
{
	pthread_t			thread[TH_KERL];
	pthread_attr_t		tattr;
	t_thread			kek[TH_KERL];
	struct sched_param	param;
	int			i;

		// pthread_attr_getschedparam();
	i = 0;
	pthread_attr_init(&tattr);
	pthread_attr_setscope(&tattr, PTHREAD_SCOPE_PROCESS);
	pthread_attr_setdetachstate(&tattr, PTHREAD_CREATE_JOINABLE);
	pthread_attr_setinheritsched(&tattr, PTHREAD_EXPLICIT_SCHED);
	pthread_attr_setschedpolicy(&tattr, SCHED_OTHER);
	param.sched_priority = 1000000;
	pthread_attr_setschedparam(&tattr, &param);
	while (i < TH_KERL)
	{
		kek[i].i = i;
		kek[i].scene = &scene;
		
		pthread_create(&thread[i], &tattr, lol, &kek[i]);
		i += 1;
	}
	pthread_attr_destroy(&tattr);
	i = 0;
	while (i < TH_KERL)
	{
		pthread_join(thread[i], NULL);
		i += 1;
	}
	printf("-----\n");
	mlx_put_image_to_window(scene.mlx.mlx, scene.mlx.win, scene.mlx.canvas, 0, 0);
}
