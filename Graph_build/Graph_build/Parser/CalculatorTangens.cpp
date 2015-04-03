#include "Parser.h"

using namespace MathParser;

float Parser :: CalculatorTangens()
{
	int LeftShift = 3, RightShift = -1;

	Parser Operand(limit.first + LeftShift, limit.second + RightShift);

	float OperandValue = Operand.GetValue();

	return tan(OperandValue);
}