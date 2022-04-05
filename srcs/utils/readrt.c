#include "../../includes/minirt.h"
#include <fcntl.h>
#include <stdio.h>

static int fill_struct(char **values, t_rt *rt)
{
	int i;

	i = 0;
	if (!s[0])
		return (0);
	if (ft_strncmp(values[0], "A", 1))
		i = element_ambient_light(values, rt);
	else if (ft_strncmp(values[0], "C", 1))
		i = element_camera(values, rt);
	else if (ft_strncmp(values[0], "L", 1))
		i = element_light(values, rt);
	else if (ft_strncmp(values[0], "sp", 2))
		i = element_sphere(values, rt);
	else if (ft_strncmp(values[0], "pl", 2))
		i = element_plane(values, rt);
	else if (ft_strncmp(values[0], "cy", 2))
		i =	element_cylinder(values, rt);
	else
		return (1);
	return (i);
}

static int get_values(char *line, t_rt *rt)
{
	char **s;
	int i = -1;

	(void) rt;
	printf("line is->%s\n", line);
	values = ft_split(line, ' ');
	if (fill_struct(values, rt))
		return (1);
	while (values[++i])
		free(values[i]);
	free(values);
	return(0);
}

int ft_readrt(char *argv, t_rt *rt)
{
	int		fd;
	char	*s;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return(1);
	s = get_next_line(fd);
	while (s)
	{
		if (get_values(s, rt))
		{
			free(s);
			return (1);
		}
		free(s);
		s = get_next_line(fd);
	}
	free(s);
	return (0);
}
