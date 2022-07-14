/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:53:09 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/14 10:56:10 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	matrix_scale(t_mat matrix, t_vec3 scale)
{
	t_mat	_scale;

	matrix_column(_scale[0], scale.x, 0.0, 0.0);
	matrix_column(_scale[1], 0.0, scale.y, 0.0);
	matrix_column(_scale[2], 0.0, 0.0, scale.z);
	matrix_multiply(matrix, _scale);
}
