#include "Parser.h"
#include "../Graph Builder/MathFunction.h"


using namespace MathParser;

float Parser :: CalculatorFractionPart()
{
	int LeftShift = 1, RightShift = -1;

	Parser Operand(limit.first + LeftShift, limit.second + RightShift);

	float OperandValue = Operand.GetValue();

	return MyMath::GetFractionalPart(OperandValue);
}