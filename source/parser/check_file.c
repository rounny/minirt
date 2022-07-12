/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_open.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:04:28 by lemmon            #+#    #+#             */
/*   Updated: 2022/07/11 18:02:02 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_extention(char *s)
{
	size_t	len;

	len = ft_strlen(s);
	if (s[len - 3] == '.' && s[len - 2] == 'r' && s[len - 1] == 't')
		return (0);
	return (1);
}

void	check_open(char *path, t_scene *scene)
{
	scene->fd = open(path, O_RDONLY);
	if (scene->fd < 0)
		ft_error("can'r open the file, sorry..");
	if (check_extention(path))
		ft_error("only '.rt' extention");
}
