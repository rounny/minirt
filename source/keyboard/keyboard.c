/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:21 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/09 12:28:51 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "key.h"

t_bool	ismovement(int key, t_scene *scene)
{
	t_vec3	vector;

	if (key == KEY_W)
		vector = vec3_new(1.0, 0.0, 0.0);
	else if (key == KEY_A)
		vector = vec3_new(0.0, -1.0, 0.0);
	else if (key == KEY_S)
		vector = vec3_new(-1.0, 0.0, 0.0);
	else if (key == KEY_D)
		vector = vec3_new(0.0, 1.0, 0.0);
	else if (key == KEY_SPASE)
		vector = vec3_new(0.0, 0.0, -1.0);
	else if (key == KEY_Z)
		vector = vec3_new(0.0, 0.0, 1.0);
	else
		return (FALSE);
	vector = vec3_mulmat_xy(vector, scene->matrix);
	vector = vec3_add(scene->camera.location, vec3_mulv(vector, 50.0));
	scene->camera.location = vector;
	draw(*scene);
	return (TRUE);
}

t_bool	isblock(int key, t_scene *scene)
{
	if (key == KEY_ONE)
		scene->block = 1;
	else if (key == KEY_TWO)
		scene->block = 2;
	else if (key == KEY_THREE)
		scene->block = 4;
	else if (key == KEY_FOUR)
		scene->block = 8;
	else if (key == KEY_FIVE)
		scene->block = 16;
	else
		return (FALSE);
	draw(*scene);
	return (TRUE);
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

static int	mouse_movex(int x, int y, t_scene *scene)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)scene->object.target;
	sphere->location.x += vec2_len(vec2_new(x - scene->mouse.x, y - scene->mouse.y));
	// sphere->location.x += (x - scene->mouse.x) + (y - scene->mouse.y) * 0.1;
	scene->mouse.x = x;
	scene->mouse.y = y;
	draw(*scene);
	return (0);
}

static int	mouse_movey(int x, int y, t_scene *scene)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)scene->object.target;
	sphere->location.y += vec2_len(vec2_new(x - scene->mouse.x, y - scene->mouse.y));
	scene->mouse.x = x;
	scene->mouse.y = y;
	draw(*scene);
	return (0);
}

static int	mouse_movez(int x, int y, t_scene *scene)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)scene->object.target;
	sphere->location.z += vec2_len(vec2_new(x - scene->mouse.x, y - scene->mouse.y));
	scene->mouse.x = x;
	scene->mouse.y = y;
	draw(*scene);
	return (0);
}

int	key_pressed(int key, t_scene *scene)
{
	if (scene->pressed == TRUE)
	{
		if (key == KEY_I)
		{
			mlx_hook(scene->mlx.win, 6, 0, mouse_movex, scene);
			printf("x\n");
			return (0);
		}
		else if (key == KEY_K)
		{
			printf("y\n");
			mlx_hook(scene->mlx.win, 6, 0, mouse_movey, scene);
			return (0);
		}
		else if (key == KEY_M)
		{
			mlx_hook(scene->mlx.win, 6, 0, mouse_movez, scene);
			printf("z\n");
			return (0);
		}
	}
	if (ismovement(key, scene) == TRUE)
	{
		return (0);
	}
	else if (isblock(key, scene) == TRUE)
	{
		return (0);
	}
	else if (key == KEY_C)
	{
		scene->smooth = bool_reverse(scene->smooth);
		draw(*scene);
	}
	else if (key == KEY_PLUS)
	{
		scene->camera.fov += 1.0;
		scene->camera.focus = WIDTH / 2 / tanf(scene->camera.fov / 2 * M_PI / 180);
		draw(*scene);
	}
	else if (key == KEY_MINUS)
	{
		scene->camera.fov -= 1.0;
		scene->camera.focus = WIDTH / 2 / tanf(scene->camera.fov / 2 * M_PI / 180);
		draw(*scene);
	}
	else if (key == KEY_ESC)
	{
		terminate(scene);
	}
	else
	{
		printf("key: %d\n", key);
	}
	return (0);
}
