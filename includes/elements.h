#ifndef ELEMENTS_H
#define ELEMENTS_H

#include "vectors.h"

typedef struct s_alight
{
	double	ratio; // ambient ligt ratio [0,1]
	int		tRGB; //RGB[0]=R RGB[1]=G RGB[2]=B
} t_alight;

typedef struct s_cam
{
	t_vec	coord; //[0]=x [1]=y [2]=z
	t_vec	n; // t_vector n; //normalized orientation vector [0]=x [1]=y [2]=z
	int		FOV; //Field Of View, campoo de vision [0-180]degrees
} t_cam;

typedef struct s_light
{
	double	ratio; // ambient ligt ratio [0,1] brightness
	t_vec	coord; //[0]=x [1]=y [2]=z
	// BONUS int	tRGB; //RGB[0]=R RGB[1]=G RGB[2]=B
} t_light;

typedef struct s_sph
{
	t_vec			coord; //[0]=x [1]=y [2]=z
	double			d; //diameter
	int				tRGB; //RGB[0]=R RGB[1]=G RGB[2]=B
	struct	s_sph	*next;
} t_sph;

typedef struct s_pl
{
	t_vec			coord; //[0]=x [1]=y [2]=z
	t_vec			n;  //normalized orientation vector [0]=x [1]=y [2]=z
	int				tRGB; //RGB[0]=R RGB[1]=G RGB[2]=B
	struct	s_pl	*next;
} t_pl;

typedef struct s_cy
{
	t_vec		coord; //[0]=x [1]=y [2]=z
	t_vec		n;  //normalized orientation vector [0]=x [1]=y [2]=z
	double		d; //diameter
	double		h; //height
	int			tRGB; //RGB[0]=R RGB[1]=G RGB[2]=B
	struct s_cy	*next;
} t_cy;

#endif 
