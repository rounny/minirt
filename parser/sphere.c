#include "../minirt.h"

void	parse_sphere(char *str, t_scene *scene)
{
	int	i;

	i = 0;
	printf("flag - %d\n", scene->sphere.flag_sp);
	if (scene->sphere.flag_sp == 0)
		scene->sphere.flag_sp = 1;
	else
		ft_error("dublicate of options");
	check_next_element(str, i);
	scene->sphere.coordinates = parse_xyz(str, &i);
	check_digit(str, i);
	scene->sphere.diameter = ft_atof(str, &i);
	// printf("diameter 0 |%f|\n", scene->sphere.diameter);
	scene->sphere.color = parsing_color(str, i, scene);
// 	printf("x - |%f|\n", scene->sphere.coordinates.x);
// 	printf("y - |%f|\n", scene->sphere.coordinates.y);
// 	printf("z - |%f|\n", scene->sphere.coordinates.z);
// 	printf("r - |%d|\n", scene->sphere.rgb.r);
// 	printf("g - |%d|\n", scene->sphere.rgb.g);
// 	printf("b - |%d|\n", scene->sphere.rgb.b);
}
