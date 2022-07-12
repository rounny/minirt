/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:01:03 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/12 08:02:00 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "data.h"
# include "window.h"
# include "utils.h"

struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
};

typedef struct s_ray	t_ray;

t_ray	ray_new(t_vec2 pixel, t_cam camera, t_mat matrix);
t_vec3	ray_pos(t_ray ray, float time);

#endif // RAY_H
