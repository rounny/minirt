
#include "../minirt.h"

void	parse_ambient_lightning(char *str, t_scene *scene)
{
	int		i;

	i = 0;
	if (scene->ambient.flag_A == 0)
		scene->ambient.flag_A = 1;
	else
		ft_error("dublicate of options");
	check_digit(str, i); // возможно стоит поменять на check_next_element
	scene->ambient.lighting = ft_atof(str, &i);
	if (scene->ambient.lighting > 1.0 || scene->ambient.lighting < 0.0)
		ft_error("invalid argument");
	// printf("float %f\n", opt->amb.lighting);
	scene->ambient.color = parsing_color(str, i, scene);
	// printf("r - |%d|\n", scene->ambient.color.x);
	// printf("g - |%d|\n", scene->ambient.color.y);
	// printf("b - |%d|\n", scene->ambient.color.z);
}
