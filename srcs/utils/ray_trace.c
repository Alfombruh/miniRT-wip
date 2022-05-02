#include "../../includes/minirt.h"
#include <math.h>
#include <stdio.h>
/*
static void ray_origin(t_rt *rt)
{
	rt->ray.r = rt->cam.n;
	rt->ray.r = v_normalize(rt->ray.r);
	rt->ray.o = rt->cam.coord;
	rt->ray.o = v_normalize(rt->ray.o);
}
*/
//https://www.youtube.com/watch?v=KBK6g6RFgdA
//Tenemos el vector de la camara (cam->v) y un vector que mira hacia arriba (up)
////////////////////////////////////////////////////////////////////////////////
//cam->v y up forman un plano, el vector u es perpendicular a este plano
//por lo cual el producto vectorial entre cam->v y up nos da el vector u
//este vector u representa el eje x en el canvas
///////////////////////////////////////////////////////////////////////////////
//cam->v y el vector u tambien forman un plano, el vector v es perpndicular a este plano
//asi que haciendo lo mismo que en el anterior paso calculamos el vecot v
//este vector v representa el eje y en nuestro canvas
/////////////////////////////////////////////////////
//minuto 7:20 
////////////////////////////////////////////////
/*static t_matrix cam_to_origin(t_cam *cam)
{
	t_vec up;
	t_vec u;
	t_vec v;
	t_matrix M;
	
	up = v_new(0, 1, 0);
	u = v_normalize(v_cross(up, cam->n));
	v = v_normalize(v_cross(cam->n, u));
	M.m[0][0] = u.x;
	M.m[0][1] = u.y;
	M.m[0][2] = u.z;
	M.m[0][3] = 0;
	M.m[1][0] = u.x;
	M.m[1][1] = u.y;
	M.m[1][2] = u.z;
	M.m[1][3] = 0;
	M.m[2][0] = cam->n.x;be 
	M.m[2][1] = cam->n.y;
	M.m[2][2] = cam->n.z;
	M.m[2][3] = 0;
	M.m[3][0] = cam->coord.x;
	M.m[3][1] = cam->coord.y;
	M.m[3][2] = cam->coord.z;
	M.m[3][3] = 1;
	return (M);
}
*/
//places ray in the cam
//https://www.youtube.com/watch?v=_DHW3KhqR40
static t_vec place_ray(t_rt *rt, double i, double j)
{

	//EDURNE
	t_vec 	ray;
	double	x;
	double	y;
	//
	x = (rt->cam.FOV / 2.0) - (((rt->cam.FOV / 2.0) / ((double)WIDTH / 2.0)) * i);
	y = (rt->cam.FOV / 2.0) - (((rt->cam.FOV / 2.0) / ((double)HEIGHT / 2.0)) * j);
	//
	ray = v_rotatez(rt->cam.n, x);
	ray = v_rotatey(rt->cam.n, y);
//if (j == HEIGHT / 2)
//		printf ("x=%f && y=%f && z=%f\n", ray.x, ray.y, ray.z);
	return (ray);
	//
	//ojo!!! cuando ese int sea mayor que fov/2 la rotacion que le debemos mandar es negativa para que rote restando a la posicion de origen.
	//



//	return (v_new(x, y, z));
	//JAMBO VIDEO RtX
/*	(void) rt;
	double	u;
	double	v;

	//ray_origin(rt);
	u = i - ((double)WIDTH / 2.0) + ((double)HEIGHT / 2.0) / (double) HEIGHT * 2 *  - 1;
	v = -(j / (double) HEIGHT * 2 - 1);
	return (v_new(u, v, 0));
*/	//JOSE
/*
	double	x;
	double	y;
	double	VOF;
	double	a_ratio; //aspect ratio, 16:9 by default

	x = i;
	y = j;
	//ray_origin(rt);
	VOF = tan(((double)rt->cam.FOV / (2.0 * M_PI)) / 180.0); 
	a_ratio = (double)WIDTH / (double)HEIGHT;
	x = (2 * (x + 0.5) / (double)WIDTH - 1) * VOF * a_ratio;
	y = (1 - 2 * (y + 0.5) / (double)HEIGHT - 1) * VOF;
	return (v_new(-x, y, 1));
	*/
}

static t_vec ray_casting(t_rt *rt, t_vec ray, int *color)
{
	t_vec	target;

	(void) target;
	ray = v_normalize(ray);
	//printf("vector is:\nv.x==%f\tv.y==%f\tv.z==%f\n", ray.x, ray.y, ray.z);
	if (sphere_intersection(rt->sph, ray) != -1)
		*color = rt->sph->tRGB;
	// targe = ray * cam matrix
	// target - cam coord
	// norm(target)
	// ray[0] = cam.coord
	// ray[1] = target
	// return (ray);
	return ((t_vec) ray);
}

int start_raytrace(t_rt *rt, t_mlx *mlx, t_img *img)
{
	int	i;
	int	j;
	int color;
	t_vec ray;

	j = -1;
	color = 0;
	//rt->m_cam = cam_to_origin(&rt->cam); //places cam at O
	while (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
		{
			ray = place_ray(rt, i, j);
			ray_casting(rt, ray, &color);
			img->addr[j * img->line_len + i] = color; 
			color = 0;
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
	return (0);
}
