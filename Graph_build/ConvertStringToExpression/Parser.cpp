#include "Parser.h"
#include <vector>
#include <fstream>

using namespace MathParser;

string Parser :: ParserStr;
float Parser :: variable;

Parser :: Parser(string *tmp, float var)
{
	Parser :: ParserStr = *tmp;
	
	RemoveUnnecessaryChar();	

	variable = var;
	limit.first = 0;
	limit.second = ParserStr.length() - 1;

	TryShiftBrackets();
	
	Operator = CalcNotDetected;
	OperatorNumber = limit.first;
}

Parser :: Parser(int left, int right)
{
	limit.first = left;
	limit.second = right;

	TryShiftBrackets();

	Operator = CalcNotDetected;
	OperatorNumber = limit.first;
}

void Parser :: RemoveUnnecessaryChar()
{
	while (ParserStr.find(" ") != string::npos) ParserStr.erase(ParserStr.find(" "), 1);
}

void Parser :: OneOperandOperatorFind()
{
	CalculatorEnum OperatorAnswer = CalcNotDetected;
	string strtmp;
	for (int i = limit.first; i <= limit.second; i++)
		strtmp += ParserStr[i];

	if (strtmp.find("sin") == 0) OperatorAnswer = CalcSinus;
	else if (strtmp.find("cos") == 0) OperatorAnswer = CalcCosinus;
	else if (strtmp.find("tg") == 0) OperatorAnswer = CalcTangens;
	else if (strtmp.find("ctg") == 0)	OperatorAnswer = CalcCotangens;
	else if (strtmp.find("arcsin") == 0) OperatorAnswer = CalcArcsinus;
	else if (strtmp.find("arccos") == 0) OperatorAnswer = CalcArccosinus;
	else if (strtmp.find("arctg") == 0) OperatorAnswer = CalcArctangens;
	else if (strtmp.find("arcctg") == 0) OperatorAnswer = CalcArccotangens;
	else if (strtmp.find("sqrt") == 0) OperatorAnswer = CalcSpecialSqrt;
	else if (strtmp.find("lg") == 0) OperatorAnswer = CalcLogarithmDecimal;
	else if (strtmp.find("ln") == 0) OperatorAnswer = CalcLogarithmNatural;
	else if (strtmp.find("[") == 0) OperatorAnswer = CalcIntegralPart;
	else if (strtmp.find("{") == 0) OperatorAnswer = CalcFractionPart;
	else if (strtmp.find("|") == 0) OperatorAnswer = CalcModule;
	else OperatorAnswer = CalcNotDetected;

	Operator = OperatorAnswer;
}

bool Parser :: TwoOperandOperatorFind()
{
	CalculatorEnum OperatorAnswer = CalcNotDetected;

	int bestprior = 4, numberbestprior = limit.first;

	for (int itmp = limit.first; itmp <= limit.second; itmp++)
		if (CheckNullNesting(limit.first, itmp) == NestingNull)
		{
			int tmpTwoOperandOperationPrior = TwoOperandOperationPrior(ParserStr[itmp]);

			if (tmpTwoOperandOperationPrior <= bestprior)
			{
				bestprior = tmpTwoOperandOperationPrior;
				OperatorAnswer = OperatorIdentify(itmp, true);
				numberbestprior = itmp;
			};
		};

	Operator = OperatorAnswer;
	OperatorNumber = numberbestprior;

	if (OperatorAnswer != CalcNotDetected) return true;
	else return false;
}

int Parser::TwoOperandOperationPrior(char tmp)
{
	switch (tmp)
	{
	case '^':
		return 3;
		break;
	case '*':
	case '/':
		return 2;
		break;
	case '+':
	case '-':
		return 1;
		break;
	default:
		return 4;
		break;
	};
}

int Parser :: CheckNullNesting(int left, int right)
{
	Nesting answer = NestingNotNull;
	int NestingSimple = 0, NestingIntegral = 0, NestingFraction = 0;

	for (int itmp = left; itmp <= right; itmp++)
	{
		switch (ParserStr[itmp])
		{
		case '(':
			NestingSimple++;
			break;
		case ')':
			NestingSimple--;
			break;
		case '[':
			NestingIntegral++;
			break;
		case ']':
			NestingIntegral--;
			break;
		case '{':
			NestingFraction++;
			break;
		case '}':
			NestingFraction--;
			break;
		}
		if (NestingSimple < 0 || NestingIntegral < 0 || NestingFraction < 0) answer = NestingError;
	}

	if (answer != NestingError && NestingSimple == 0 && NestingIntegral == 0 && NestingFraction == 0) answer = NestingNull;

	return answer;
}

