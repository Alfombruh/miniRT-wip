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
//color reference-> "https://www.theurbanpenguin.com/4184-2/"

#include "../srcs/libft/libft.h"
#include "../mlx/mlx.h"
#include <math.h>

typedef struct s_alight
{
	float	ratio; // ambient ligt ratio [0,1]
	int		RGB[3]; //RGB[0]=R RGB[1]=G RGB[2]=B
} t_alight;

typedef struct s_cam
{
	float	coord[3]; //[0]=x [1]=y [2]=z
	int		n[3];  //normalized orientation vector [0]=x [1]=y [2]=z
	int		FOV; //Field Of View, campoo de vision
} t_cam;

typedef struct s_light
{
	float	ratio; // ambient ligt ratio [0,1]
	float	coord[3]; //[0]=x [1]=y [2]=z
	float	bright; // brightness
	// BONUS int		RGB[3]; //RGB[0]=R RGB[1]=G RGB[2]=B
} t_light;

typedef struct s_sph
{
	float			coord[3]; //[0]=x [1]=y [2]=z
	float			d; //diameter
	int				RGB[3]; //RGB[0]=R RGB[1]=G RGB[2]=B
	struct	s_sph	*next;
} t_sph;

typedef struct s_pl
{
	float			coord[3]; //[0]=x [1]=y [2]=z
	int				n[3];  //normalized orientation vector [0]=x [1]=y [2]=z
	int				RGB[3]; //RGB[0]=R RGB[1]=G RGB[2]=B
	struct	s_pl	*next;
} t_pl;

typedef struct s_cy
{
	float		coord[3]; //[0]=x [1]=y [2]=z
	int			n[3];  //normalized orientation vector [0]=x [1]=y [2]=z
	float		d; //diameter
	float		h; //height
	int			RGB[3]; //RGB[0]=R RGB[1]=G RGB[2]=B
	struct s_cy	*next;
} t_cy;

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
int ft_error(char *s);

int ft_readrt(char *argv, t_rt *rt);

#endif
