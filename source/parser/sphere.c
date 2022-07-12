/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:44:30 by lemmon            #+#    #+#             */
/*   Updated: 2022/07/11 15:47:23 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_sphere(char *str, t_sphere *sphere, t_scene *scene)
{
	int	i;

	i = 0;
	check_next_element(str, i);
	sphere->location = parse_vector(str, &i);
	check_digit(str, i);
	sphere->radius = ft_atof(str, &i);
	sphere->color = parsing_color(str, i, scene);
}
