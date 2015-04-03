#include "Parser.h"

using namespace MathParser;

float Parser :: CalculatorCotangens()
{
	int LeftShift = 4, RightShift = -1;

	Parser Operand(limit.first + LeftShift, limit.second + RightShift);

	float OperandValue = Operand.GetValue();

	return cos(OperandValue) / sin(OperandValue);
}