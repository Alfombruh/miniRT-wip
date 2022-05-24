/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_linked.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 23:39:06 by jofernan          #+#    #+#             */
/*   Updated: 2022/05/24 06:36:57 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	element_sphere(char **v, t_rt *rt)
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
			rt->sph->next = NULL;
		}
		else
		{
			head = rt->sph;
			sphlinked_new(rt, temp);
		}
		if (sphlinked_fill(rt, v))
			return (1);
		rt->sph = head;
	}
	else
		return (1);
	return (0);
}

int	element_plane(char **v, t_rt *rt)
{
	t_pl	*temp;
	t_pl	*head;

	if (v[0] && v[1] && v[2] && v[3] && !v[4])
	{
		temp = (t_pl *)malloc(sizeof(t_pl));
		if (!rt->pl)
		{
			rt->pl = temp;
			head = rt->pl;
			rt->pl->next = NULL;
		}
		else
		{
			head = rt->pl;
			plinked_new(rt, temp);
		}
		if (get_coord(v[1], &rt->pl->coord) || get_vector(v[2], &rt->pl->n)
			|| get_trgb(v[3], &rt->pl->trgb))
			return (1);
		rt->pl = head;
	}
	else
		return (1);
	return (0);
}

int	element_cylinder(char **v, t_rt *rt)
{
	t_cy	*temp;
	t_cy	*head;

	if (v[0] && v[1] && v[2] && v[3] && v[4] && v[5] && !v[6])
	{
		temp = (t_cy *)malloc(sizeof(t_cy));
		if (!rt->cy)
		{
			rt->cy = temp;
			head = rt->cy;
			rt->cy->next = NULL;
		}
		else
		{
			head = rt->cy;
			cylinked_new(rt, temp);
		}
		if (cylinked_fill(rt, v))
			return (1);
		rt->cy = head;
	}
	else
		return (1);
	return (0);
}
