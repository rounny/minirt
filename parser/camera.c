#include "../minirt.h"

t_vec3 parse_xyz(char *str, int *i)
{
	t_vec3	matrix;
	int		separator;

	separator = 0;
	matrix.x = ft_atof(str, i);
	// printf("x - %f\n", matrix.x);
	count_separator(str, i, &separator);
	// printf("str - %c\n", str[*i]);
	check_next_element(str, *i);
	matrix.y = ft_atof(str, i);
	count_separator(str, i, &separator);
	check_next_element(str, *i);
	matrix.z = ft_atof(str, i);
	// printf("separator - %d\n", separator);
	if (separator != 2)
		ft_error("invalid argument(separator)");
	return(matrix);
}

void	check_vector(t_vec3 vector)
{
	if ((vector.x > 1 || vector.x < -1) || (vector.y > 1 || vector.y < -1)
	|| (vector.z > 1 || vector.z < -1))
		ft_error("invalid argument(vector)");
}

void	parse_camera(char *str, t_scene *scene)
{
	int	i;

	i = 0;
	if (scene->camera.flag_C == 0)
		scene->camera.flag_C = 1;
	else
		ft_error("dublicate of sceneions");
	check_next_element(str, i);
	scene->camera.coordinates = parse_xyz(str, &i);
	scene->camera.vector = parse_xyz(str, &i);
	check_vector(scene->camera.vector);
	check_next_element(str, i);
	scene->camera.fov = ft_atoi2(&str[i]);
	if (scene->camera.fov > 180 || scene->camera.fov < 0)
		ft_error("invalid argument(fov)");
	check_next_space(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
		++i;
	check_next_space(str, &i);
	if (str[i])
		ft_error("invalid argument...");
	// printf("x - |%f|\n", scene->camera.coordinates.x);
	// printf("y - |%f|\n", scene->camera.coordinates.y);
	// printf("z - |%f|\n", scene->camera.coordinates.z);
	// printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n");
	// printf("x - |%f|\n", scene->camera.vector.x);
	// printf("y - |%f|\n", scene->camera.vector.y);
	// printf("z - |%f|\n", scene->camera.vector.z);
	// printf("for - |%d|\n", scene->camera.fov);

}