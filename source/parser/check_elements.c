/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:20:39 by lemmon            #+#    #+#             */
/*   Updated: 2022/07/11 18:01:54 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_digit(char *str, int i)
{
	while (str[i] == ' ')
		++i;
	if (str[i] < '0' || str[i] > '9')
		ft_error("invalid argument");
}

void	check_next_space(char *str, int *i)
{
	while (str[*i] == ' ')
		++(*i);
}

void	check_next_element(char *str, int i)
{
	while (str[i] == ' ')
		++i;
	if (str[i] == '-')
		++i;
	if (str[i] > '9' || str[i] < '0')
		ft_error("invalid argument_3");
}
