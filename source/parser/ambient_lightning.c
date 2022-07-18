/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_lightning.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:43:49 by lemmon            #+#    #+#             */
/*   Updated: 2022/07/18 17:56:16 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_ambient_lightning(char *str, t_scene *scene)
{
	int		i;

	i = 0;
	if (scene->ambient.flag_amb == 0)
		scene->ambient.flag_amb = 1;
	else
		ft_error("dublicate of sceneions");
	check_digit(str, i);
	scene->ambient.lighting = ft_atof(str, &i);
	if (scene->ambient.lighting > 1.0 || scene->ambient.lighting < 0.0)
		ft_error("invalid argument");
	scene->ambient.color = parsing_color(str, i, scene);
}
