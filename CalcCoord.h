#ifndef CALCCOORD_H
#define CALCCOORD_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>

#define PI acos(-1)
#define DTOR (PI/180.0)

typedef struct ImgCoordinate
{
	int row;
	int col;
}ImgCoord;

typedef struct GeoCoordinate
{
	double x;
	double y;
	double z;
}GeoCoord;

typedef struct VariablesForCalculation
{
	double cen_lon;
	double radius_height;
	double scale;
	double res;
	VariablesForCalculation()
	{
		cen_lon = 155.0;
		radius_height = 3396000.0;
		res = 6.0;
	}
}CalcParams;

typedef struct OffsetAndScale
{
	float lineOff, sampOff, latOff, longOff, heightOff;
	float lineScale, sampScale, latScale, longScale, heightScale;
}Offsets;

inline std::istream& operator>>(std::istream& is, ImgCoord& ic)
{
	is >> ic.col >> ic.row; // image x, image y
	return is;
}

inline std::istream& operator>>(std::istream& is, GeoCoord& gc)
{
	is >> gc.x >> gc.y >> gc.z;
	return is;
}

inline std::istream& operator>>(std::istream& is, Offsets& o)
{
	std::string tmp;
	is >> tmp >> o.lineOff;
	is >> tmp >> o.sampOff;
	is >> tmp >> o.latOff;
	is >> tmp >> o.longOff;
	is >> tmp >> o.heightOff;
	is >> tmp >> o.lineScale;
	is >> tmp >> o.sampScale;
	is >> tmp >> o.latScale;
	is >> tmp >> o.longScale;
	is >> tmp >> o.heightScale;
	return is;
}

inline std::ostream& operator<<(std::ostream& os, ImgCoord& ic)
{
	os << ic.col << ' ' << ic.row; // image x, image y
	return os;
}

inline std::ostream& operator<<(std::ostream& os, GeoCoord& gc)
{
	os << gc.x << ' ' << gc.y << ' ' << gc.z;
	return os;
}

inline std::ostream& operator<<(std::ostream& os, Offsets& o)
{
	os << "LINE_OFF: " << o.lineOff << std::endl;
	os << "SAMP_OFF: " << o.sampOff << std::endl;
	os << "LAT_OFF: " << o.latOff << std::endl;
	os << "LONG_OFF: " << o.longOff << std::endl;
	os << "HEIGHT_OFF: " << o.heightOff << std::endl;
	os << "LINE_SCALE: " << o.lineScale << std::endl;
	os << "SAMP_SCALE: " << o.sampScale << std::endl;
	os << "LAT_SCALE: " << o.latScale << std::endl;
	os << "LONG_SCALE: " << o.longScale << std::endl;
	os << "HEIGHT_SCALE: " << o.heightScale << std::endl;
	return os;
}

void calcScale(CalcParams& cp);
GeoCoord calcNewCoord(const GeoCoord& gc, const CalcParams& params);
GeoCoord calcMapCoord(const GeoCoord corners[4], const GeoCoord& gc, const CalcParams& params);

#endif


