#ifndef ELEMENTS_H
#define ELEMENTS_H

typedef struct s_alight
{
	double	ratio; // ambient ligt ratio [0,1]
	int		RGB[3]; //RGB[0]=R RGB[1]=G RGB[2]=B
} t_alight;

typedef struct s_cam
{
	double	coord[3]; //[0]=x [1]=y [2]=z
	int		n[3];  //normalized orientation vector [0]=x [1]=y [2]=z
	int		FOV; //Field Of View, campoo de vision [0-180]
} t_cam;

typedef struct s_light
{
	double	ratio; // ambient ligt ratio [0,1]
	double	coord[3]; //[0]=x [1]=y [2]=z
	double	bright; // brightness
	// BONUS int		RGB[3]; //RGB[0]=R RGB[1]=G RGB[2]=B
} t_light;

typedef struct s_sph
{
	double			coord[3]; //[0]=x [1]=y [2]=z
	double			d; //diameter
	int				RGB[3]; //RGB[0]=R RGB[1]=G RGB[2]=B
	struct	s_sph	*next;
	struct	s_sph	*tail;
} t_sph;

typedef struct s_pl
{
	double			coord[3]; //[0]=x [1]=y [2]=z
	int				n[3];  //normalized orientation vector [0]=x [1]=y [2]=z
	int				RGB[3]; //RGB[0]=R RGB[1]=G RGB[2]=B
	struct	s_pl	*next;
	struct	s_pl	*tail;
} t_pl;

typedef struct s_cy
{
	double		coord[3]; //[0]=x [1]=y [2]=z
	int			n[3];  //normalized orientation vector [0]=x [1]=y [2]=z
	double		d; //diameter
	double		h; //height
	int			RGB[3]; //RGB[0]=R RGB[1]=G RGB[2]=B
	struct s_cy	*next;
	struct s_cy	*tail;
} t_cy;

#endif 
