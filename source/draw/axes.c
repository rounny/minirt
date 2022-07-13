/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axes.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:59:54 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/13 12:00:25 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

float	red(t_ray ray, t_vec3 origin)
{
	t_vec3	t;

	t.y = (origin.y - ray.origin.y) / ray.direction.y;
	t.z = (origin.z - ray.origin.z) / ray.direction.z;
	if (t.y - t.z < -1 || t.y - t.z > 1)
	{
		return (-1.0);
	}
	t.x = ray.origin.x + ray.direction.x * t.z;
	// if ((int)t.x != (int)t.y || (int)t.x != (int)t.z)
	// {
	// 	return (FALSE);
	// }
	return (t.z);
}

float	grean(t_ray ray, t_vec3 origin)
{
	t_vec3	t;

	t.x = (origin.x - ray.origin.x) / ray.direction.x;
	t.z = (origin.y - ray.origin.z) / ray.direction.z;
	if (t.x - t.z < -1 || t.x - t.z > 1)
	{
		return (-1.0);
	}
	t.y = ray.origin.y + ray.direction.y * t.z;
	// if ((int)t.x != (int)t.y || (int)t.x != (int)t.z)
	// {
	// 	return (vec3_newv(-1.0));
	// }
	return (t.z);
}

float	blue(t_ray ray, t_vec3 origin)
{
	t_vec3	t;

	t.x = (origin.x - ray.origin.x) / ray.direction.x;
	t.y = (origin.y - ray.origin.y) / ray.direction.y;
	if (t.x - t.y < -1 || t.x - t.y > 1)
	{
		return (-1.0);
	}
	t.z = ray.origin.z + ray.direction.z * t.x;
	// if ((int)t.x != (int)t.y || (int)t.x != (int)t.z)
	// {
	// 	return (vec3_newv(-1.0));
	// }
	return (t.x);
}

void	hit_axes(t_time *time, t_scene scene, t_ray ray)
{
	float	t;

	t = red(ray, vec3_newv(0.0));
	if (t >= 0 && t < time->time)
	{
		time->index = 0;
		time->time = t;
		time->type = LINE;
	}
	t = grean(ray, vec3_newv(0.0));
	if (t >= 0 && t < time->time)
	{
		time->index = 1;
		time->time = t;
		time->type = LINE;
	}
	t = blue(ray, vec3_newv(0.0));
	if (t >= 0 && t < time->time)
	{
		time->index = 2;
		time->time = t;
		time->type = LINE;
	}
	if (scene.object.type != NIL)
	{
		t_sphere	sphere;

		sphere = *(t_sphere *)scene.object.target;
		if (scene.object.x == TRUE)
		{
			t = red(ray, sphere.location);
			if (t >= 0 && t < time->time)
			{
				time->index = 0;
				time->time = t;
				time->type = LINE;
			}
		}
		if (scene.object.y == TRUE)
		{
			t = grean(ray, sphere.location);
			if (t >= 0 && t < time->time)
			{
				time->index = 1;
				time->time = t;
				time->type = LINE;
			}
		}
		if (scene.object.z == TRUE)
		{
			t = blue(ray, sphere.location);
			if (t >= 0 && t < time->time)
			{
				time->index = 2;
				time->time = t;
				time->type = LINE;
			}
		}
	}
}
