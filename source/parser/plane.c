/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:44:26 by lemmon            #+#    #+#             */
/*   Updated: 2022/07/11 15:47:23 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_plane(char *str, t_pln *plane, t_scene *scene)
{
	int	i;

	i = 0;
	check_next_element(str, i);
	plane->location = parse_vector(str, &i);
	plane->vector = parse_vector(str, &i);
	check_vector(plane->vector);
	plane->color = parsing_color(str, i, scene);
}
