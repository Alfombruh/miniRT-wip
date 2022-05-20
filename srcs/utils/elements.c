/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 23:39:09 by jofernan          #+#    #+#             */
/*   Updated: 2022/05/20 23:45:24 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include <math.h>

int	element_ambient_light(char **v, t_rt *rt)
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

int	element_camera(char **v, t_rt *rt)
{
	if (v[0] && v[1] && v[2] && v[3] && !v[4])
	{
		if (get_coord(v[1], &rt->cam.coord))
			return (1);
		if (get_vector(v[2], &rt->cam.n))
			return (1);
		if (fabs(rt->cam.n.x + rt->cam.n.y + rt->cam.n.z) != 1)
			return (1);
		if (fabs(rt->cam.n.x) == 1 && rt->cam.n.y != 0 && rt->cam.n.z != 0)
			return (1);
		if (fabs(rt->cam.n.y) == 1 && rt->cam.n.x != 0 && rt->cam.n.z != 0)
			return (1);
		if (fabs(rt->cam.n.z) == 1 && rt->cam.n.y != 0 && rt->cam.n.x != 0)
			return (1);
		rt->cam.FOV = ft_atod(v[3]);
		if (rt->cam.FOV > 180 || rt->cam.FOV <= 0)
			return (1);
	}
	else
		return (1);
	return (0);
}

int	element_light(char **v, t_rt *rt)
{
	if (v[0] && v[1] && v[2] && v[3] && !v[4])
	{
		get_coord(v[1], &rt->light.coord);
		rt->light.ratio = ft_atod(v[2]);
	}
	else
		return (1);
	return (0);
}
