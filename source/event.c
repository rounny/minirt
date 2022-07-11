/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:23 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/11 14:53:01 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "event.h"
#include "key.h"

void	movement(t_scene *scene)
{
	t_vec3	vector;

	vector = scene->press.key.direction;
	vector = vec3_mulmat_xy(vector, scene->option.matrix);
	vector = vec3_add(scene->camera.location, vec3_mulv(vector, 2.5));
	scene->camera.location = vector;
}

void	keyboard(t_scene *scene)
{
	if (scene->press.key.move == TRUE)
	{
		movement(scene);
	}
	if (scene->press.key.fov == TRUE)
	{
		scene->camera.fov += scene->press.key.change;
		scene->camera.focus = WIDTH / 2 / tanf(scene->camera.fov / 2 * M_PI / 180);
	}
}

int	func(t_scene *scene)
{
	t_bool	isdraw;

	isdraw = FALSE;
	if (scene->press.key.action == TRUE)
	{
		keyboard(scene);
		isdraw = TRUE;
	}
	if (scene->press.mouse.action == TRUE)
	{
		isdraw = TRUE;
	}
	if (isdraw == TRUE)
	{
		draw(*scene);
	}
	return (0);
}

int	key_repressed(t_key key, t_scene *scene)
{
	scene->press.key.count -= 1;

	t_vec3	vector;

	vector = scene->press.key.direction;
	if (key == KEY_W)
	{
		vector = vec3_sub(vector, vec3_new(1.0, 0.0, 0.0));
	}
	if (key == KEY_A)
	{
		vector = vec3_sub(vector, vec3_new(0.0, -1.0, 0.0));
	}
	if (key == KEY_S)
	{
		vector = vec3_sub(vector, vec3_new(-1.0, 0.0, 0.0));
	}
	if (key == KEY_D)
	{
		vector = vec3_sub(vector, vec3_new(0.0, 1.0, 0.0));
	}
	if (key == KEY_SPASE)
	{
		vector = vec3_sub(vector, vec3_new(0.0, 0.0, -1.0));
	}
	if (key == KEY_SHIFT)
	{
		vector = vec3_sub(vector, vec3_new(0.0, 0.0, 1.0));
	}
	scene->press.key.direction = vector;

	if (scene->press.key.count == 0)
	{
		scene->press.key.action = FALSE;
		scene->press.key.move = FALSE;
	}

	if (key == KEY_PLUS)
	{
		scene->press.key.fov = FALSE;
	}
	if (key == KEY_MINUS)
	{
		scene->press.key.fov = FALSE;
	}
	return (key);
}

void	event(t_scene *scene)
{
	t_mlx	mlx;

	mlx = scene->mlx;
	mlx_hook(mlx.win, ON_KEYDOWN, 0, key_pressed, scene);
	mlx_hook(mlx.win, ON_KEYUP, 0, key_repressed, scene);
	mlx_hook(mlx.win, ON_MOUSEDOWN, 0, mouse_pressed, scene);
	mlx_hook(mlx.win, ON_MOUSEUP, 0, mouse_released, scene);
	mlx_hook(mlx.win, ON_DESTROY, 0, terminate, scene);
	mlx_do_key_autorepeatoff(mlx.mlx);
	mlx_loop_hook(mlx.mlx, func, scene);
	mlx_loop(mlx.mlx);
}
