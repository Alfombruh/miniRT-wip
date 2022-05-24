/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 23:39:13 by jofernan          #+#    #+#             */
/*   Updated: 2022/05/24 06:24:49 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include <stdlib.h>

int	free_double(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	return (1);
}

void	free_cy(t_cy *cy)
{
	t_cy	*temp;

	if (!cy)
		return ;
	while (cy->next)
	{
		temp = cy;
		cy = cy->next;
		free(temp);
	}
	free(cy);
}

void	free_sph(t_sph *sph)
{
	t_sph	*temp;

	if (!sph)
		return ;
	while (sph->next)
	{
		temp = sph;
		sph = sph->next;
		free(temp);
	}
	free(sph);
}

void	free_pl(t_pl *pl)
{
	t_pl	*temp;

	if (!pl)
		return ;
	if (!pl->next)
	{
		free(pl);
		return ;
	}
	while (pl->next)
	{
		temp = pl;
		pl = pl->next;
		free(temp);
	}
}

int	free_struct(t_rt *rt)
{
	free_pl(rt->pl);
	free_sph(rt->sph);
	free_cy(rt->cy);
	return (0);
}
