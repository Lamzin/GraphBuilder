#include "Parser.h"

using namespace MathParser;

float Parser :: CalculatorModule()
{
	int LeftShift = 4, RightShift = -1;

	Parser Operand(limit.first + LeftShift, limit.second + RightShift);

	float OperandValue = Operand.GetValue();

	return abs(OperandValue);
}