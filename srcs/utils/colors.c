#include "../../includes/minirt.h"

static void trgb_rgb(int trgb, int rgb[3])
{
	rgb[0] = (trgb >> 16) & 0xFF;
	rgb[1] = (trgb >> 8) & 0xFF;
	rgb[2] = trgb & 0xFF;
}

int color_add(int trgb1, int trgb2)
{
	int	rgb1[3];
	int	rgb2[3];
	int total[3];

	trgb_rgb(trgb1, rgb1);
	trgb_rgb(trgb2, rgb2);
	total[0] = rgb1[0] + rgb2[0];
	total[1] = rgb1[1] + rgb2[1];
	total[2] = rgb1[2] + rgb2[2];
	return (0 << 24 | total[0] << 16 | total[1] << 8 | total[2]);
}
