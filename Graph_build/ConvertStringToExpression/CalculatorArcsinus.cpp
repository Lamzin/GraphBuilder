#include "Parser.h"

using namespace MathParser;

float Parser :: CalculatorArcsinus()
{
	int LeftShift = 7, RightShift = -1;

	Parser Operand(limit.first + LeftShift, limit.second + RightShift);

	float OperandValue = Operand.GetValue();

	return asin(OperandValue);
}