/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnvtosh <ivnvtosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:44:26 by lemmon            #+#    #+#             */
/*   Updated: 2022/07/09 18:21:10 by ivnvtosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_plane(char *str, t_pln *plane, t_scene *scene)
{
	int	i;

	i = 0;
	// if (scene->plane.flag_pl == 0)
	// 	scene->plane.flag_pl = 1;
	// else
	// 	ft_error("dublicate of options");
	check_next_element(str, i);
	plane->location = parse_xyz(str, &i);
	plane->vector = parse_xyz(str, &i);
	check_vector(plane->vector);
	plane->color = parsing_color(str, i, scene);
	// printf("x - |%f|\n", scene->plane.coordinates.x);
	// printf("y - |%f|\n", scene->plane.coordinates.y);
	// printf("z - |%f|\n", scene->plane.coordinates.z);
	// printf("\\\\\\\\\\\\\\\\\\\\\\ \n");
	// printf("x - |%f|\n", scene->plane.vector.x);
	// printf("y - |%f|\n", scene->plane.vector.y);
	// printf("z - |%f|\n", scene->plane.vector.z);
	// printf("r - |%d|\n", scene->plane.rgb.r);
	// printf("g - |%d|\n", scene->plane.rgb.g);
	// printf("b - |%d|\n", scene->plane.rgb.b);
}


// void	parse_plane(char *str, t_scene *scene)
// {
// 	int	i;

// 	i = 0;
// 	if (scene->plane.flag_pl == 0)
// 		scene->plane.flag_pl = 1;
// 	else
// 		ft_error("dublicate of options");
// 	check_next_element(str, i);
// 	scene->plane.coordinates = parse_xyz(str, &i);
// 	scene->plane.vector = parse_xyz(str, &i);
// 	check_vector(scene->plane.vector);
// 	scene->plane.color = parsing_color(str, i, scene);
// 	// printf("x - |%f|\n", scene->plane.coordinates.x);
// 	// printf("y - |%f|\n", scene->plane.coordinates.y);
// 	// printf("z - |%f|\n", scene->plane.coordinates.z);
// 	// printf("\\\\\\\\\\\\\\\\\\\\\\ \n");
// 	// printf("x - |%f|\n", scene->plane.vector.x);
// 	// printf("y - |%f|\n", scene->plane.vector.y);
// 	// printf("z - |%f|\n", scene->plane.vector.z);
// 	// printf("r - |%d|\n", scene->plane.rgb.r);
// 	// printf("g - |%d|\n", scene->plane.rgb.g);
// 	// printf("b - |%d|\n", scene->plane.rgb.b);
// }