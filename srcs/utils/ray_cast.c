/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 23:39:28 by jofernan          #+#    #+#             */
/*   Updated: 2022/05/24 06:38:13 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include <math.h>
#include <stdio.h>

static void	ray_sphere(double *dist, double *catched, t_rt *rt, t_vec ray)
{
	t_sph	*temp;

	temp = rt->sph;
	while (rt->sph)
	{
		*dist = sphere_intersection(rt->sph, ray, rt->cam.coord);
		if (*dist < *catched && *dist > 0 && *dist < 1000)
		{
			rt->inter.dist = *dist;
			rt->inter.color = rt->sph->trgb;
			rt->inter.sph = rt->sph;
			rt->inter.type = 1;
			*catched = *dist;
		}
		rt->sph = rt->sph->next;
	}
	rt->sph = temp;
}

static void	ray_plane(double *dist, double *catched, t_rt *rt, t_vec ray)
{
	t_pl	*temp;

	temp = rt->pl;
	while (rt->pl)
	{
		*dist = plane_intersection(rt->pl, ray, rt->cam.coord);
		if (*dist < *catched && *dist > 0 && *dist < 1000)
		{
			rt->inter.dist = *dist;
			rt->inter.color = rt->pl->trgb;
			rt->inter.pl = rt->pl;
			rt->inter.type = 2;
			*catched = *dist;
		}
		rt->pl = rt->pl->next;
	}
	rt->pl = temp;
}

static void	ray_cylinder(double *dist, double *catched, t_rt *rt, t_vec ray)
{
	t_cy	*temp;

	temp = rt->cy;
	while (rt->cy)
	{
		*dist = cylinder_intersection(rt->cy, ray, rt->cam.coord);
		if (*dist < *catched && *dist > 0 && *dist < 1000)
		{
			rt->inter.dist = *dist;
			rt->inter.color = rt->cy->trgb;
			rt->inter.cy = rt->cy;
			rt->inter.type = 3;
			*catched = *dist;
		}
		rt->cy = rt->cy->next;
	}
	rt->cy = temp;
}

void	ray_casting(t_rt *rt, t_vec ray)
{
	double	dist;
	double	catched;

	dist = 0;
	catched = INFINITY;
	rt->inter.type = 0;
	rt->inter.color = 0;
	ray_sphere(&dist, &catched, rt, ray);
	ray_plane(&dist, &catched, rt, ray);
	ray_cylinder(&dist, &catched, rt, ray);
}
