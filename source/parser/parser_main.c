/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:29:22 by lemmon            #+#    #+#             */
/*   Updated: 2022/07/18 17:48:29 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
		if (line[i][0] == 'A' || line[i][0] == 'C')
			parse_options(line[i], scene);
		else if ((line[i][0] == 'L')
				|| (line[i][0] == 's' && line[i][1] == 'p')
				|| (line[i][0] == 'p' && line[i][1] == 'l')
				|| (line[i][0] == 'c' && line[i][1] == 'y'))
			parse_count_objects(line[i], &count);
		else
			ft_error("invalid content of file");
	}
	parse_objects(line, scene, &count);
	scene->count = count;
}
