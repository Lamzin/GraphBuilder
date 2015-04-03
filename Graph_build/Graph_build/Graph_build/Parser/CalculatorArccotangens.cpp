#include "Parser.h"

#define PI 3.14159265f

using namespace MathParser;

float Parser :: CalculatorArccotangens()
{
	int LeftShift = 7, RightShift = -1;

	Parser Operand(limit.first + LeftShift, limit.second + RightShift);

	float OperandValue = Operand.GetValue();

	return PI/2 - atan(OperandValue);
}