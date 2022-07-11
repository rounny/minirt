/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 06:36:49 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/11 14:48:34 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mouse.h"
#include "draw.h"

int	mouse_rotate(int x, int y, t_scene *scene)
{
	scene->camera.rotation.z -= (x - scene->press.mouse.vector.x) * 0.1;
	scene->camera.rotation.y += (y - scene->press.mouse.vector.y) * 0.1;
	scene->press.mouse.vector = vec2_new(x, y);
	matrix_new(scene->option.matrix);
	matrix_rotate(scene->option.matrix, scene->camera.rotation);
	scene->press.mouse.action = TRUE;
	return (0);
}

int	mouse_pressed(int key, int x, int y, t_scene *scene)
{
	scene->press.mouse.vector = vec2_new(x, y);
	if (key == MOUSE_CLICK_LEFT)
	{
		mlx_hook(scene->mlx.win, 6, 0, mouse_rotate, scene);
	}
	return (0);
}

int	mouse_released(int key, int x, int y, t_scene *scene)
{
	(void)key;
	(void)x;
	(void)y;
	mlx_hook(scene->mlx.win, 6, 0, NULL, NULL);
	scene->press.mouse.action = FALSE;
	return (0);
}
