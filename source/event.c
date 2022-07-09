/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:23 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/09 12:34:09 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "event.h"

void	event(t_scene *scene)
{
	t_mlx	mlx;

	mlx = scene->mlx;
	mlx_hook(mlx.win, ON_KEYDOWN, 0, key_pressed, scene);
	mlx_hook(mlx.win, ON_MOUSEDOWN, 0, mouse_pressed, scene);
	mlx_hook(mlx.win, ON_MOUSEUP, 0, mouse_released, scene);
	mlx_hook(mlx.win, ON_DESTROY, 0, terminate, scene);
	mlx_loop(mlx.mlx);
}
