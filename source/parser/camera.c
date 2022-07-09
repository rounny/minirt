/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnvtosh <ivnvtosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:43:39 by lemmon            #+#    #+#             */
/*   Updated: 2022/07/09 18:43:36 by ivnvtosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"


t_vec3 parse_xyz(char *str, int *i)
{
	t_vec3	matrix;
	int		separator;

	separator = 0;
	matrix.x = ft_atof(str, i);
	// printf("x - %f\n", matrix.x);
	count_separator(str, i, &separator);
	// printf("str - %c\n", str[*i]);
	check_next_element(str, *i);
	matrix.y = ft_atof(str, i);
	count_separator(str, i, &separator);
	check_next_element(str, *i);
	matrix.z = ft_atof(str, i);
	// printf("separator - %d\n", separator);
	if (separator != 2)
		ft_error("invalid argument(separator)");
	return(matrix);
}

void	check_vector(t_vec3 vector)
{
	if ((vector.x > 1 || vector.x < -1) || (vector.y > 1 || vector.y < -1)
	|| (vector.z > 1 || vector.z < -1))
		ft_error("invalid argument(vector)");
}

void	parse_camera(char *str, t_scene *scene)
{
	int	i;

	i = 0;
	if (scene->camera.flag_C == 0)
		scene->camera.flag_C = 1;
	else
		ft_error("dublicate of sceneions");
	check_next_element(str, i);
	scene->camera.location = parse_xyz(str, &i);
	scene->camera.rotation = parse_xyz(str, &i);
	check_vector(scene->camera.rotation);
	check_next_element(str, i);
	scene->camera.fov = ft_atoi2(&str[i]);
	if (scene->camera.fov > 180 || scene->camera.fov < 0)
		ft_error("invalid argument(fov)");
	check_next_space(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
		++i;
	check_next_space(str, &i);
	if (str[i])
		ft_error("invalid argument...");
	scene->camera.focus = WIDTH / 2 / tanf(scene->camera.fov / 2 * M_PI / 180);
	// printf("x - |%f|\n", scene->camera.location.x);
	// printf("y - |%f|\n", scene->camera.location.y);
	// printf("z - |%f|\n", scene->camera.location.z);
	// printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n");
	// printf("x - |%f|\n", scene->camera.rotation.x);
	// printf("y - |%f|\n", scene->camera.rotation.y);
	// printf("z - |%f|\n", scene->camera.rotation.z);
	// printf("for - |%d|\n", scene->camera.fov);

}