/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 23:39:15 by jofernan          #+#    #+#             */
/*   Updated: 2022/05/23 19:29:36 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include <math.h>

static int	light_sphere(t_rt *rt, t_vec light, double *dist, t_shame sh)
{
	t_sph	*temp;

	temp = rt->sph;
	while (rt->sph)
	{
		*dist = sphere_intersection(rt->sph, sh.n_light, light);
		if ((*dist > -0.99999999 && *dist < sh.mod)
			|| fabs(*dist - sh.mod) < 0.00000001)
		{
			rt->sph = temp;
			return (0);
		}
		rt->sph = rt->sph->next;
	}
	rt->sph = temp;
	return (1);
}

static int	light_plane(t_rt *rt, t_vec light, double *dist, t_shame sh)
{
	t_pl	*temp;

	temp = rt->pl;
	while (rt->pl)
	{
		*dist = plane_intersection(rt->pl, sh.n_light, light);
		if ((*dist > -0.99999999 && *dist < sh.mod)
			|| fabs(*dist - sh.mod) < 0.00000001)
		{
			rt->pl = temp;
			return (0);
		}
		rt->pl = rt->pl->next;
	}
	rt->pl = temp;
	return (1);
}

static int light_cylinder(t_rt *rt, t_vec light, double *dist, t_shame sh)
{
	t_cy	*temp;

	temp = rt->cy;
	while (rt->cy)
	{
		*dist = cylinder_intersection(rt->cy, sh.n_light, light);
		if ((*dist > -0.99999999 && *dist < sh.mod)
			|| fabs(*dist - sh.mod) < 0.00000001)
		{
			rt->cy = temp;
			return (0);
		}
		rt->cy = rt->cy->next;
	}
	rt->cy = temp;
	return (1);
}


int	light_intersection(t_rt *rt, t_vec light)
{
	double	dist;
	t_shame	sh;

	dist = 0;
	ft_memset(&sh, 0, sizeof(sh));
	sh.mod = v_mod(v_sub(rt->light.coord, light));
	sh.n_light = v_normalize(v_sub(rt->light.coord, light));
	if (light_sphere(rt, light, &dist, sh) == 0)
		return (0);
	else if (light_plane(rt, light, &dist, sh) == 0)
		return (0);
	else if (light_cylinder(rt, light, &dist, sh) == 0)
		return (0);
	return (1);
}
