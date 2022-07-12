/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:07 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/12 08:21:19 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC2_H
# define VEC2_H

# include <stdio.h>
# include <math.h>

struct s_vec2
{
	float	x;
	float	y;
};

typedef struct s_vec2	t_vec2;

t_vec2	vec2_addv(t_vec2 vec, float value);
t_vec2	vec2_add(t_vec2 a, t_vec2 b);
t_vec2	vec2_divv(t_vec2 vec, float value);
t_vec2	vec2_div(t_vec2 a, t_vec2 b);
float	vec2_len(t_vec2 vec);
t_vec2	vec2_new(float x, float y);
void	vec2_print(char *name, t_vec2 vector);
t_vec2	vec2_subv(t_vec2 a, float value);
t_vec2	vec2_sub(t_vec2 a, t_vec2 b);

#endif // VEC2_H
