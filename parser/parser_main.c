#include "../minirt.h"

void	check_next_element(char *str, int i)
{
	while (str[i] == ' ')
		++i;
	if (str[i] == '-') // являются ли "+" валидными ????
		++i;
	if (str[i] > '9' || str[i] < '0')
		ft_error("invalid argument_3");
}


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

void	parsing(t_scene *scene)
{
	char	**line;
	int		i;

	i = -1;
	line = get_line_file(scene->fd, scene);
	if (scene->count_line != 6)
		ft_error("wrong number of optins"); // ONLY 6 ARGUMENTS FOR MINIRT
	while (++i < scene->count_line)
	{
		scene->count_argc = 0;
		if (line[i][0] == 'A')
			parse_ambient_lightning(line[i] + 1, scene);
		else if (line[i][0] == 'C')
			parse_camera(line[i] + 1, scene);
		else if (line[i][0] == 'L')
			parse_light(line[i] + 1, scene);
		else if (line[i][0] == 's' && line[i][1] == 'p')
			parse_sphere(line[i] + 2, scene);
		else if (line[i][0] == 'p' && line[i][1] == 'l')
			parse_plane(line[i] + 2, scene);
		else if (line[i][0] == 'c' && line[i][1] == 'y')
			parse_cylinder(line[i] + 2, scene);
		else
			ft_error("invalid content of file");
	}
	
	for (int j = 0; j < scene->count_argc; ++j)
		printf("|%s|\n", line[j]);
}