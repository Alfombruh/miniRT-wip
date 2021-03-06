/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 23:39:04 by jofernan          #+#    #+#             */
/*   Updated: 2022/05/24 00:59:21 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include <math.h>

// https://www.youtube.com/watch?v=UTz7ytMJ2yk
// really cool RT in cpp series
// http://www.irisa.fr/prive/kadi/Master_Recherche/cours_CTR/RayTracing.pdf
// those are some slides about raytracing

static double	get_root(double a, double b, double c, double d)
{
	double	root;

	if (d < 0)
		root = -a / b;
	else
		root = (c - a) / b;
	return (root);
}

//n && p are not vectors, they are double but as I cannot use functions that
//are longer than 25 lines and declare more than 5 variables
//Im forced to do this
double	cylinder_intersection(t_cy *cy, t_vec ray, t_vec coord)
{
	t_vec	n;
	t_vec	p;
	t_vec	sub;
	t_vec	multh;

	multh = v_scal(v_normalize(cy->n), cy->h);
	p.z = v_dot(multh, multh);
	sub = v_sub(coord, cy->coord);
	n.x = p.z - v_dot(multh, ray) * v_dot(multh, ray);
	n.y = p.z * v_dot(sub, ray) - v_dot(multh, sub) * v_dot(multh, ray);
	n.z = p.z * v_dot(sub, sub) - v_dot(multh, sub)
		* v_dot(multh, sub) - (cy->d / 2) * (cy->d / 2) * p.z;
	p.y = n.y * n.y - n.x * n.z;
	if (p.y < 0)
		return (-1);
	p.x = (-n.y - pow(p.y, 0.5)) / n.x;
	p.y = v_dot(multh, sub) + p.x * v_dot(multh, ray);
	if (p.y > 0 && p.y < p.z)
		return (p.x);
	p.y = get_root(v_dot(multh, sub), v_dot(multh, ray), p.z, p.y);
	if (fabs(n.y + n.x * p.y) < pow((n.y * n.y - n.x * n.z), 0.5))
		return (p.y);
	return (-1);
}
