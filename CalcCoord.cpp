#include "CalcCoord.h"

using namespace std;

void calcScale(CalcParams& cp)
{
	cp.scale = (2*PI*cp.radius_height)/360.0;
}


GeoCoord calcNewCoord(const GeoCoord& gc, const CalcParams& params)
{
	GeoCoord result;
	double x_cor, y_cor;
	x_cor = params.scale*(gc.x-params.cen_lon)*cos(gc.y*DTOR);
	y_cor = params.scale*gc.y;

	result.x = x_cor;
	result.y = y_cor;
	result.z = gc.z;

	return result;
}

GeoCoord calcMapCoord(const GeoCoord corners[4], const GeoCoord& gc, const CalcParams& params)
{
	GeoCoord result;
	double x_min, y_min;

	GeoCoord newCorners[4];

	for(int i = 0; i < 4; i++)
		newCorners[i] = calcNewCoord(corners[i], params);

	x_min = newCorners[0].x;
	y_min = newCorners[0].y;

	for(int i = 1; i < 4; i++)
	{
		if (x_min > newCorners[i].x)
			x_min = newCorners[i].x;

		if (y_min > newCorners[i].y)
			y_min = newCorners[i].y;
	}

	result.x = (gc.x - x_min) / params.res;
	result.y = (gc.y - y_min) / params.res;
	result.z = gc.z;


	return result;
}


