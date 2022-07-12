/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:46:50 by lemmon            #+#    #+#             */
/*   Updated: 2022/07/11 18:27:16 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_vector(t_vec3 vector)
{
	if ((vector.x > 1 || vector.x < -1) || (vector.y > 1 || vector.y < -1)
		|| (vector.z > 1 || vector.z < -1))
		ft_error("invalid argument(vector)");
}

t_vec3	parse_vector(char *str, int *i)
{
	t_vec3	matrix;
	int		separator;

	separator = 0;
	matrix.x = ft_atof(str, i);
	count_separator(str, i, &separator);
	check_next_element(str, *i);
	matrix.y = ft_atof(str, i);
	count_separator(str, i, &separator);
	check_next_element(str, *i);
	matrix.z = ft_atof(str, i);
	if (separator != 2)
		ft_error ("invalid argument(separator)");
	return (matrix);
}
