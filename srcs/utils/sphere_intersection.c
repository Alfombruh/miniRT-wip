/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 23:39:37 by jofernan          #+#    #+#             */
/*   Updated: 2022/05/24 01:09:03 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include <math.h>
#include <stdio.h>

static int	sphere_inside(double t0, double t1)
{
	t0 = t1;
	if (t0 < 0)
		return (-1);
	else
		return (t0);
}

static void	double_swap(double *i, double *j)
{
	double	temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

double	sphere_intersection(t_sph *sph, t_vec ray, t_vec coord)
{
	t_vec	l;
	double	tc[2];
	double	t[2];
	double	dd;
	double	r;

	r = sph->d / 2;
	l = v_sub(sph->coord, coord);
	tc[0] = v_dot(l, ray);
	if (tc[0] < 0)
		return (-1);
	dd = v_dot(l, l) - (tc[0] * tc[0]);
	if (dd > (r * r))
		return (-1);
	tc[1] = pow((r * r) - dd, 0.5);
	t[0] = tc[0] - tc[1];
	t[1] = tc[0] + tc[1];
	if (t[1] < t[0])
		double_swap(&t[0], &t[1]);
	if (t[0] < 0)
		return (sphere_inside(t[0], t[1]));
	return (t[0]);
}
