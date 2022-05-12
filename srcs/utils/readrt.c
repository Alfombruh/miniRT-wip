#include "../../includes/minirt.h"
#include <fcntl.h>
#include <stdio.h>

static void print_elements(t_rt *rt)
{
	int i = 1;
	t_sph	*temps = NULL;
	t_pl	*templ = NULL;
	t_cy	*tempcy = NULL;
	if (rt->sph)
		temps = rt->sph;
	if (rt->pl)
		templ = rt->pl;
	if (rt->cy)
		tempcy = rt->cy;
	if (rt->alight.ratio)
	{
		printf(BHGRN "Ambien Light Ratio==%f\n", rt->alight.ratio);
		printf("tRGB==%d\n" CLOSE, rt->alight.tRGB);
	}
	if (rt->cam.FOV)
	{
		printf(BHYEL "cam COORDS [x]=%f [y]=%f [z]=%f\n", rt->cam.coord.x, 
				rt->cam.coord.y, rt->cam.coord.z);
		printf("CAM vector [x]=%f [y]=%f [z]=%f\n", rt->cam.n.x, rt->cam.n.y, rt->cam.n.z);
		printf("FOV==%f\n" CLOSE, rt->cam.FOV);
	}
	if (rt->light.ratio)
	{
		printf(BHBLU "Light Ratio is==%f\n", rt->light.ratio);
		printf("light COORDS [x]=%f [y]=%f [z]=%f\n" CLOSE, rt->light.coord.x, 
				rt->light.coord.y, rt->light.coord.z);
	}
	while(rt->sph)
	{
		printf(BHMAG "SPH n[%d]\n", i);
		i++;
		printf("sph COORDS [x]=%f [y]=%f [z]=%f\n", rt->sph->coord.x, 
				rt->sph->coord.y, rt->sph->coord.z);
		printf("diameter==%f\n", rt->sph->d);
		printf("tRGB==%d\n" CLOSE, rt->sph->tRGB);
		rt->sph = rt->sph->next;
	}
	i = 1;
	while(rt->pl)
	{
		printf(BHCYN "PL n[%d]\n", i);
		i++;
		printf("pl COORDS [x]=%f [y]=%f [z]=%f\n", rt->pl->coord.x, 
				rt->pl->coord.y, rt->pl->coord.z);
		printf("pl vector [x]=%f [y]=%f [z]=%f\n", rt->pl->n.x, rt->pl->n.y, rt->pl->n.z);
		printf("tRGB==%d\n" CLOSE, rt->pl->tRGB);
		rt->pl = rt->pl->next;
	}
	i = 1;
	while(rt->cy)
	{
		printf(BHWHT "CY n[%d]\n", i);
		i++;
		printf("cy COORDS [x]=%f [y]=%f [z]=%f\n", rt->cy->coord.x, 
				rt->cy->coord.y, rt->cy->coord.z);
		printf("cy vector [x]=%f [y]=%f [z]=%f\n", rt->cy->n.x, rt->cy->n.y, rt->cy->n.z);
		printf("diameter==%f\n", rt->cy->d);
		printf("height==%f\n", rt->cy->h);
		printf("tRGB==%d\n" CLOSE, rt->cy->tRGB);
		rt->cy = rt->cy->next;
	}
	rt->sph = temps;
	rt->pl = templ;
	rt->cy = tempcy;
}

static int fill_struct(char **values, t_rt *rt)
{
	int i;

	i = 0;
	if (!values[0])
		return (0);
	if (!ft_strncmp(values[0], "A", 1))
		i = element_ambient_light(values, rt);
	else if (!ft_strncmp(values[0], "C", 1))
		i = element_camera(values, rt);
	else if (!ft_strncmp(values[0], "L", 1))
		i = element_light(values, rt);
	else if (!ft_strncmp(values[0], "sp", 2))
		i = element_sphere(values, rt);
	else if (!ft_strncmp(values[0], "pl", 2))
		i = element_plane(values, rt);
	else if (!ft_strncmp(values[0], "cy", 2))
		i =	element_cylinder(values, rt);
	else if (!ft_strncmp(values[0], "\n", 1))
		return (0);
	else
		return (1);
	return (i);
}

static int get_values(char *line, t_rt *rt)
{
	char **values;
	int i = -1;

	(void) rt;
	values = ft_split(line, ' ');
	if (fill_struct(values, rt))
		return (1);
	while (values[++i])
		free(values[i]);
	free(values);
	return(0);
}

int ft_readrt(char *argv, t_rt *rt)
{
	int		fd;
	char	*s;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return(1);
	s = get_next_line(fd);
	while (s)
	{
		if (get_values(s, rt))
		{
			free(s);
			return (1);
		}
		free(s);
		s = get_next_line(fd);
	}
	free(s);
	print_elements(rt);
	return (0);
}
