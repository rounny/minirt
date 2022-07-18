/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 09:28:15 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/18 15:47:52 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

// find intersection
t_object	find_object(t_scene scene, t_ray ray)
{
	t_object	object;
	t_time		time;

	time.index = -1;
	time.time = __INT_MAX__;
	hit_sphere(&time, ray, scene.sphere, scene.count.sphere);
	if (time.index == -1)
	{
		object.type = NIL;
		object.target = NULL;
	}
	else
	{
		object.type = time.type;
		object.target = &(scene.sphere[time.index]);
	}
	return (object);
}
