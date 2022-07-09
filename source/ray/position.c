/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:41:39 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/08 16:05:53 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_vec3	ray_pos(t_ray ray, float time)
{
	return (vec3_add(ray.origin, vec3_mulv(ray.direction, time)));
}
