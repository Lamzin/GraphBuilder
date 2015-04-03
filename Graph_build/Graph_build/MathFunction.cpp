#include <Windows.h>
#include <d2d1.h>
#include <math.h>
#include <string>
#include <vcclr.h>

using namespace std;

#include "MathFunction.h"
#include "GraphProperties.h"
#include "Render.h"
#include "Parser\Parser.h"

using namespace Render;
using namespace MathParser;

#define FRAC GetFractionalPart
#define INTEG GetIntegralPart

float MyMath::Math::GetIntegralPart(float tmp)
{
	float fract, integ;
	fract =  modf(tmp, &integ);
	if (tmp < 0)
	{
		integ = integ - 1;
	}
	return integ;
}

float MyMath::Math::GetFractionalPart(float tmp)
{
	float fract, integ;
	fract =  modf(tmp, &integ);
	if (tmp < 0)
	{
		fract = fract + 1;
	}
	return fract;
}

float MyMath::Math::MainFunction(float x)
{
	Parser Name(Renderer::MathExpression , x);
	return Name.GetValue();
};

float MyMath::Math::MainFunction(float x, int param)
{
	switch (param)
	{
	case 0:
		return (float) pow(2, INTEG(x));
		break;
	case 1:
		return (float) pow(3, INTEG(x)) + 1;
		break;
	case 2:
		return x*x;
		break;
	case 3:
		return INTEG(x*x);
		break;
	case 4:
		return INTEG(x*x);
		break;
	case 5:
		return INTEG(x)*INTEG(x);
		break;
	case 6:
		return INTEG(x)*INTEG(x);
		break;
	case 7:
		return acos(x);
		break;
	case 8:
		return acos(INTEG(x));
		break;
	default:
		return 0;
		break;
	}
};