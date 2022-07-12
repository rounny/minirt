/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:03 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/12 07:54:35 by ccamie           ###   ########.fr       */
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
void	minirt(char *path);
void	check_options(char *path, t_scene *scene);
void	parsing(t_scene *scene);
int		terminate(t_scene *scene);

int		thread_for_draw(t_scene *scene);

int		key_down(t_key key, t_scene *scene);
int		key_up(t_key key, t_scene *scene);

int		mouse_down(int key, int x, int y, t_scene *scene);
int		mouse_up(int key, int x, int y, t_scene *scene);

#endif // MINIRT_H
