/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnvtosh <ivnvtosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:44:12 by lemmon            #+#    #+#             */
/*   Updated: 2022/07/09 18:21:45 by ivnvtosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_cylinder(char *str, t_clnd *cylinder, t_scene *scene)
{
	int	i;

	i = 0;
	// if (scene->cylinder->flag_cy == 0)
	// 	scene->cylinder->flag_cy = 1;
	// else
	// 	ft_error("dublicate of options");
	check_next_element(str, i);
	cylinder->coordinates = parse_xyz(str, &i);
	cylinder->vector = parse_xyz(str, &i);
	check_vector(cylinder->vector);
	check_digit(str, i);
	cylinder->diameter = ft_atof(str, &i);
	check_digit(str, i);
	cylinder->height = ft_atof(str, &i);
	cylinder->color = parsing_color(str, i, scene);

	// printf("x - |%f|\n", scene->cylinder->coordinates.x);
	// printf("y - |%f|\n", scene->cylinder->coordinates.y);
	// printf("z - |%f|\n", scene->cylinder->coordinates.z);
	// printf("\\\\\\\\\\\\\\\\\\\\\\ \n");
	// printf("x - |%f|\n", scene->cylinder->vector.x);
	// printf("y - |%f|\n", scene->cylinder->vector.y);
	// printf("z - |%f|\n", scene->cylinder->vector.z);
	// printf("\\\\\\\\\\\\\\\\\\\\\\ \n");
	// printf("diameter - |%f|\n", scene->cylinder->diameter);
	// printf("height - |%f|\n", scene->cylinder->height);
	// printf("r - |%d|\n", scene->cylinder->rgb.r);
	// printf("g - |%d|\n", scene->cylinder->rgb.g);
	// printf("b - |%d|\n", scene->cylinder->rgb.b);

}


// void	parse_cylinder(char *str, t_scene	*scene)
// {
// 	int	i;

// 	i = 0;
// 	// if (scene->cylinder->flag_cy == 0)
// 	// 	scene->cylinder->flag_cy = 1;
// 	// else
// 	// 	ft_error("dublicate of options");
// 	check_next_element(str, i);
// 	scene->cylinder->coordinates = parse_xyz(str, &i);
// 	scene->cylinder->vector = parse_xyz(str, &i);
// 	check_vector(scene->cylinder->vector);
// 	check_digit(str, i);
// 	scene->cylinder->diameter = ft_atof(str, &i);
// 	check_digit(str, i);
// 	scene->cylinder->height = ft_atof(str, &i);
// 	scene->cylinder->color = parsing_color(str, i, scene);

// 	// printf("x - |%f|\n", scene->cylinder->coordinates.x);
// 	// printf("y - |%f|\n", scene->cylinder->coordinates.y);
// 	// printf("z - |%f|\n", scene->cylinder->coordinates.z);
// 	// printf("\\\\\\\\\\\\\\\\\\\\\\ \n");
// 	// printf("x - |%f|\n", scene->cylinder->vector.x);
// 	// printf("y - |%f|\n", scene->cylinder->vector.y);
// 	// printf("z - |%f|\n", scene->cylinder->vector.z);
// 	// printf("\\\\\\\\\\\\\\\\\\\\\\ \n");
// 	// printf("diameter - |%f|\n", scene->cylinder->diameter);
// 	// printf("height - |%f|\n", scene->cylinder->height);
// 	// printf("r - |%d|\n", scene->cylinder->rgb.r);
// 	// printf("g - |%d|\n", scene->cylinder->rgb.g);
// 	// printf("b - |%d|\n", scene->cylinder->rgb.b);

// }