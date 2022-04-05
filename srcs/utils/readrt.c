#include "../../includes/minirt.h"
#include <fcntl.h>
#include <stdio.h>

static int fill_struct(char **s, t_rt *rt)
{
	if (!s[0])
		return (0);
	if (ft_strncmp(s[0], "A", 1))
		element_ambient_light(s, rt);
	else if (ft_strncmp(s[0], "C", 1))
		element_camera(s, rt);
	else if (ft_strncmp(s[0], "L", 1))
		element_light(s, rt);
	else if (ft_strncmp(s[0], "sp", 2))
		element_sphere(s, rt);
	else if (ft_strncmp(s[0], "pl", 2))
		element_plane(s, rt);
	else if (ft_strncmp(s[0], "cy", 2))
		element_cylinder(s, rt);
	else
		return (1);
	return (0);
}

static int get_values(char *line, t_rt *rt)
{
	char **s;
	int i = -1;

	(void) rt;
	printf("line is->%s\n", line);
	s = ft_split(line, ' ');
	if (fill_struct(s, rt))
		return (1);
	while (s[++i])
		free(s[i]);
	free(s);
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
