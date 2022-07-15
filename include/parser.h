/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:41:24 by lemmon            #+#    #+#             */
/*   Updated: 2022/07/15 08:56:55 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "data.h"
# include "window.h"

// printf
# include <stdio.h>
// exit
# include <stdlib.h>
// open
# include <fcntl.h>
// read
# include <unistd.h>

//check_open
void	check_open(char *path, t_scene *scene);
int		check_extention(char *s);
//utils
void	ft_error(char *msg);
size_t	ft_strlen(const char *str);
void	count_separator(char *str, int *i, int *sep);
//atoi_atof
int		ft_atoi(const char *str);
float	ft_atof(char *str, int *i);
//parsing
void	parsing(t_scene *scene);
void	parse_objects(char **line, t_scene *scene, t_count *count);
void	create_objects(t_count count, t_scene *scene);
void	parse_count_objects(char *line, t_count *count);
void	parse_options(char *line, t_scene *scene);
//get_line_file
char	**get_line_file(int fd, t_scene *scene);
//split_rt
char	**ft_split_rt(char const *s, char c, t_scene *scene);
void	check_next_space(char *str, int *i);
void	check_digit(char *str, int i);
void	check_next_element(char *str, int i);
//parse_objects
void	parse_ambient_lightning(char *str, t_scene *scene);
t_vec3	parse_vector(char *str, int *i);
void	check_vector(t_vec3 vector);
void	parse_camera(char *str, t_scene *scene);
void	parse_cylinder(char *str, t_clnd *cylinder, t_scene *scene);
void	parse_light(char *str, t_scene *scene);
t_vec3	parsing_color(char *str, int i, t_scene *scene);
void	parse_plane(char *str, t_pln *plane, t_scene *scene);
void	parse_sphere(char *str, t_sphere *sphere, t_scene *scene);

#endif // PARSER_H