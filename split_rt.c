/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_rt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:25:24 by lemmon            #+#    #+#             */
/*   Updated: 2022/06/21 21:23:56 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minirt.h"

static int	ft_found_word_rt(char const *s, char c)
{
	int	countword;
	int	i;

	if (s == NULL || (c == 0 && ft_strlen2(s) == 0))
		return (0);
	countword = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			countword++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (countword);
}

static void	ft_free_memory_split_rt(char **matrix, int x)
{
	x--;
	while (x >= 0)
	{
		free(matrix[x]);
		x--;
	}
	free(matrix);
}

static char	**ft_create_rt(char **matrix, int countword, char const *s, char c)
{
	int		i;
	int		x;
	int		lenword;

	i = 0;
	x = -1;
	while (++x < countword)
	{
		lenword = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			lenword++;
		}
		matrix[x] = (char *)malloc(sizeof(char) * (lenword + 1));
		if (matrix[x] == NULL)
		{
			ft_free_memory_split_rt(matrix, x);
			return (NULL);
		}
		matrix[x][lenword] = '\0';
	}
	return (matrix);
}

static char	**ft_saveword_rt(char **matrix, int countword, char const *s, char c)
{
	int	y;
	int	i;
	int	x;

	i = 0;
	x = -1;
	while (++x < countword)
	{
		while (s[i] == c)
			i++;
		y = 0;
		while (s[i] != c && s[i] != '\0')
		{
			matrix[x][y] = s[i];
			i++;
			y++;
		}
		matrix[x][y] = '\0';
	}
	matrix[x] = NULL;
	return (matrix);
}

char	**ft_split_rt(char const *s, char c, t_scene *scene)
{
	char	**matrix;
	int		countword;

	countword = ft_found_word_rt(s, c);
	// opt->count_line = countword;
	if (scene->flag_line == 0)
	{
		scene->count_line = countword;
		scene->flag_line = 1;
	}
	scene->count_argc = countword;
	matrix = (char **)malloc(sizeof(char *) * (countword + 1));
	if (matrix == NULL)
		return (NULL);
	matrix = ft_create_rt(matrix, countword, s, c);
	if (matrix == NULL)
		return (NULL);
	matrix = ft_saveword_rt(matrix, countword, s, c);
	return (matrix);
}