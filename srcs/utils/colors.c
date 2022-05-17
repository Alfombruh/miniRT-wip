#include "../../includes/minirt.h"

int	amb_light(int amb_color, int obj_color, double ratio)
{
	int a_rgb[3];
	int o_rgb[3];

	trgb_rgb(amb_color, a_rgb);
	trgb_rgb(obj_color, o_rgb);
	a_rgb[0] = (double)a_rgb[0] * ratio * (double)o_rgb[0] / 255.0;
	a_rgb[1] = (double)a_rgb[1] * ratio * (double)o_rgb[1] / 255.0;
	a_rgb[2] = (double)a_rgb[2] * ratio * (double)o_rgb[2] / 255.0;
	return (0 << 24 | a_rgb[0] << 16 | a_rgb[1] << 8 | a_rgb[2]);
}

int	diff_light(int obj, double l_ratio)
{
	int d_rgb[3];
	int o_rgb[3];

	trgb_rgb(obj, o_rgb);
	d_rgb[0] = l_ratio * 255.0 * (double)o_rgb[0];
	d_rgb[1] = l_ratio * 255.0 * (double)o_rgb[1];
	d_rgb[2] = l_ratio * 255.0 * (double)o_rgb[2];
	return (0 << 24 | d_rgb[0] << 16 | d_rgb[1] << 8 | d_rgb[2]);
}

void trgb_rgb(int trgb, int rgb[3])
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
