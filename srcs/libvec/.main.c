#include <stdio.h>
#include "vectors.h"

int main()
{
	t_vec v = v_new(2, 0, 0);
	t_vec w = v_new(2, 0, 0);
	double d = v_dot(v, w);
	printf("dot is 0 || %f \n", d);
	//printf("v.x = %f v.y = %f v.z = %f\n", v.x, v.y, v.z);
	return 0;
}
