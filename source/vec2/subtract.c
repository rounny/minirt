/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtract.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 08:20:09 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/12 08:20:10 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2.h"

t_vec2	vec2_subv(t_vec2 a, float value)
{
	a.x -= value;
	a.y -= value;
	return (a);
}

t_vec2	vec2_sub(t_vec2 a, t_vec2 b)
{
	a.x -= b.x;
	a.y -= b.y;
	return (a);
}
