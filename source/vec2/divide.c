/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 08:20:28 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/12 08:20:29 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2.h"

t_vec2	vec2_divv(t_vec2 vec, float value)
{
	vec.x /= value;
	vec.y /= value;
	return (vec);
}

t_vec2	vec2_div(t_vec2 a, t_vec2 b)
{
	a.x /= b.x;
	a.y /= b.y;
	return (a);
}
