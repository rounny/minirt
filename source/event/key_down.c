/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_down.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:31:58 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/12 07:51:52 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "key.h"

static void	movement(t_key key, t_vec3 *direction, t_bool *move)
{
	t_vec3	vector;

	vector = *direction;
	if (key == KEY_W)
		vector = vec3_add(vector, vec3_new(1.0, 0.0, 0.0));
	else if (key == KEY_A)
		vector = vec3_add(vector, vec3_new(0.0, -1.0, 0.0));
	else if (key == KEY_S)
		vector = vec3_add(vector, vec3_new(-1.0, 0.0, 0.0));
	else if (key == KEY_D)
		vector = vec3_add(vector, vec3_new(0.0, 1.0, 0.0));
	else if (key == KEY_SPASE)
		vector = vec3_add(vector, vec3_new(0.0, 0.0, -1.0));
	else if (key == KEY_SHIFT)
		vector = vec3_add(vector, vec3_new(0.0, 0.0, 1.0));
	else
		return ;
	*move = TRUE;
	*direction = vector;
}

static void	check_fov(t_key key, float *change, t_bool *fov)
{
	if (key == KEY_PLUS)
		*change += +0.5;
	else if (key == KEY_MINUS)
		*change += -0.5;
	else
		return ;
	*fov = TRUE;
}

static void	check_block(t_key key, int *block)
{
	if (key == KEY_ONE)
		*block = 1;
	else if (key == KEY_TWO)
		*block = 2;
	else if (key == KEY_THREE)
		*block = 4;
	else if (key == KEY_FOUR)
		*block = 8;
	else if (key == KEY_FIVE)
		*block = 16;
	else
		return ;
}

static void	check_smooth(t_key key, int *smooth)
{
	if (key == KEY_C)
		*smooth = !*smooth;
	else
		return ;
}

int	key_down(t_key key, t_scene *scene)
{
	scene->press.key.count += 1;
	scene->press.key.action = TRUE;
	scene->press.key.code = key;
	movement(key, &(scene->press.key.direction), &(scene->press.key.move));
	check_fov(key, &(scene->press.key.change), &(scene->press.key.fov));
	check_block(key, &(scene->option.block));
	check_smooth(key, &(scene->option.smooth));
	if (key == KEY_ESC)
		terminate(scene);
	return (0);
}
