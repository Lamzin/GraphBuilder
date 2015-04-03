#include "Parser.h"
#include "../MathFunction.h"

using namespace MathParser;

float Parser :: CalculatorIntegralPart()
{
	int LeftShift = 1, RightShift = -1;

	Parser Operand(limit.first + LeftShift, limit.second + RightShift);

	float OperandValue = Operand.GetValue();

	return MyMath::Math::GetIntegralPart(OperandValue);
}