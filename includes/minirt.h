#ifndef MINIRT_H
#define MINIRT_H

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

#include "mlx.h"
#include "libft.h"
#include "elements.h"
#include "vectors.h"
#include <math.h>

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	struct s_rt	*rt;
}	t_mlx;

typedef struct s_rt
{	
	t_alight	alight;
	t_cam		cam;
	t_light		light;
	t_sph		*sph;
	t_pl		*pl;
	t_cy		*cy;
} t_rt;

//utils
int ft_argc(void);
int	ft_argvcheck(char *argv);
int ft_error(char *s, t_rt *rt);

int ft_readrt(char *argv, t_rt *rt);

int element_ambient_light(char **s, t_rt *rt);
int element_camera(char **s, t_rt *rt);
int element_light(char **s, t_rt *rt);
int element_sphere(char **s, t_rt *rt);
int element_plane(char **s, t_rt *rt);
int element_cylinder(char **s, t_rt *rt);

int	get_trgb(char *color, int *tRGB);
int get_coord(char *pos, double *coord);
int	get_vector(char *pos, t_vec *vec);

int free_double(char **str);
int free_struct(t_rt *rt);

int mlx_start(t_rt *rt);

#endif