CalculatorEnum Parser :: OperatorIdentify(int StringNumber, bool SimpleOperator)
{
	if (SimpleOperator == true)
	{
		switch (ParserStr[StringNumber])
		{
		case '^':
			return CalcPowering;
			break;
		case '/':
			return CalcDivision;
			break;
		case '*':
			return CalcMultiplication;
			break;
		case '+':
			return CalcAddition;
			break;
		case '-':
			return CalcSubtraction;
			break;
		default:
			return CalcNotDetected;
			break;
		}

	}
	else
	{
		return CalcNotDetected;
	}
}

void Parser::TryShiftBrackets()
{
	if (ParserStr[limit.first] == '(' && ParserStr[limit.second] == ')')
	{
		Nesting FindNullNesting = NestingNotNull;

		for (int itmp = limit.first + 1; itmp < limit.second; itmp++)
		{
			if (CheckNullNesting(limit.first, itmp) == NestingNull || CheckNullNesting(limit.first, itmp) == NestingError)
			{
				FindNullNesting = NestingNull;
				break;
			}
		}

		if (FindNullNesting == NestingNotNull)
		{
			limit.first++;
			limit.second--;
		}
	}
}

float Parser :: ConvertToFloat()
{
	TryShiftBrackets();

	if (limit.first == limit.second && ParserStr[limit.first] == 'x')
	{
		return variable;
	}
	else
	{
		float answer = 0;
		bool comma = false;
		int CharAfterComma = 0;

		for (int itmp = limit.first; itmp <= limit.second; itmp++)
		{
			if (ParserStr[itmp] != '.' && comma == false)
			{
				answer *= 10;
				answer += ParserStr[itmp] - 48;
			}
			else if (ParserStr[itmp] == '.')
			{
				comma = true;
			}
			else if (comma)
			{
				CharAfterComma++;
				answer += (ParserStr[itmp] - 48) / pow(10, CharAfterComma);
			}
		}
		return answer;
	}
	
}

bool Parser::ErrorHandling()
{
	return true;
}

float Parser :: GetValue()
{
	if (ErrorHandling())
	{
		if (!TwoOperandOperatorFind()) OneOperandOperatorFind();
		switch (Operator)
		{
		case CalcPowering:
			return CalculatorPowering();
			break;
		case CalcMultiplication:
			return CalculatorMultiplication();
			break;
		case CalcDivision:
			return CalculatorDivision();
			break;
		case CalcAddition:
			return CalculatorAddition();
			break;		
		case CalcSubtraction:
			return CalculatorSubstraction();
			break;
		case CalcSinus:
			return CalculatorSinus();
			break;
		case CalcCosinus:
			return CalculatorCosinus();
			break;
		case CalcTangens:
			return CalculatorTangens();
			break;
		case CalcCotangens:
			return CalculatorCotangens();
			break;
		case CalcArcsinus:
			return CalculatorArcsinus();
			break;
		case CalcArccosinus:
			return CalculatorArccosinus();
			break;
		case CalcArctangens:
			return CalculatorArctangens();
			break;		
		case CalcArccotangens:
			return CalculatorArccotangens();
			break;
		case CalcFractionPart:
			return CalculatorFractionPart();
			break;
		case CalcIntegralPart:
			return CalculatorIntegralPart();
			break;
		case CalcModule:
			return CalculatorModule();
			break;
		case CalcSpecialSqrt:
			return CalculatorSpecialSqrt();
			break;
		case CalcLogarithmDecimal:
			return CalculatorLogarithmDecimal();
			break;
		case CalcLogarithmNatural:
			return CalculatorLogarithmNatural();
			break;
		case CalcNotDetected:
			return ConvertToFloat();
			break;
		default: 
			return 0;
			break;
		}
	}
	else return 0;
}