#include "parser.h"

static void	check_color(int color)
{
	if (color > 255 || color < 0)
		ft_error("invalid color");
}

t_vec3	parsing_color(char *str, int i, t_scene *scene)
{
	t_vec3	color;
	int		separator;

	separator  = 0;
	(void)scene;
	// printf("str5 - %c\n", str[i]);
	check_next_space(str, &i);
	color.x = ft_atoi2(&(str[i]));
	check_color(color.x);
	while (str[i] >= '0' && str[i] <= '9')
		++i;
	count_separator(str, &i, &separator);
	// printf("sep2 - %d\n", separator);
	// if (!str[i] || str[i] < '0' || str[i] > '9')
	// 	--separator;
	color.y = ft_atoi2(&str[i]);
	check_color(color.y);
	while (str[i] >= '0' && str[i] <= '9')
		++i;
	count_separator(str, &i, &separator);
	if (!str[i] || str[i] < '0' || str[i] > '9')
		--separator;
	color.z = ft_atoi2(&(str[i]));
	check_color(color.z);
	while (str[i] == ' ' || (str[i] >= '0' && str[i] <= '9'))
		++i;
	// printf("sep - %d\n", separator);
	if (str[i] || separator != 2)
		ft_error("invalid color parameters");
	// printf("sep - %d\n", separator);
	// printf("str6 - %c\n", str[i]);
	return (color);

}