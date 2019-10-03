#include "randomnumbergenerator.h"
#include "math.h"
#include <stdlib.h>
#include <time.h>

bool RandomNumberGenerator::initiated = false;

int RandomNumberGenerator::randomInt(int from, int tillIncl)
{
	checkIfInitiated();
	return rand() % (tillIncl - from + 1) + from;
}

double RandomNumberGenerator::randomDouble(double from, double tillIncl, int precision)
{
	checkIfInitiated();
	if (precision > 10.0)
		throw "This function is not meant to go beyond point ten precision";
	precision = pow(10, precision);
	int fromAsInt = from * precision;
	int tillAsInt = tillIncl * precision;
	return (rand() % (tillAsInt - fromAsInt + 1) + fromAsInt) / double(precision);
}

void RandomNumberGenerator::checkIfInitiated()
{
	if (!initiated)
	{
		srand(time(0));
		initiated = true;
	}
}
