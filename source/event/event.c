/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:23 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/12 07:54:50 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "event.h"
#include "key.h"

void	event(t_scene *scene)
{
	t_mlx	mlx;

	mlx = scene->mlx;
	mlx_hook(mlx.win, ON_KEYDOWN, 0, key_down, scene);
	mlx_hook(mlx.win, ON_KEYUP, 0, key_up, scene);
	mlx_hook(mlx.win, ON_MOUSEDOWN, 0, mouse_down, scene);
	mlx_hook(mlx.win, ON_MOUSEUP, 0, mouse_up, scene);
	mlx_hook(mlx.win, ON_DESTROY, 0, terminate, scene);
	mlx_do_key_autorepeatoff(mlx.mlx);
	mlx_loop_hook(mlx.mlx, thread_for_draw, scene);
	mlx_loop(mlx.mlx);
}
