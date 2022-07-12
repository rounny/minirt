/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:36:40 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/12 07:53:23 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "key.h"

static void	movement(t_key key, t_vec3 *direction)
{
	t_vec3	vector;

	vector = *direction;
	if (key == KEY_W)
		vector = vec3_sub(vector, vec3_new(1.0, 0.0, 0.0));
	else if (key == KEY_A)
		vector = vec3_sub(vector, vec3_new(0.0, -1.0, 0.0));
	else if (key == KEY_S)
		vector = vec3_sub(vector, vec3_new(-1.0, 0.0, 0.0));
	else if (key == KEY_D)
		vector = vec3_sub(vector, vec3_new(0.0, 1.0, 0.0));
	else if (key == KEY_SPASE)
		vector = vec3_sub(vector, vec3_new(0.0, 0.0, -1.0));
	else if (key == KEY_SHIFT)
		vector = vec3_sub(vector, vec3_new(0.0, 0.0, 1.0));
	else
		return ;
	*direction = vector;
}

static void	check_fov(t_key key, float *change)
{
	if (key == KEY_PLUS)
		*change -= +0.5;
	else if (key == KEY_MINUS)
		*change -= -0.5;
	else
		return ;
}

static void	check_number_of_pressed(t_scene *scene)
{
	if (scene->press.key.count == 0)
	{
		scene->press.key.action = FALSE;
		scene->press.key.move = FALSE;
		scene->press.key.fov = TRUE;
	}
}

int	key_up(t_key key, t_scene *scene)
{
	scene->press.key.count -= 1;
	movement(key, &(scene->press.key.direction));
	check_fov(key, &(scene->press.key.change));
	check_number_of_pressed(scene);
	return (0);
}
