#include "../../includes/minirt.h"
#include <stdio.h>


////////////////////////COLOR//////////////////////////
int	get_trgb(char *color, int *tRGB)
{
	char **temp;
	int rgb[3];
	int i;
	
	temp = ft_split(color, ','); 
	if (temp[3] || !temp[1] || !temp[2] || !temp[0] || temp[2][0] == '\n')
		return (1);
	i = -1;
	while(temp[++i])
	{
		rgb[i] = ft_atoi(temp[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (1);
	}
	free_double(temp);
	*tRGB = 0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2];
	return (0);
}



////////////////////////COORD//////////////////////////
int get_coord(char *pos, double *coord)
{
	char	**temp;
	int		i;
	temp = ft_split(pos, ',');
	if (temp[3] || !temp[1] || !temp[2] || !temp[0])
		return (1);
	i = -1;
	while(temp[++i])
		coord[i] = ft_atod(temp[i]);
	free_double(temp);
	return (0);
}

////////////////////////VECTOR//////////////////////////
int get_vector(char *pos, t_vec *vec)
{
	char **temp;

	temp = ft_split(pos, ',');
	if (temp[3] || !temp[1] || !temp[2] || !temp[0])
		return (1);
	vec->x = ft_atoi(temp[0]);
	vec->y = ft_atoi(temp[1]);
	vec->z = ft_atoi(temp[2]);
	if (vec->x != -1 && vec->x != 1 && vec->x != 0)
		return (1);
	if (vec->y != -1 && vec->y != 1 && vec->y != 0)
		return (1);
	if (vec->z != -1 && vec->z != 1 && vec->z != 0)
		return (1);
	return (0);
}
