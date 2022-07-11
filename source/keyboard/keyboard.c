/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:21 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/11 14:53:17 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "key.h"

t_bool	isblock(int key, t_scene *scene)
{
	if (key == KEY_ONE)
		scene->option.block = 1;
	else if (key == KEY_TWO)
		scene->option.block = 2;
	else if (key == KEY_THREE)
		scene->option.block = 4;
	else if (key == KEY_FOUR)
		scene->option.block = 8;
	else if (key == KEY_FIVE)
		scene->option.block = 16;
	else
		return (FALSE);
	draw(*scene);
	return (TRUE);
}

int	key_pressed(t_key key, t_scene *scene)
{
	scene->press.key.count += 1;
	scene->press.key.action = TRUE;

	t_vec3	vector;

	vector = scene->press.key.direction;
	if (key == KEY_W)
	{
		vector = vec3_add(vector, vec3_new(1.0, 0.0, 0.0));
		scene->press.key.move = TRUE;
	}
	if (key == KEY_A)
	{
		vector = vec3_add(vector, vec3_new(0.0, -1.0, 0.0));
		scene->press.key.move = TRUE;
	}
	if (key == KEY_S)
	{
		vector = vec3_add(vector, vec3_new(-1.0, 0.0, 0.0));
		scene->press.key.move = TRUE;
	}
	if (key == KEY_D)
	{
		vector = vec3_add(vector, vec3_new(0.0, 1.0, 0.0));
		scene->press.key.move = TRUE;
	}
	if (key == KEY_SPASE)
	{
		vector = vec3_add(vector, vec3_new(0.0, 0.0, -1.0));
		scene->press.key.move = TRUE;
	}
	if (key == KEY_SHIFT)
	{
		vector = vec3_add(vector, vec3_new(0.0, 0.0, 1.0));
		scene->press.key.move = TRUE;
	}
	scene->press.key.direction = vector;

	scene->press.key.code = key;

	if (isblock(key, scene) == TRUE)
	{
		return (0);
	}
	else if (key == KEY_C)
	{
		scene->option.smooth = !scene->option.smooth;
		draw(*scene);
	}
	else if (key == KEY_PLUS)
	{
		scene->press.key.fov = TRUE;
		scene->press.key.change = 0.5;
	}
	else if (key == KEY_MINUS)
	{
		scene->press.key.fov = TRUE;
		scene->press.key.change = -0.5;
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
