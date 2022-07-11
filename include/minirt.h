/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:03 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/11 18:06:50 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "data.h"
# include "window.h"
# include "mlx.h"
# include "utils.h"

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

void	draw(t_scene scene);
void	event(t_scene *scene);
int		key_pressed(int key, t_scene *scene);
void	minirt(char *path);
void	check_open(char *path, t_scene *scene);
void	parsing(t_scene *scene);
int		terminate(t_scene *scene);

int		mouse_pressed(int key, int x, int y, t_scene *scene);
int		mouse_released(int key, int x, int y, t_scene *scene);

#endif // MINIRT_H
