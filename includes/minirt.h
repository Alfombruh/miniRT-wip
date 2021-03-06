/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 23:37:56 by jofernan          #+#    #+#             */
/*   Updated: 2022/05/24 04:55:38 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WIDTH 1920
# define HEIGHT 1080

# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define YELLOW	"\033[0;33m"
# define BLUE 	"\033[0;34m"
# define PURPLE	"\033[0;35m"
# define CYAN	"\033[0;36m"
# define BOLD	"\033[0;1m"
# define CLOSE	"\033[0;0m"
# define BHRED	"\e[1;91m"
# define BHGRN	"\e[1;92m"
# define BHBLK "\e[1;90m"
# define BHYEL "\e[1;93m"
# define BHBLU "\e[1;94m"
# define BHMAG "\e[1;95m"
# define BHCYN "\e[1;96m"
# define BHWHT "\e[1;97m"
//color reference-> "https://www.theurbanpenguin.com/4184-2/"

# include "mlx.h"
# include "libft.h"
# include "elements.h"
# include "vectors.h"

typedef struct s_matrix
{
	double	m[4][4];
}	t_matrix;

typedef struct s_shame
{
	t_vec	hp;
	t_vec	n_light;
	double	mod;
	int		asd;
}	t_shame;

//an structure used to get the intersection of a ray and his values
typedef struct s_inter
{
	t_pl	*pl;
	t_cy	*cy;
	t_sph	*sph;
	int		type;
	int		color;
	double	dist;
}			t_inter;

typedef struct s_img
{
	void		*img;
	int			*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_img		img;
	struct s_rt	*rt;
}				t_mlx;

typedef struct s_rt
{	
	int			color;
	t_alight	alight;
	t_cam		cam;
	t_light		light;
	t_sph		*sph;
	t_pl		*pl;
	t_cy		*cy;
	t_inter		inter;
	t_matrix	m_cam;
}				t_rt;

//IO handler//
int		ft_argc(void);
int		ft_argvcheck(char *argv);
int		ft_error(char *s, t_rt *rt);
int		ft_readrt(char *argv, t_rt *rt);
//each elements fill function//
int		element_ambient_light(char **s, t_rt *rt);
int		element_camera(char **s, t_rt *rt);
int		element_light(char **s, t_rt *rt);
int		element_sphere(char **s, t_rt *rt);
int		element_plane(char **s, t_rt *rt);
int		element_cylinder(char **s, t_rt *rt);
//utils//
int		get_trgb(char *color, int *tRGB);
int		get_coord(char *pos, t_vec *vec);
int		get_vector(char *pos, t_vec *vec);
int		color_add(int trgb1, int trgb2);
int		color_scal(int trgb, double i);
void	trgb_rgb(int trgb, int rgb[3]);
//frees//
int		free_double(char **str);
int		free_struct(t_rt *rt);
void	free_pl(t_pl *pl);
void	free_sph(t_sph *sph);
void	free_cy(t_cy *cy);
//raytracing//
int		mlx_start(t_rt *rt);
int		start_raytrace(t_rt *rt, t_mlx *mlx, t_img *img);
void	ray_casting(t_rt *rt, t_vec ray);
double	sphere_intersection(t_sph *sph, t_vec ray, t_vec coord);
double	cylinder_intersection(t_cy *cy, t_vec ray, t_vec coord);
double	plane_intersection(t_pl *pl, t_vec ray, t_vec coord);
int		amb_light(int amb_color, int obj_color, double ratio);
int		diff_light(int obj, double l_ratio);
int		light_intersection(t_rt *rt, t_vec light);
//camera//
void	cam_to_origin(t_matrix *cam, t_rt *rt);
t_vec	place_ray(t_rt *rt, double i, double j);
t_vec	matrix_vector(t_matrix m, t_vec ray);
t_vec	ray_transform(t_rt *rt, t_vec ray);
//norminette//
int		sphlinked_fill(t_rt *rt, char **v);
void	sphlinked_new(t_rt *rt, t_sph *temp);
int		cylinked_fill(t_rt *rt, char **v);
void	cylinked_new(t_rt *rt, t_cy *temp);
void	plinked_new(t_rt *rt, t_pl *temp);

#endif
