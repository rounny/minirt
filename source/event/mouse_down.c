/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 07:17:36 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/12 07:20:15 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "event.h"
#include "mouse.h"
#include "draw.h"

int	mouse_move(int x, int y, t_scene *scene)
{
	scene->camera.rotation.z -= (x - scene->press.mouse.vector.x) * 0.1;
	scene->camera.rotation.y += (y - scene->press.mouse.vector.y) * 0.1;
	scene->press.mouse.vector = vec2_new(x, y);
	matrix_new(scene->option.matrix);
	matrix_rotate(scene->option.matrix, scene->camera.rotation);
	scene->press.mouse.action = TRUE;
	return (0);
}

int	mouse_down(int key, int x, int y, t_scene *scene)
{
	scene->press.mouse.vector = vec2_new(x, y);
	if (key == MOUSE_CLICK_LEFT)
	{
		mlx_hook(scene->mlx.win, ON_MOUSEMOVE, 0, mouse_move, scene);
	}
	return (0);
}
