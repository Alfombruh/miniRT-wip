#include "../../includes/minirt.h"

int element_ambient_light(char **v, t_rt *rt)
{
	if (v[2] && !v[3])
	{
		rt->alight.ratio = ft_atod(v[1]);
		get_rgb(v[2], &rt->alight.tRGB);//preguntar si devuelve 1
	}
	else
		return (1);
	return (0);
}

int element_camera(char **v, t_rt *rt)
{
	//FOV (0-180);
	if (v[3] && !v[4])
	{
		get_coord(v[2], &rt->cam.coord);//preguntar si devuelve 1
		//get_vector(); //struct vs array
		rt->cam.FOV = ft_atoi(v[3]);
	}
	else
		return (1);
	return 0;
}

int element_light(char **v, t_rt *rt)
{
	if (v[2] && !v[3])
	{
		rt->light.ratio = ft_atod(v[1]);
		get_coord(v[2], &rt->light.coord);//preguntar si devuelve 1
		// BONUS get_rgb(v[2], &rt->light.tRGB);//preguntar si devuelve 1
	}
	else
		return (1);
	return 0;
}

