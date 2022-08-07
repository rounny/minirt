/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:44:26 by lemmon            #+#    #+#             */
/*   Updated: 2022/08/07 19:41:03 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_plane(char *str, t_pln *plane, t_scene *scene)
{
	int	i;

	i = 0;
	check_next_element(str, i);
	plane->location = parse_vector(str, &i);
	plane->location.z *= -1;
	plane->vector = parse_vector(str, &i);
	check_vector(plane->vector);
	plane->color = parsing_color(str, i, scene);
}
