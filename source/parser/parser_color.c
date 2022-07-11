/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:10:26 by lemmon            #+#    #+#             */
/*   Updated: 2022/07/11 18:18:43 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	check_color(int color)
{
	if (color > 255 || color < 0)
		ft_error("invalid color");
}

t_vec3	parsing_color(char *str, int i, t_scene *scene)
{
	t_vec3	color;
	int		separator;

	separator = 0;
	(void)scene;
	check_next_space(str, &i);
	color.x = ft_atoi(&(str[i]));
	check_color(color.x);
	while (str[i] >= '0' && str[i] <= '9')
		++i;
	count_separator(str, &i, &separator);
	color.y = ft_atoi(&str[i]);
	check_color(color.y);
	while (str[i] >= '0' && str[i] <= '9')
		++i;
	count_separator(str, &i, &separator);
	if (!str[i] || str[i] < '0' || str[i] > '9')
		--separator;
	color.z = ft_atoi(&(str[i]));
	check_color(color.z);
	while (str[i] == ' ' || (str[i] >= '0' && str[i] <= '9'))
		++i;
	if (str[i] || separator != 2)
		ft_error("invalid color parameters");
	return (color);
}
