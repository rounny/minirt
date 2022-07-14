/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:35:17 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/14 11:08:42 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static int	get_min_index(t_sphere *spheres, int count)
{
	t_vec2	min;
	int		i;
	int		index;

	min.x = __INT_MAX__;
	index = -1;
	i = 0;
	while (i < count)
	{
		if (spheres[i].time.x >= 0 && spheres[i].time.x < min.x)
		{
			min.x = spheres[i].time.x;
			index = i;
		}
		i += 1;
	}
	return (index);
}

void	hit_sphere(t_time *time, t_ray ray, t_sphere *spheres, int count)
{
	// t_ray	new;
	// t_mat	matrix;
	int		index;
	int		i;

	i = 0;
	while (i < count)
	{
		// matrix_new(matrix);
		// spheres[i].scale = vec3_new(1.0, 2.0, 1.0);
		// matrix_scale(matrix, spheres[i].scale);
		// new.direction = vec3_mulmat(ray.direction, matrix);
		// new.origin = ray.origin;
		// new.direction = vec3_norm(new.direction);
		spheres[i].time = draw_sphere(ray, spheres[i].location, \
													spheres[i].radius);
		i += 1;
	}
	index = get_min_index(spheres, count);
	if (index == -1)
	{
		return ;
	}
	if (spheres[index].time.x < time->time)
	{
		time->index = index;
		time->time = spheres[index].time.x;
		time->type = SPHERE;
	}
}
