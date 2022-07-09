/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:53:37 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/09 12:21:21 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "data.h"

t_vec3	color_trim(t_vec3 color);
void	matrix_rotate(t_mat matrix, t_vec3 angle);
float	maxf(float a, float b);
float	minf(float a, float b);
t_vec3	vec3_mulmat(t_vec3 vec, t_mat matrix);
t_vec3	vec3_mulmat_xy(t_vec3 vec, t_mat matrix);

#endif // UTILS_H
