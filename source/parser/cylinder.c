/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:44:12 by lemmon            #+#    #+#             */
/*   Updated: 2022/07/11 15:47:20 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_cylinder(char *str, t_clnd *cylinder, t_scene *scene)
{
	int	i;

	i = 0;
	check_next_element(str, i);
	cylinder->coordinates = parse_vector(str, &i);
	cylinder->vector = parse_vector(str, &i);
	check_vector(cylinder->vector);
	check_digit(str, i);
	cylinder->diameter = ft_atof(str, &i);
	check_digit(str, i);
	cylinder->height = ft_atof(str, &i);
	cylinder->color = parsing_color(str, i, scene);
}
