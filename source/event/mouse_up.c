/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:37:10 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/12 07:53:04 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "event.h"
#include "mouse.h"
#include "draw.h"

int	mouse_up(int key, int x, int y, t_scene *scene)
{
	(void)key;
	(void)x;
	(void)y;
	mlx_hook(scene->mlx.win, ON_MOUSEMOVE, 0, NULL, NULL);
	scene->press.mouse.action = FALSE;
	return (0);
}
