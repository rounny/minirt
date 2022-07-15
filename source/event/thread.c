/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 07:53:42 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/15 08:57:13 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	movement(t_scene *scene)
{
	t_vec3	vector;

	vector = scene->press.key.direction;
	vector = vec3_mulmat_xy(vector, scene->option.matrix);
	vector = vec3_add(scene->camera.location, vec3_mulv(vector, 2.5));
	scene->camera.location = vector;
}

static void	change_fov(t_scene *scene, float *fov, float *focus)
{
	*fov += scene->press.key.change;
	*focus = WIDTH / 2 / tanf(*fov / 2 * M_PI / 180);
}

static void	keyboard(t_scene *scene)
{
	if (scene->press.key.move == TRUE)
	{
		movement(scene);
	}
	if (scene->press.key.fov == TRUE)
	{
		change_fov(scene, &(scene->camera.fov), &(scene->camera.focus));
	}
}

int	thread_for_draw(t_scene *scene)
{
	t_bool	drawit;

	drawit = FALSE;
	if (scene->press.key.action == TRUE)
	{
		keyboard(scene);
		drawit = TRUE;
	}
	if (scene->press.mouse.action == TRUE)
	{
		drawit = TRUE;
	}
	if (drawit == TRUE)
	{
	}
		draw(*scene);
	return (0);
}
