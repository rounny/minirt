/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnvtosh <ivnvtosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:06 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/09 18:43:46 by ivnvtosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "data.h"

// printf
# include <stdio.h>
// exit
# include <stdlib.h>
// open
# include <fcntl.h>
// read
#include <unistd.h>

#include "window.h"

//check_options
void	check_options(char *path, t_scene *scene);
int		check_extention(char *s);
//parsing
void	parsing(t_scene *scene);
//get_line_file
char	**get_line_file(int fd, t_scene *scene);
char	*ft_chrjoin(char *s1, char s2);
void	ft_error(char *msg);
int		ft_atoi_rt(const char *str);


//split_rt
char	**ft_split_rt(char const *s, char c, t_scene *scene);

size_t	ft_strlen(const char *str);
void	count_separator(char *str, int *i, int *sep);
void	check_next_space(char *str, int *i);
void	check_digit(char *str, int i);
void	check_next_element(char *str, int i);

void	parse_ambient_lightning(char *str, t_scene *scene);
t_vec3 parse_xyz(char *str, int *i);
void	check_vector(t_vec3 vector);
void	parse_camera(char *str, t_scene *scene);

void	parse_cylinder(char *str, t_clnd *cylinder, t_scene *scene);
void	parse_light(char *str, t_scene *scene);
t_vec3	parsing_color(char *str, int i, t_scene *scene);
void	create_objects(t_count count, t_scene *scene);
void	parse_objects(char **line, t_scene *scene, t_count *count);
void	parse_plane(char *str, t_pln *plane, t_scene *scene);
void	parse_sphere(char *str, t_sphere *sphere, t_scene *scene);
int	ft_atoi2(const char *str);
float	ft_atof(char *str, int *i);



#endif // PARSER_H
