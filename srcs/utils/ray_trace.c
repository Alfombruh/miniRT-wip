/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 23:39:30 by jofernan          #+#    #+#             */
/*   Updated: 2022/05/24 06:38:00 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include <math.h>
#include <stdio.h>

static t_vec	object_normal(t_inter inter, t_vec hp, t_vec r)
{
	if (inter.type == 1)
		return (v_normalize(v_sub(hp, inter.sph->coord)));
	else if (inter.type == 2)
	{	
		if (v_dot(r, inter.pl->n) / (v_mod(r) * v_mod(inter.pl->n)) > 0)
			return (v_normalize(v_scal(inter.pl->n, -1)));
		return (v_normalize(inter.pl->n));
	}
	else if (inter.type == 3)
	{
		if (v_mod(v_sub(hp, v_add(inter.cy->coord, v_scal(v_normalize
							(inter.cy->n), inter.cy->h)))) < (inter.cy->d / 2))
			return (inter.cy->n);
		if (v_mod(v_sub(hp, inter.cy->coord)) < (inter.cy->d / 2))
			return (v_scal(inter.cy->n, -1));
		return (v_normalize(v_sub(hp, v_add(inter.cy->coord, v_scal(inter.cy->n
							, v_dot(v_sub(hp, inter.cy->coord),
								v_normalize(inter.cy->n)))))));
	}
	else
		return (v_new(0, 0, 0));
}

static int	ray_tracing(t_rt *rt, t_vec ray)
{
	t_vec	hp;
	t_vec	n;
	t_vec	vl;
	double	ls;
	int		color[2];

	hp = v_add(v_scal(ray, rt->inter.dist), rt->cam.coord);
	n = object_normal(rt->inter, hp, ray);
	if (n.x == 0 && n.y == 0 && n.z == 0)
		return (0);
	vl = v_normalize(v_sub(rt->light.coord, hp));
	color[0] = amb_light(rt->alight.trgb, rt->inter.color, rt->alight.ratio);
	ls = rt->light.ratio * v_dot(n, v_normalize(v_sub(rt->light.coord, hp)));
	if (ls < 0)
		ls = 0;
	else
		ls *= 1.5;
	color[1] = color_scal(diff_light(rt->inter.color, rt->light.ratio), ls);
	if (light_intersection(rt, v_add(vl, hp)) == 1)
		return (color_add(color[0], color[1]));
	else
		return (color[0]);
}

int	start_raytrace(t_rt *rt, t_mlx *mlx, t_img *img)
{
	int		i;
	int		j;
	t_vec	ray;

	j = -1;
	cam_to_origin(&rt->m_cam, rt);
	while (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
		{
			ray = place_ray(rt, i, j);
			ray = ray_transform(rt, ray);
			ray_casting(rt, ray);
			img->addr[j * img->line_len + i] = ray_tracing(rt, ray);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
	return (0);
}
