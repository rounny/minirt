/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnvtosh <ivnvtosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:04:28 by lemmon            #+#    #+#             */
/*   Updated: 2022/07/09 18:12:29 by ivnvtosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

size_t	ft_strlen(const char *str) // change into ft_strlen from libft
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


int	check_extention(char *s)
{
	size_t	len;

	len = ft_strlen(s); 
	if (s[len - 3] == '.' && s[len - 2] == 'r' && s[len - 1] == 't')
		return (0);
	return (1);
}

void	check_options(char *path, t_scene *scene)
{
	// char	*buf;


	// buf = NULL; // 
	scene->fd = open(path, O_RDONLY);
	if (scene->fd < 0)
		ft_error("can'r open the file, sorry..");
	if (check_extention(path))
		ft_error("only '.rt' extention");
}


