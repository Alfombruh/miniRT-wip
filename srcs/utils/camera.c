#include "../../includes/minirt.h"
#include <math.h>

//https://www.youtube.com/watch?v=ggHSrlrP5zI 
//a quick video about cameras in a raytracer
//This function makes a matrix thas is gonna be used to transform the cam rays so we can move our cam
void	cam_to_origin(t_matrix *cam, t_rt *rt)
{
	t_vec	up;
	t_vec	right;
	t_vec	new;

	if (rt->cam.n.x == 0 && (rt->cam.n.y == 1 || rt->cam.n.y == -1) && rt->cam.n.z == 0)
			new = v_new(0,0,1);
	else
			new = v_new(0,1,0);
	right = v_normalize(v_cross(new, rt->cam.n));
	up = v_cross(rt->cam.n, right);
	cam->m[0][0] = right.x;
	cam->m[0][1] = right.y;
	cam->m[0][2] = right.z;
	cam->m[0][3] = 0; 
	cam->m[1][0] = up.x;
	cam->m[1][1] = up.y;
	cam->m[1][2] = up.z;
	cam->m[1][3] = 0;
	cam->m[2][0] = rt->cam.n.x;
	cam->m[2][1] = rt->cam.n.y;
	cam->m[2][2] = rt->cam.n.z;
	cam->m[2][3] = 0;
	cam->m[3][0] = rt->cam.coord.x;
	cam->m[3][1] = rt->cam.coord.y;
	cam->m[3][2] = rt->cam.coord.z;
	cam->m[3][3] = 1;
}

t_vec place_ray(t_rt *rt, double i, double j)
{
	double	x;
	double	y;
	double	a_ratio;

	a_ratio = (double) WIDTH / (double) HEIGHT;
	x = (2.0 * ((i + 0.5) / (double) WIDTH) - 1.0) * a_ratio * tan((rt->cam.FOV / 2.0) * (M_PI / 180.0));
	y = (1.0 - (2.0 * (j + 0.5) / (double) HEIGHT)) *  tan((rt->cam.FOV / 2.0) * (M_PI / 180.0));
	return (v_new(-x, y, 1)); //orientamos la camara hacia z en 1 por convencion
}

t_vec matrix_vector(t_matrix m,	t_vec ray)
{
	t_vec	new;

	new.x = m.m[0][0] * ray.x + m.m[1][0] * ray.y + m.m[2][0] * ray.z + m.m[3][0];
	new.y = m.m[0][1] * ray.x + m.m[1][1] * ray.y + m.m[2][1] * ray.z + m.m[3][1];
	new.z = m.m[0][2] * ray.x + m.m[1][2] * ray.y + m.m[2][2] * ray.z + m.m[3][2];
	return (new);
}

t_vec ray_transform(t_rt *rt, t_vec ray)
{
	ray = matrix_vector(rt->m_cam, ray);
	ray = v_sub(ray, rt->cam.coord);
	ray = v_normalize(ray);
	return (ray);
}
