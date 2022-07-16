/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:20:58 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/16 23:31:57 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "minirt.h"
# include "ray.h"

struct s_time
{
	float	time;
	t_type	type;
	int		index;
};

typedef struct s_time	t_time;

t_vec2		draw_sphere(t_ray ray, t_vec3 center, float radius);
void		hit_sphere(t_time *time, t_ray ray, t_sphere *spheres, int count);

void		hit_axes(t_time *time, t_scene scene, t_ray ray);

t_object	find_object(t_scene scene, t_ray ray);

void		write_pixel(t_view view, t_vec2 pixel, t_vec3 color);
void		write_pixels(t_view view, t_vec2 pixel, t_vec3 color, float block);

#endif // DRAW_H
