#include "Parser.h"

using namespace MathParser;

float Parser::CalculatorLogarithmNatural()
{
	int LeftShift = 3, RightShift = -1;

	Parser Operand(limit.first + LeftShift, limit.second + RightShift);

	float OperandValue = Operand.GetValue();

	return log10(OperandValue) / log10(2.71828182845904523536);
}