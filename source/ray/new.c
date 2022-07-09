/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:40:14 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/08 16:05:49 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_ray	ray_new(t_vec2 pixel, t_cam camera, t_mat matrix)
{
	t_ray	ray;

	ray.origin = camera.location;
	pixel.x -= WIDTH / 2.0;
	pixel.y -= HEIGHT / 2.0;
	ray.direction = vec3_norm(vec3_new(camera.focus, pixel.x, pixel.y));
	ray.direction = vec3_mulmat(ray.direction, matrix);
	return (ray);
}
