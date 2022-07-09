/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:35:17 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/08 16:39:03 by ccamie           ###   ########.fr       */
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
	int		index;
	int		i;

	i = 0;
	while (i < count)
	{
		spheres[i].time = draw_sphere(ray, spheres[i].location, spheres[i].radius);
		i += 1;
	}
	index = get_min_index(spheres, count);
	time->index = index;
	if (spheres[index].time.x < time->time)
	{
		time->time = spheres[index].time.x;
	}
}
