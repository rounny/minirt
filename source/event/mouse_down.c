/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 07:17:36 by ccamie            #+#    #+#             */
/*   Updated: 2022/08/07 20:14:52 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "event.h"
#include "mouse.h"
#include "draw.h"

int	mouse_move_rotate(int x, int y, t_scene *scene)
{
	scene->camera.rotation.z -= (x - scene->press.mouse.vector.x) * 0.1;
	scene->camera.rotation.y += (y - scene->press.mouse.vector.y) * 0.1;
	scene->press.mouse.vector = vec2_new(x, y);
	matrix_new(scene->option.matrix);
	matrix_rotate(scene->option.matrix, scene->camera.rotation);
	scene->press.mouse.action = TRUE;
	return (0);
}

int	mouse_find(t_vec2 pixel, t_scene *scene)
{
	t_ray		ray;
	t_object	object;

	pixel = scene->press.mouse.vector;
	ray = ray_new(pixel, scene->camera, scene->option.matrix);
	object = find_object(*scene, ray);
	if (object.type == NIL)
		return (0);
	scene->press.mouse.action = TRUE;
	if (object.target == scene->object.target)
	{
		scene->object.type = NIL;
		scene->object.target = NULL;
		scene->object.x = FALSE;
		scene->object.y = FALSE;
		scene->object.z = FALSE;
		return (0);
	}
	scene->object = object;
	scene->object.x = TRUE;
	scene->object.y = TRUE;
	scene->object.z = TRUE;
	return (0);
}

int	mouse_down(int click, int x, int y, t_scene *scene)
{
	scene->press.mouse.vector = vec2_new(x, y);
	if (click == MOUSE_CLICK_LEFT)
	{
		mlx_hook(scene->mlx.win, ON_MOUSEMOVE, 0, mouse_move_rotate, scene);
	}
	if (click == MOUSE_CLICK_RIGHT)
	{
		mouse_find(vec2_new(x, y), scene);
	}
	return (0);
}
