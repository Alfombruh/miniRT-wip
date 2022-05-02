#include <stdio.h>
#include "vectors.h"

int main()
{
	t_vec v = v_new(1, 0, 0);

	v = v_rotatey(v, 360);
	printf("v.x = %f v.y = %f v.z = %f\n", v.x, v.y, v.z);
	return 0;
}
