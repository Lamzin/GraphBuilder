#include "Parser.h"

using namespace MathParser;

float Parser::CalculatorSpecialSqrt()
{
	int LeftShift = 5, RightShift = -1;

	Parser Operand(limit.first + LeftShift, limit.second + RightShift);

	float OperandValue = Operand.GetValue();

	return sqrtf(OperandValue);
}