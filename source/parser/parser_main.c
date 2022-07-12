/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:10:06 by lemmon            #+#    #+#             */
/*   Updated: 2022/07/11 18:35:09 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_options(char *line, t_scene *scene)
{
	int	i;

	i = 0;
	if (line[i] == 'A')
		parse_ambient_lightning(line + 1, scene);
	else if (line[i] == 'C')
		parse_camera(line + 1, scene);
	else if (line[i] == 'L')
		parse_light(line + 1, scene);
}

void	parse_count_objects(char *line, t_count *count)
{
	int	i;

	i = 0;
	if (line[i] == 's' && line[i + 1] == 'p')
		++count->sphere;
	else if (line[i] == 'p' && line[i + 1] == 'l')
		++count->plane;
	else if (line[i] == 'c' && line[i + 1] == 'y')
		++count->cylinder;
}

void	create_objects(t_count count, t_scene *scene)
{
	if (count.sphere)
	{
		scene->sphere = malloc(sizeof(t_sphere) * count.sphere);
		if (!scene->sphere)
			ft_error("malloc error");
	}
	if (count.plane)
	{
		scene->plane = malloc(sizeof(t_pln) * count.plane);
		if (!scene->plane)
			ft_error("malloc error");
	}
	if (count.cylinder)
	{
		scene->cylinder = malloc(sizeof(t_clnd) * count.cylinder);
		if (!scene->cylinder)
			ft_error("malloc error");
	}
}

void	parse_objects(char **line, t_scene *scene, t_count *count)
{
	int	i;

	i = -1;
	create_objects(*count, scene);
	while (++i < scene->count_line)
	{
		if (line[i][0] == 's' && line[i][1] == 'p')
		{
			parse_sphere(line[i] + 2, &(scene->sphere[count->i_sph]), scene);
			++count->i_sph;
		}
		else if (line[i][0] == 'p' && line[i][1] == 'l')
		{
			parse_plane(line[i] + 2, &scene->plane[count->i_pln], scene);
			++count->i_pln;
		}
		else if (line[i][0] == 'c' && line[i][1] == 'y')
		{
			parse_cylinder(line[i] + 2, &scene->cylinder[count->i_clnd], scene);
			++count->i_clnd;
		}
	}
}

void	parsing(t_scene *scene)
{
	t_count	count;
	char	**line;
	int		i;

	i = -1;
	count = (t_count){};
	line = get_line_file(scene->fd, scene);
	while (++i < scene->count_line)
	{
		scene->count_argc = 0;
		if (line[i][0] == 'A' || line[i][0] == 'C' || line[i][0] == 'L')
			parse_options(line[i], scene);
		else if ((line[i][0] == 's' && line[i][1] == 'p')
				|| (line[i][0] == 'p' && line[i][1] == 'l')
				|| (line[i][0] == 'c' && line[i][1] == 'y'))
			parse_count_objects(line[i], &count);
		else
			ft_error("invalid content of file");
	}
	parse_objects(line, scene, &count);
	scene->count = count;
}
