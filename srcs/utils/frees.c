#include "../../includes/minirt.h"
#include <stdlib.h>

int free_double(char **str)
{
	int i;

	i = -1;
	while(str[++i])
		free(str[i]);
	free(str);
	return (1);
}
/*
static void free_cy(t_cy *cy)
{
	t_cy *temp;
	t_cy *free;

	if (!cy)
		return ;
	while(cy->next)
	{
		free = cy;
		temp = cy->next;
		free(free);
		cy = temp;
	}
	free(cy);
}*/
static void free_sph(t_sph *sph)
{
	t_sph *temp;

	if (!sph)
		return ;
	while(sph->next)
	{
		temp = sph;
		sph = sph->next;
		free(temp);
	}
	free(sph);
}
/*
static void free_pl(t_pl *pl)
{
	t_pl *temp;
	t_pl *free;

	if (!pl)
		return ;
	while(pl->next)
	{
		free = pl;
		temp = pl->next;
		free(free);
		pl = temp;
	}
}*/

int free_struct(t_rt *rt)
{
	//free_pl(rt->pl);
	free_sph(rt->sph);
	//free_cy(rt->cy);
	//free(rt);
	return (0);
}
