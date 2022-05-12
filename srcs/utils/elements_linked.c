#include "../../includes/minirt.h"

int element_sphere(char **v, t_rt *rt)
{
	t_sph	*temp;
	t_sph	*head;
	
	if (v[0] && v[1] && v[2] && v[3] && !v[4])
	{
		temp = (t_sph *)malloc(sizeof(t_sph));
		if (!rt->sph)
		{
			rt->sph = temp;
			head = rt->sph;
		}
		else
		{
			head = rt->sph;
			while (rt->sph->next)
				rt->sph = rt->sph->next;
			rt->sph->next = temp;
			rt->sph = rt->sph->next;
		}
		if (get_coord(v[1], &rt->sph->coord))
			return (1);
		rt->sph->d = ft_atod(v[2]);
		if (get_trgb(v[3], &rt->sph->tRGB))
			return (1);
		rt->sph->next = NULL;
		rt->sph = head;
	}
	else
		return (1);
	return (0);
}

int element_plane(char **v, t_rt *rt)
{
	t_pl *temp;
	t_pl *head;

	if (v[0] && v[1] && v[2] && v[3] && !v[4])
	{
		temp = (t_pl *)malloc(sizeof(t_pl));
		if (!rt->pl)
		{
			rt->pl = temp;
			head = rt->pl;
		}
		else
		{
			head = rt->pl;
			while (rt->pl->next)
				rt->pl = rt->pl->next;
			rt->pl->next = temp;
			rt->pl = rt->pl->next;
		}
		if (get_coord(v[1], &rt->pl->coord))
			return (1);
		if (get_vector(v[2], &rt->pl->n))
			return (1);
		if (get_trgb(v[3], &rt->pl->tRGB))
			return (1);
		rt->pl->next = NULL;
		rt->pl = head;
	}
	else
		return (1);
	return (0);
}

int element_cylinder(char **v, t_rt *rt)
{
	t_cy 	*temp;
	t_cy	*head;

	if (v[0] && v[1] && v[2] && v[3] && v[4] && v[5] && !v[6])
	{
		temp = (t_cy *)malloc(sizeof(t_cy));
		if (!rt->cy)
		{
			rt->cy = temp;
			head = rt->cy;
		}
		else
		{
			head = rt->cy;
			while (rt->cy->next)
				rt->cy = rt->cy->next;
			rt->cy->next = temp;
			rt->cy = rt->cy->next;
		}
		if (get_coord(v[1], &rt->cy->coord))
			return (1);
		if (get_vector(v[2], &rt->cy->n))
			return (1);
		rt->cy->d = ft_atod(v[3]);
		rt->cy->h = ft_atod(v[4]);
		if (get_trgb(v[5], &rt->cy->tRGB))
			return (1);
		rt->cy->next = NULL;
		rt->cy = head;
	}
	else
		return (1);
	return (0);
}
