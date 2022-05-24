/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 23:37:46 by jofernan          #+#    #+#             */
/*   Updated: 2022/05/24 06:42:20 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_H
# define ELEMENTS_H

# include "vectors.h"

typedef struct s_alight
{
	double	ratio;
	int		trgb;
}			t_alight;

typedef struct s_cam
{
	t_vec		coord;
	t_vec		n;
	double		fov;
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
	int				trgb;
	struct s_sph	*next;
}					t_sph;

typedef struct s_pl
{
	t_vec			coord;
	t_vec			n;
	int				trgb;
	struct s_pl		*next;
}					t_pl;

typedef struct s_cy
{
	int			trgb;
	t_vec		coord;
	t_vec		n;
	double		d;
	double		h;
	struct s_cy	*next;
}				t_cy;

#endif 
