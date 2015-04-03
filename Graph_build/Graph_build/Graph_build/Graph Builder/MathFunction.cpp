#include "header.h"
#include "MathFunction.h"

using namespace std;

float MyMath::GetIntegralPart(float tmp)
{
	float fract, integ;
	fract =  modf(tmp, &integ);
	if (tmp < 0 && tmp != integ)
	{
		integ = integ - 1;
	}
	return integ;
}

float MyMath::GetFractionalPart(float tmp)
{
	float fract, integ;
	fract =  modf(tmp, &integ);
	if (tmp < 0)
	{
		fract = fract + 1;
	}
	return fract;
}