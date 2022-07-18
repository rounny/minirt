/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:43:39 by lemmon            #+#    #+#             */
/*   Updated: 2022/07/18 17:54:31 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_camera(char *str, t_scene *scene)
{
	int	i;

	i = 0;
	if (scene->camera.flag_cam == 0)
		scene->camera.flag_cam = 1;
	else
		ft_error("dublicate of sceneions");
	check_next_element(str, i);
	scene->camera.location = parse_vector(str, &i);
	scene->camera.rotation = parse_vector(str, &i);
	check_vector(scene->camera.rotation);
	check_next_element(str, i);
	scene->camera.fov = ft_atoi(&str[i]);
	if (scene->camera.fov > 180 || scene->camera.fov < 0)
		ft_error("invalid argument(fov)");
	check_next_space(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
		++i;
	check_next_space(str, &i);
	if (str[i])
		ft_error("invalid argument...");
	scene->camera.focus = WIDTH / 2 / tanf(scene->camera.fov / 2 * M_PI / 180);
}
