#include "../../includes/minirt.h"

int element_sphere(char **s, t_rt *rt)
{
	if (v[3] && !v[4])
	{
		get_coord(v[1], &rt->sph.coord);//preguntar si devuelve 1
		rt->sph.d = ft_atod(v[2]);
		get_rgb(v[3], &rt->sph.tRGB);//preguntar si devuelve 1
	}
	else
		return (1);
	//PUNTERO A NEXT?????
	return 0;
}

int element_plane(char **s, t_rt *rt)
{
	if (v[3] && !v[4])
	{
		get_coord(v[1], &rt->pl.coord);//preguntar si devuelve 1
		//get_vector(); //struct vs array
		get_rgb(v[3], &rt->pl.tRGB);//preguntar si devuelve 1
	}
	else
		return (1);
	//PUNTERO A NEXT?????
	return 0;
}

int element_cylinder(char **s, t_rt *rt)
{
	if (v[5] && !v[6])
	{
		get_coord(v[1], &rt->cy.coord);//preguntar si devuelve 1
		//get_vector(); //struct vs array
		rt->cy.d = ft_atod(v[3]);
		rt->cy.h = ft_atod(v[4]);
		get_rgb(v[5], &rt->cy.tRGB);//preguntar si devuelve 1
	}
	else
		return (1);
	//PUNTERO A NEXT?????
	return 0;
}

////////alloc linked/////////
	/*
	if (!rt->cy)
	{
		rt->cy = (t_cy *)malloc(sizeof(t_cy));
		rt->cy->next = NULL;
		//function that allocates a 3 value string sepatared by commas (x3)
	}
	*/
