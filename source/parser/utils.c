/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:39:32 by lemmon            #+#    #+#             */
/*   Updated: 2022/07/11 15:41:12 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_error(char *msg)
{
	printf("Error: %s\n", msg);
	exit(1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	count_separator(char *str, int *i, int *sep)
{
	while (str[*i] == ' ')
		++(*i);
	if (str[*i] == ',')
	{
		++(*sep);
		++(*i);
	}
	while (str[*i] == ' ')
		++(*i);
}
