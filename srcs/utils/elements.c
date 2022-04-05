#include "../../includes/minirt.h"

int element_ambient_light(char **s, t_rt *rt)
{
	if (s[1])
		rt->alight.ratio = ft_atod(s[1]);
	else
		return (1);
	return (0);
}

int element_camera(char **s, t_rt *rt)
{
	(void) s;
	(void) rt;
	return 0;
}

int element_light(char **s, t_rt *rt)
{
	(void) s;
	(void) rt;
	return 0;
}

