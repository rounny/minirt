#include "minirt.h"

int	ft_atoi_rt(const char *str)
{
	size_t	i;
	int		num;
	// int		count_num;
	size_t		j;

	// count_num = 0;
	i = 0;
	num = 0;
	j = 0;
	while (str[j])
	{
		if ((str[j] >= '0' && str[j] <= '9') || str[j] == ' ')
			j++;
		// else
		// 	ft_error("wrong color argument");
	}
	while (str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i++] - '0';
	}
	if (num < 0 || num > 255)
		ft_error("wrong color argument");
	return (num);
}

void	ft_error(char *msg)
{
	printf("Error: %s\n", msg);
	exit(1);
}

char	*ft_chrjoin(char *s1, char s2)
{
	char	*tmp;
	long	i;

	i = -1;
	if (s1)
	{
		tmp = malloc(sizeof(char) * ((ft_strlen2(s1) + 2)));
		if (!tmp)
			return (NULL);
		while (s1[++i])
			tmp[i] = s1[i];
		tmp[i] = s2;
		tmp[i + 1] = '\0';
		free (s1);
	}
	else
	{
		tmp = malloc(sizeof(char) * 2);
		if (!tmp)
			return (NULL);
		tmp[0] = s2;
		tmp[1] = '\0';
	}
	return (tmp);
}

char	**get_line_file(int fd, t_scene *scene)
{
	char	ch;
	char	*res;
	char	**string;
	// int		i;

	// i = -1;
	res = NULL;
	string = NULL;
	if (fd >= 0)
	{
		while (read(fd, &ch, 1))
			res = ft_chrjoin(res, ch);
		res = ft_chrjoin(res, '\0'); // 
		string = ft_split_rt(res, '\n', scene); //
		if (!string)
			return (NULL);
		return (string);
	}
	return (NULL);
}
