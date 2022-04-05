#include "../../includes/minirt.h"



////////////////////////COLOR//////////////////////////
int	get_trgb(char *color, int *tRGB)
{
	//255,255,,,,,,,,,,255 el split lo aceptaria, esta bien?
	//valor mas alto que 255
	char **temp;
	int rgb[3];
	int i;
	
	temp = ft_split(color, ','); 
	if (temp[3])
		return (1);
	i = -1;
	while(temp[++i])
		rgb[i] = ft_atoi(temp[i]);
	free_double(temp);//free double
	tRGB = 0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2];
}



////////////////////////COORD//////////////////////////
int get_coord(char *pos, double **coord)
{
	//255,255,,,,,,,,,,255 el split lo aceptaria, esta bien?
	int i;
	char **temp;

	temp = ft_split(pos, ','); 
	if (temp[3])
		return (1);
	i = -1;
	while(temp[++i])
		coord[i] = ft_atod(temp[i]);
	free_double(temp);//free double
	return (0);
}

////////////////////////VECTOR//////////////////////////
int get_vector(char *pos, double **coord)
{
	///solo 1     / 0
	//considerar la opcion de meterno en una stuct s_vector, sino en un array de ints. 
}
