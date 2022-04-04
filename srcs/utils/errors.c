#include "../../includes/minirt.h"
#include <stdio.h>

int ft_argvcheck(char *argv)
{
	char	*s;

	s = ft_substr(argv, ft_strlen(argv) - 3, 3);
	if (ft_strncmp(s, ".rt", 3) || ft_strlen(argv) == 3)
	{
		free(s);
		return (1);
	}
	else
	{
		free(s);
		return (0);
	}
}

int	ft_argc(void)
{
	printf(BHRED "Error\nProgram cannot be executed like that\n" CLOSE);
	printf(BOLD "use=>./miniRT *.rt\n" CLOSE);
	return (1);
}

int ft_error(char *s)
{
	printf(BHRED "Error\n%s\n" CLOSE, s);
	return (1);
}
