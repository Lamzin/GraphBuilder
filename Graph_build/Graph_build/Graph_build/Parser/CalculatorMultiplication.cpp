#include "Parser.h"

using namespace MathParser;

float Parser :: CalculatorMultiplication()
{
	Parser LeftOperand(limit.first, OperatorNumber - 1), RightOperand(OperatorNumber + 1, limit.second);

	float LeftOperandValue = LeftOperand.GetValue(), RightOperandValue = RightOperand.GetValue();

	return LeftOperandValue * RightOperandValue;
}