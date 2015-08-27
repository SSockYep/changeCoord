#include "CalcCoord.h"
#include <cstdlib>

using namespace std;

int main(int argc, char** argv)
{
	string inputFilename = argv[1];
	string outputFilename = argv[2];
	ifstream inputFile;
	ofstream outputFile;
	Offsets offsets;
	string temp;
	CalcParams params;
	vector<ImgCoord> imgCoords;
	vector<GeoCoord> geoCoords;
	ImgCoord imgCorner[4];
	GeoCoord geoCorner[4];
	int num;
	if (argc > 3)
		params.res = atof(argv[3]);

	calcScale(params);

	inputFile.open(inputFilename.c_str());
	outputFile.open(outputFilename.c_str());

	outputFile.precision(11);
	outputFile.setf(ios::fixed);

	inputFile >> offsets;
	outputFile << offsets;
	inputFile >> temp >> num;

	for (int i = 0; i < 4; i++)
	{
		inputFile >> imgCorner[i];
		inputFile >> geoCorner[i];
		outputFile << imgCorner[i] << ' ';
		outputFile << geoCorner[i] << endl;
	}

	imgCoords.resize(num);
	geoCoords.resize(num);

	for (int i = 0; i < num; i++)
	{
		inputFile >> imgCoords[i] >> geoCoords[i];
	}
	while (inputFile.eof() == false)
	{
		for (int i = 0; i < num; i++)
		{
			inputFile >> imgCoords[i] >> geoCoords[i];
			GeoCoord outCoord = calcNewCoord(geoCoords[i], params);
			outputFile << outCoord.x << ' ' << outCoord.y << ' ';
			outputFile << geoCoords[i] << endl;
		}
	}

	return 0;
}
