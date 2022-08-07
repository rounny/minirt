/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:27:54 by lemmon            #+#    #+#             */
/*   Updated: 2022/08/07 19:40:11 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_light(char *str, t_light *light, t_scene *scene)
{
	int	i;

	i = 0;
	check_next_element(str, i);
	light->location = parse_vector(str, &i);
	light->location.z *= -1;
	check_digit(str, i);
	light->intensity = ft_atof(str, &i);
	if (light->intensity > 1.0 || light->intensity < 0.0)
		ft_error("invalid argument");
	light->color = parsing_color(str, i, scene);
}
