#include "../../includes/minirt.h"

int free_double(char **str)
{
	int i;

	i = -1;
	while(str[++i])
		free(str[i]);
	free(str);
	return (1);
}

int free_struct(t_rt *rt)
{

}
