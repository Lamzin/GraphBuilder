#include "Parser.h"

using namespace MathParser;

float Parser :: CalculatorDivision()
{
	Parser LeftOperand(limit.first, OperatorNumber - 1), RightOperand(OperatorNumber + 1, limit.second);
	
	float LeftOperandValue = LeftOperand.GetValue(), RightOperandValue = RightOperand.GetValue();

	if (RightOperandValue != 0)
		return LeftOperandValue / RightOperandValue;
	else return 0;
}