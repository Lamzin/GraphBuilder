#include "../Graph_build/Graph Builder/header.h"
#include "PointerFunction.h"
#include "../Graph_build/Graph Builder/MathFunction.h"
#include "GraphParser.h"

#define PI 3.14159265
#define Econst 2.7182818284

namespace QuickMathParser
{
	float funcPtr::funcPtrReturnValue(float a, float b)
	{
		return a;
	}

	float funcPtr::funcPtrCalcPowering(float a, float b)
	{
		return pow(a, b);
	}
	float funcPtr::funcPtrCalcMultiplication(float a, float b)
	{
		return a * b;
	}
	float funcPtr::funcPtrCalcDivision(float a, float b)
	{
		return (b != 0.0f) ? a / b : 0.0f;
	}
	float funcPtr::funcPtrCalcAddition(float a, float b)
	{
		return a + b;
	}
	float funcPtr::funcPtrCalcSubtraction(float a, float b)
	{
		return a - b;
	}
	float funcPtr::funcPtrCalcSinus(float a, float b)
	{
		return sin(a);
	}
	float funcPtr::funcPtrCalcCosinus(float a, float b)
	{
		return cos(a);
	}
	float funcPtr::funcPtrCalcTangens(float a, float b)
	{
		return tan(a);
	}
	float funcPtr::funcPtrCalcCotangens(float a, float b)
	{
		return 1 / tan(a);
	}
	float funcPtr::funcPtrCalcArcsinus(float a, float b)
	{
		return asin(a);
	}
	float funcPtr::funcPtrCalcArccosinus(float a, float b)
	{
		return acos(a);
	}
	float funcPtr::funcPtrCalcArctangens(float a, float b)
	{
		return atan(a);
	}
	float funcPtr::funcPtrCalcArccotangens(float a, float b)
	{
		return (float) PI - atan(a);
	}
	float funcPtr::funcPtrCalcFractionPart(float a, float b)
	{
		return MyMath::GetFractionalPart(a);
	}
	float funcPtr::funcPtrCalcIntegralPart(float a, float b)
	{
		return MyMath::GetIntegralPart(a);
	}

	float funcPtr::funcPtrCalcBrackets(float a, float b)
	{
		return a;
	}

	float funcPtr::funcPtrCalcModule(float a, float b)
	{
		return abs(a);
	}
	float funcPtr::funcPtrCalcLogarithmDecimal(float a, float b)
	{
		return log10(a);
	}
	float funcPtr::funcPtrCalcLogarithmNatural(float a, float b)
	{
		return log10(a) / log10((float) Econst);
	}
	float funcPtr::funcPtrCalcSpecialSqrt(float a, float b)
	{
		return sqrt(a);
	}
	float funcPtr::funcPtrCalcNotDetected(float a, float b)
	{
		return 0.0f;
	}
	float funcPtr::funcPtrCalcVariableFirst(float a, float b)
	{
		return 0.0f;
	}
	float funcPtr::funcPtrCalcConstPI(float a, float b)
	{
		return (float) PI;
	}
	float funcPtr::funcPtrCalcConstE(float a, float b)
	{
		return (float) Econst;
	}
	float funcPtr::funcPtrCalcValue(float a, float b)
	{
		return a;
	}
	float funcPtr::funcPtrCalcVarX(float a, float b)
	{
		return QuickMathParser::GraphParser::xtmp;
	}
	float funcPtr::funcPtrCalcVarY(float a, float b)
	{
		return QuickMathParser::GraphParser::ytmp;
	}
}