/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_trim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:28:38 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/08 15:33:53 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	color_trim(t_vec3 color)
{
	color = vec3_mapv(color, 0.0, maxf);
	color = vec3_mapv(color, 1.0, minf);
	return (color);
}
