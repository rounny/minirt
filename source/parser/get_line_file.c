/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:34:40 by lemmon            #+#    #+#             */
/*   Updated: 2022/07/11 15:42:04 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*ft_chrjoin(char *s1, char s2)
{
	char	*tmp;
	long	i;

	i = -1;
	if (s1)
	{
		tmp = malloc(sizeof(char) * ((ft_strlen(s1) + 2)));
		if (!tmp)
			return (NULL);
		while (s1[++i])
			tmp[i] = s1[i];
		tmp[i] = s2;
		tmp[i + 1] = '\0';
		free (s1);
	}
	else
	{
		tmp = malloc(sizeof(char) * 2);
		if (!tmp)
			return (NULL);
		tmp[0] = s2;
		tmp[1] = '\0';
	}
	return (tmp);
}

char	**get_line_file(int fd, t_scene *scene)
{
	char	ch;
	char	*res;
	char	**string;

	res = NULL;
	string = NULL;
	if (fd >= 0)
	{
		if (read(fd, &ch, 1) == 0)
			ft_error("can't read the file, sorry..");
		res = ft_chrjoin(res, ch);
		while (read(fd, &ch, 1))
			res = ft_chrjoin(res, ch);
		res = ft_chrjoin(res, '\0');
		string = ft_split_rt(res, '\n', scene);
		if (!string)
			return (NULL);
		return (string);
	}
	return (NULL);
}
