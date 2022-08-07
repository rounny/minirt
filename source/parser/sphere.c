/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:44:30 by lemmon            #+#    #+#             */
/*   Updated: 2022/08/07 19:40:52 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_sphere(char *str, t_sphere *sphere, t_scene *scene)
{
	int	i;

	i = 0;
	check_next_element(str, i);
	sphere->location = parse_vector(str, &i);
	sphere->location.z *= -1;
	check_digit(str, i);
	sphere->radius = ft_atof(str, &i);
	sphere->color = parsing_color(str, i, scene);
}
