/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 01:33:42 by jofernan          #+#    #+#             */
/*   Updated: 2022/05/24 06:09:49 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include <stdio.h>

int	sphlinked_fill(t_rt *rt, char **v)
{
	if (get_coord(v[1], &rt->sph->coord))
		return (1);
	rt->sph->d = ft_atod(v[2]);
	if (get_trgb(v[3], &rt->sph->tRGB))
		return (1);
	return (0);
}

void	sphlinked_new(t_rt *rt, t_sph *temp)
{
	while (rt->sph->next)
		rt->sph = rt->sph->next;
	rt->sph->next = temp;
	rt->sph = rt->sph->next;
	rt->sph->next = NULL;
}

int	cylinked_fill(t_rt *rt, char **v)
{
	if (get_coord(v[1], &rt->cy->coord))
		return (1);
	if (get_vector(v[2], &rt->cy->n))
		return (1);
	rt->cy->d = ft_atod(v[3]);
	rt->cy->h = ft_atod(v[4]);
	if (get_trgb(v[5], &rt->cy->tRGB))
		return (1);
	return (0);
}

void	cylinked_new(t_rt *rt, t_cy *temp)
{
	while (rt->cy->next)
		rt->cy = rt->cy->next;
	rt->cy->next = temp;
	rt->cy = rt->cy->next;
	rt->cy->next = NULL;
}

void	plinked_new(t_rt *rt, t_pl *temp)
{
	while (rt->pl->next)
		rt->pl = rt->pl->next;
	rt->pl->next = temp;
	rt->pl = rt->pl->next;
	rt->pl->next = NULL;
}
