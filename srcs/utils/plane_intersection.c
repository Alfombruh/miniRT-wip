/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 23:39:22 by jofernan          #+#    #+#             */
/*   Updated: 2022/05/20 23:40:40 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include <stdio.h>

double	plane_intersection(t_pl *pl, t_vec ray, t_vec coord)
{
	return (v_dot(pl->n, v_sub(pl->coord, coord)) / v_dot(pl->n, ray));
}
