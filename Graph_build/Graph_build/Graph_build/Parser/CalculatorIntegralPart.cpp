#include "Parser.h"
#include "../Graph Builder/MathFunction.h"

#include "../Graph Builder/header.h"

using namespace MathParser;

float Parser :: CalculatorIntegralPart()
{
	int LeftShift = 1, RightShift = -1;

	Parser Operand(limit.first + LeftShift, limit.second + RightShift);

	float OperandValue = Operand.GetValue();

	return MyMath::GetIntegralPart(OperandValue);
}