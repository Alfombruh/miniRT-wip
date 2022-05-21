/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 23:39:37 by jofernan          #+#    #+#             */
/*   Updated: 2022/05/21 19:54:58 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include <math.h>
#include <stdio.h>

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
	double	tca;
	double	thc;
	double	t0;
	double	t1;
	double	dd;
	double	r;
	
	r = sph->d / 2;
	l = v_sub(sph->coord, coord) ;
	tca = v_dot(l, ray);
	if (tca < 0)
		return (-1);
	dd = v_dot(l, l) - (tca * tca);
	if (dd > (r * r))
		return (-1);
	thc = pow((r * r) - dd, 0.5);
	t0 = tca - thc;
	t1 = tca + thc;
	if (t1 < t0)
		double_swap(&t0, &t1);
	if (t0 < 0)
	{
		t0 = t1;
		if (t0 < 0)
			return (-1);
	}
	return (t0);
}
