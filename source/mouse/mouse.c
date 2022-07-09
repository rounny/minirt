/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnvtosh <ivnvtosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 06:36:49 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/09 18:04:34 by ivnvtosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mouse.h"
#include "draw.h"

static int	mouse_rotate(int x, int y, t_scene *scene)
{
	scene->move = TRUE;
	scene->camera.rotation.z -= (x - scene->mouse.x) * 0.1;
	scene->camera.rotation.y += (y - scene->mouse.y) * 0.1;
	scene->mouse.x = x;
	scene->mouse.y = y;
	matrix_new(scene->matrix);
	matrix_rotate(scene->matrix, scene->camera.rotation);
	draw(*scene);
	return (0);
}

int	mouse_pressed(int key, int x, int y, t_scene *scene)
{
	scene->mouse.x = x;
	scene->mouse.y = y;
	scene->move = FALSE;
	if (key == MOUSE_CLICK_LEFT)
	{
		mlx_hook(scene->mlx.win, 6, 0, mouse_rotate, scene);
	}
	return (0);
}

int	get_min_index_mouse(t_sphere *sphere, int count)
{
	t_vec2	min;
	int		i;
	int		index;

	min.x = __INT_MAX__;
	index = -1;
	i = 0;
	while (i < count)
	{
		if (sphere[i].time.x >= 0 && sphere[i].time.x < min.x)
		{
			min.x = sphere[i].time.x;
			index = i;
		}
		i += 1;
	}
	return (index);
}

void	hit_sphere_mouse(t_time *time, t_ray ray, t_sphere *sphere, int count)
{
	int		index;
	int		i;

	i = 0;
	while (i < count)
	{
		sphere[i].time = draw_sphere(ray, sphere[i].location, sphere[i].radius);
		i += 1;
	}
	index = get_min_index_mouse(sphere, count);
	time->index = index;
	if (sphere[index].time.x < time->time)
	{
		time->time = sphere[index].time.x;
	}
}

t_bool	target_search(t_scene scene, t_ray ray, t_time *target)
{
	hit_sphere_mouse(target, ray, scene.sphere, scene.count.sphere);
	
	if (target->index != -1)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

static t_bool	bool_reverse(t_bool say)
{
	if (say == TRUE)
	{
		return (FALSE);
	}
	else
	{
		return (TRUE);
	}
}

int	mouse_released(int key, int x, int y, t_scene *scene)
{
	(void)key;
	(void)x;
	(void)y;
	if (scene->move == FALSE)
	{
		t_ray	ray;
		t_time	target;

		ray = ray_new(scene->mouse, scene->camera, scene->matrix);
		if (target_search(*scene, ray, &target) == TRUE)
		{
			scene->pressed = TRUE;
			scene->object.type = 1;
			if (scene->object.target != &(scene->sphere[target.index]))
			{
				scene->object.target = &(scene->sphere[target.index]);
				printf("pressed: %d\n", target.index);
				draw(*scene);
			}
			else
			{
				scene->object.target = NULL;
				scene->pressed = bool_reverse(scene->pressed);
				draw(*scene);
			}
		}
		else
		{
			scene->pressed = FALSE;
			draw(*scene);
		}
	}
	mlx_hook(scene->mlx.win, 6, 0, NULL, NULL);
	return (0);
}
