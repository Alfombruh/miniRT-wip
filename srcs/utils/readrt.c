#include "../../includes/minirt.h"
#include <fcntl.h>
#include <stdio.h>

static int get_values(char *line, t_rt *rt)
{
	char **s;
	int i = -1;

	(void) rt;
	s = ft_split(line, ' ');
	while (s[++i])
		printf("s[%d]=%s\n", i ,s[i]);
	i = -1;
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
