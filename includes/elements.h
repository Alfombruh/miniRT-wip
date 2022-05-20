/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 23:37:46 by jofernan          #+#    #+#             */
/*   Updated: 2022/05/20 23:38:09 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_H
# define ELEMENTS_H

# include "vectors.h"

typedef struct s_alight
{
	double	ratio;
	int		tRGB;
}			t_alight;

typedef struct s_cam
{
	t_vec		coord;
	t_vec		n;
	double		FOV;
}				t_cam;

typedef struct s_light
{
	double	ratio;
	t_vec	coord;
}			t_light;

typedef struct s_sph
{
	t_vec			coord;
	double			d;
	int				tRGB;
	struct s_sph	*next;
}					t_sph;

typedef struct s_pl
{
	t_vec			coord;
	t_vec			n;
	int				tRGB;
	struct s_pl		*next;
}					t_pl;

typedef struct s_cy
{
	int			tRGB;
	t_vec		coord;
	t_vec		n;
	double		d;
	double		h;
	struct s_cy	*next;
}				t_cy;

#endif 
