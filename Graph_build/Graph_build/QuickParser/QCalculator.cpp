#include "../Graph_build/Graph Builder/header.h"
#include "QParser.h"
#include "../Graph_build/Graph Builder/MathFunction.h"

using namespace QuickMathParser;

#define PI 3.14159265
#define Econst 2.7182818284

ReturnStruct QParser::CalculatorCDefault_one(CalculatorEnum op, int lparam, int rparam)
{
	pair <int, int> a = make_pair(lparam, rparam);

	ReturnStruct ret(op, a);

	return ret;
}

ReturnStruct QParser::CalculatorCDefault_two(CalculatorEnum op, int lparam1, int rparam1, int lparam2, int rparam2)
{
	pair <int, int> a = make_pair(lparam1, rparam1),
		b = make_pair(lparam2, rparam2);

	ReturnStruct ret(op, a, b);

	return ret;
}

ReturnStruct QParser::CalculatorAddition()
{
	return CalculatorCDefault_two(CalcAddition, limit.first, OperatorNumber - 1, OperatorNumber + 1, limit.second);
}

ReturnStruct QParser::CalculatorArccosinus()
{
	int LeftShift = 7, RightShift = -1;
	return CalculatorCDefault_one(CalcArccosinus, limit.first + LeftShift, limit.second + RightShift);
}

ReturnStruct QParser::CalculatorArccotangens()
{
	int LeftShift = 7, RightShift = -1;
	return CalculatorCDefault_one(CalcArccotangens, limit.first + LeftShift, limit.second + RightShift);
}

ReturnStruct QParser::CalculatorArcsinus()
{
	int LeftShift = 7, RightShift = -1;
	return CalculatorCDefault_one(CalcArcsinus, limit.first + LeftShift, limit.second + RightShift);
}

ReturnStruct QParser::CalculatorArctangens()
{
	int LeftShift = 6, RightShift = -1;
	return CalculatorCDefault_one(CalcArctangens, limit.first + LeftShift, limit.second + RightShift);
}

ReturnStruct QParser::CalculatorConstE()
{
	ReturnStruct ret((float)Econst);
	return ret;
}

ReturnStruct QParser::CalculatorConstPI()
{
	ReturnStruct ret((float)PI);
	return ret;
}

ReturnStruct QParser::CalculatorCosinus()
{
	int LeftShift = 4, RightShift = -1;
	return CalculatorCDefault_one(CalcCosinus, limit.first + LeftShift, limit.second + RightShift);
}

ReturnStruct QParser::CalculatorCotangens()
{
	int LeftShift = 4, RightShift = -1;
	return CalculatorCDefault_one(CalcCotangens, limit.first + LeftShift, limit.second + RightShift);
}


ReturnStruct QParser::CalculatorDivision()
{
	return CalculatorCDefault_two(CalcDivision, limit.first, OperatorNumber - 1, OperatorNumber + 1, limit.second);
}

ReturnStruct QParser::CalculatorFractionPart()
{
	int LeftShift = 1, RightShift = -1;
	return CalculatorCDefault_one(CalcFractionPart, limit.first + LeftShift, limit.second + RightShift);
}

ReturnStruct QParser::CalculatorIntegralPart()
{
	int LeftShift = 1, RightShift = -1;
	return CalculatorCDefault_one(CalcIntegralPart, limit.first + LeftShift, limit.second + RightShift);
}

ReturnStruct QParser::CalculatorBrackets()
{
	int LeftShift = 1, RightShift = -1;
	return CalculatorCDefault_one(CalcBrackets, limit.first + LeftShift, limit.second + RightShift);
}

ReturnStruct QParser::CalculatorLogarithmDecimal()
{
	int LeftShift = 3, RightShift = -1;
	return CalculatorCDefault_one(CalcLogarithmDecimal, limit.first + LeftShift, limit.second + RightShift);
}

ReturnStruct QParser::CalculatorLogarithmNatural()
{
	int LeftShift = 3, RightShift = -1;
	return CalculatorCDefault_one(CalcLogarithmNatural, limit.first + LeftShift, limit.second + RightShift);
}

ReturnStruct QParser::CalculatorModule()
{
	int LeftShift = 4, RightShift = -1;
	return CalculatorCDefault_one(CalcModule, limit.first + LeftShift, limit.second + RightShift);
}

ReturnStruct QParser::CalculatorModule_()
{
	int LeftShift = 1, RightShift = -1;
	return CalculatorCDefault_one(CalcModule, limit.first + LeftShift, limit.second + RightShift);
}

ReturnStruct QParser::CalculatorMultiplication()
{
	return CalculatorCDefault_two(CalcMultiplication, limit.first, OperatorNumber - 1, OperatorNumber + 1, limit.second);
}

ReturnStruct QParser::CalculatorPowering()
{
	return CalculatorCDefault_two(CalcPowering, limit.first, OperatorNumber - 1, OperatorNumber + 1, limit.second);
}

ReturnStruct QParser::CalculatorSinus()
{
	int LeftShift = 4, RightShift = -1;
	return CalculatorCDefault_one(CalcSinus, limit.first + LeftShift, limit.second + RightShift);
}

ReturnStruct QParser::CalculatorSpecialSqrt()
{
	int LeftShift = 5, RightShift = -1;
	return CalculatorCDefault_one(CalcSpecialSqrt, limit.first + LeftShift, limit.second + RightShift);
}

ReturnStruct QParser::CalculatorSubstraction()
{
	return CalculatorCDefault_two(CalcSubtraction, limit.first, OperatorNumber - 1, OperatorNumber + 1, limit.second);
}

ReturnStruct QParser::CalculatorTangens()
{
	int LeftShift = 3, RightShift = -1;
	return CalculatorCDefault_one(CalcTangens, limit.first + LeftShift, limit.second + RightShift);
}