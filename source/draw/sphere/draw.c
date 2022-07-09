/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:44 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/05 16:29:02 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_vec2	draw_sphere(t_ray ray, t_vec3 center, float radius)
{
	t_vec3	origin;
	float	b;
	float	c;
	float	h;

	origin = vec3_sub(ray.origin, center);
	b = vec3_dot(origin, ray.direction);
	c = vec3_dot(origin, origin) - radius * radius;
	h = b * b - c;
	if (h < 0.0)
	{
		return (vec2_new(-1.0, -1.0));
	}
	else
	{
		h = sqrt(h);
		return (vec2_new(-b - h, -b + h));
	}
}
