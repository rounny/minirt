/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnvtosh <ivnvtosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:44:18 by lemmon            #+#    #+#             */
/*   Updated: 2022/07/09 18:19:19 by ivnvtosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"


void	parse_light(char *str, t_scene *scene)
{
	int	i;

	i = 0;
	if (scene->light.flag_L == 0)
		scene->light.flag_L = 1;
	else
		ft_error("dublicate of options");
	check_next_element(str, i);
	scene->light.location = parse_xyz(str, &i);
	check_digit(str, i);
	scene->light.intensity = ft_atof(str, &i);
	if (scene->light.intensity > 1.0 || scene->light.intensity < 0.0)
		ft_error("invalid argument");
	scene->light.color = parsing_color(str, i, scene);
	// printf("x - |%f|\n", scene->light.coordinates.x);
	// printf("y - |%f|\n", scene->light.coordinates.y);
	// printf("z - |%f|\n", scene->light.coordinates.z);
	// // printf("str - %c\n", str[i]);
	// // printf("str - %c\n", str[i + 1]);
	// printf("r - |%d|\n", scene->light.rgb.r);
	// printf("g - |%d|\n", scene->light.rgb.g);
	// printf("b - |%d|\n", scene->light.rgb.b);

}