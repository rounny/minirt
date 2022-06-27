#include "../minirt.h"

void	parse_light(char *str, t_scene *scene)
{
	int	i;

	i = 0;
	if (scene->light.flag_L == 0)
		scene->light.flag_L = 1;
	else
		ft_error("dublicate of options");
	check_next_element(str, i);
	scene->light.coordinates = parse_xyz(str, &i);
	check_digit(str, i);
	scene->light.bright = ft_atof(str, &i);
	if (scene->light.bright > 1.0 || scene->light.bright < 0.0)
		ft_error("invalid argument");
	scene->light.color = parsing_color(str, i, scene);
	// printf("x - |%f|\n", scene->light.coordinates.x);
	// printf("y - |%f|\n", scene->light.coordinates.y);
	// printf("z - |%f|\n", scene->light.coordinates.z);
	// // printf("str - %c\n", str[i]);
	// // printf("str - %c\n", str[i + 1]);
	// printf("r - |%d|\n", scene->light.rgb.r);
	// printf("g - |%d|\n", scene->light.rgb.g);
	// printf("b - |%d|\n", scene->light.rgb.b);

}