
#include "minirt.h"

size_t	ft_strlen2(const char *str) // change into ft_strlen from libft
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


int	check_extention(char *s)
{
	size_t	len;

	len = ft_strlen2(s); // change into ft_strlen() from libft
	if (s[len - 3] == '.' && s[len - 2] == 'r' && s[len - 1] == 't')
		return (0);
	return (1);
}

void	check_options(int ac, char **av, t_scene *scene)
{
	char	*buf;

	buf = NULL;
	scene->fd = open(av[ac - 1], O_RDONLY);
	if (scene->fd < 0)
		ft_error("can'r open the file, sorry..");
	if (check_extention(av[1]))
		ft_error("only '.rt' extention");
	if (read(scene->fd, &buf, 1) <= 0)
		ft_error("can't read the file, sorry..");
}

int main(int ac, char **av)
{
	t_scene	scene;

	scene = (t_scene){};
	// scene.amb = (t_amb){};
	if (ac != 2)
		ft_error("wrong number of arguments");
	check_options(ac, av, &scene);
	parsing(&scene);
	return (0);
}