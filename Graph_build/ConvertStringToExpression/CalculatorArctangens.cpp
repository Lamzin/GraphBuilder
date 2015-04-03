#include "Parser.h"

using namespace MathParser;

float Parser :: CalculatorArctangens()
{
	int LeftShift = 6, RightShift = -1;

	Parser Operand(limit.first + LeftShift, limit.second + RightShift);

	float OperandValue = Operand.GetValue();

	return atan(OperandValue);
}