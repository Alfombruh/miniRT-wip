#include "../../includes/minirt.h"

int element_ambient_light(char **v, t_rt *rt)
{
	if (v[0] && v[1] && v[2] && !v[3])
	{
		rt->alight.ratio = ft_atod(v[1]);
		if (get_trgb(v[2], &rt->alight.tRGB))
			return (1);
	}
	else
		return (1);
	return (0);
}
int element_camera(char **v, t_rt *rt)
{
	if (v[0] && v[1] && v[2] && v[3] && !v[4])
	{
		if (get_coord(v[1], &rt->cam.coord))
			return (1);
		if (get_vector(v[2], &rt->cam.n))
			return (1);
		rt->cam.FOV = ft_atod(v[3]);
		if (rt->cam.FOV > 180 || rt->cam.FOV <= 0)
			return (1);
	}
	else
		return (1);
	return (0);
}

int element_light(char **v, t_rt *rt)
{
	if (v[0] && v[1] && v[2] && v[3] && !v[4])
	{
		get_coord(v[1], &rt->light.coord);//preguntar si devuelve 1
		rt->light.ratio = ft_atod(v[2]);
		// BONUS get_trgb(v[3], &rt->light.tRGB);//preguntar si devuelve 1
	}
	else
		return (1);
	return (0);
}

