/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 08:20:32 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/12 08:20:42 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2.h"

t_vec2	vec2_addv(t_vec2 vec, float value)
{
	vec.x += value;
	vec.y += value;
	return (vec);
}

t_vec2	vec2_add(t_vec2 a, t_vec2 b)
{
	a.x += b.x;
	a.y += b.y;
	return (a);
}
