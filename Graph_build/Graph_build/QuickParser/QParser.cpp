#include "../Graph_build/Graph Builder/header.h"
#include "QParser.h"

using namespace QuickMathParser;

string QParser::QParserStr;

QParser::QParser(System::String ^str)
{
	string strstring;
	for (int i = 0; i < str->Length; i++)
		strstring += (char) str[i];

	QParser_default(&strstring);
}

QParser::QParser(string *tmp)
{
	QParser_default(tmp);
}

QParser::QParser(int left, int right)
{
	limit.first = left;
	limit.second = right;

	TryShiftBrackets();

	Operator = CalcNotDetected;
	OperatorNumber = limit.first;
}

void QParser::QParser_default(string *tmp)
{
	//fstream debug("debug.txt", ios::app); debug << *tmp << endl;

	QParser::QParserStr = *tmp;

	RemoveUnnecessaryChar();

	limit.first = 0;
	limit.second = QParserStr.length() - 1;

	TryShiftBrackets();

	Operator = CalcNotDetected;
	OperatorNumber = limit.first;
}

void QParser::RemoveUnnecessaryChar()
{
	while (QParserStr.find(" ") != string::npos) QParserStr.erase(QParserStr.find(" "), 1);
}

void QParser::OneOperandOperatorFind()
{
	CalculatorEnum OperatorAnswer = CalcNotDetected;
	string strtmp;
	for (int i = limit.first; i <= limit.second; i++)
		strtmp += QParserStr[i];

	if (strtmp.find("sin") == 0)			OperatorAnswer = CalcSinus;
	else if (strtmp.find("cos") == 0)		OperatorAnswer = CalcCosinus;
	else if (strtmp.find("tg") == 0)		OperatorAnswer = CalcTangens;
	else if (strtmp.find("ctg") == 0)		OperatorAnswer = CalcCotangens;
	else if (strtmp.find("arcsin") == 0)	OperatorAnswer = CalcArcsinus;
	else if (strtmp.find("arccos") == 0)	OperatorAnswer = CalcArccosinus;
	else if (strtmp.find("arctg") == 0)		OperatorAnswer = CalcArctangens;
	else if (strtmp.find("arcctg") == 0)	OperatorAnswer = CalcArccotangens;
	else if (strtmp.find("sqrt") == 0)		OperatorAnswer = CalcSpecialSqrt;
	else if (strtmp.find("lg") == 0)		OperatorAnswer = CalcLogarithmDecimal;
	else if (strtmp.find("ln") == 0)		OperatorAnswer = CalcLogarithmNatural;
	else if (strtmp.find("[") == 0)			OperatorAnswer = CalcIntegralPart;
	else if (strtmp.find("{") == 0)			OperatorAnswer = CalcFractionPart;
	else if (strtmp.find("|") == 0)			OperatorAnswer = CalcModule_;
	else if (strtmp.find("abs") == 0)		OperatorAnswer = CalcModule;
	else if (strtmp.find("Pi") == 0)		OperatorAnswer = CalcConstPI;
	else if (strtmp.find("e") == 0)			OperatorAnswer = CalcConstE;
	else if (strtmp.find("(") == 0)			OperatorAnswer = CalcBrackets;
	else OperatorAnswer = CalcNotDetected;

	Operator = OperatorAnswer;
}

bool QParser::TwoOperandOperatorFind()
{
	CalculatorEnum OperatorAnswer = CalcNotDetected;

	int bestprior = 4, numberbestprior = limit.first;

	for (int itmp = limit.first; itmp <= limit.second; itmp++)
	if (CheckNullNesting(limit.first, itmp) == NestingNull)
	{
		int tmpTwoOperandOperationPrior = TwoOperandOperationPrior(QParserStr[itmp]);

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

int QParser::TwoOperandOperationPrior(char tmp)
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

int QParser::CheckNullNesting(int left, int right)
{
	Nesting answer = NestingNotNull;
	int NestingSimple = 0, NestingIntegral = 0, NestingFraction = 0;

	for (int itmp = left; itmp <= right; itmp++)
	{
		switch (QParserStr[itmp])
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
		case '|':
			NestingSimple++;
			break;
		}
		if (NestingSimple < 0 || NestingIntegral < 0 || NestingFraction < 0) answer = NestingError;
	}

	if (answer != NestingError && NestingSimple == 0 && NestingIntegral == 0 && NestingFraction == 0) answer = NestingNull;

	return answer;
}

CalculatorEnum QParser::OperatorIdentify(int StringNumber, bool SimpleOperator)
{
	if (SimpleOperator == true)
	{
		switch (QParserStr[StringNumber])
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

void QParser::TryShiftBrackets()
{
	/*if (QParserStr[limit.first] == '(' && QParserStr[limit.second] == ')')
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
	}*/
}

ReturnStruct QParser::ConvertToFloat()
{
	TryShiftBrackets();

	if (limit.first == limit.second && QParserStr[limit.first] == 'x')
	{
		ReturnStruct ret(CalcVarX);
		return ret;
	}
	else if (limit.first == limit.second && QParserStr[limit.first] == 'y')
	{
		ReturnStruct ret(CalcVarY);
		return ret;
	}
	else
	{
		float answer = 0;
		bool comma = false;
		int CharAfterComma = 0;

		for (int itmp = limit.first; itmp <= limit.second; itmp++)
		{
			if (QParserStr[itmp] != '.' && comma == false)
			{
				answer *= 10;
				answer += QParserStr[itmp] - 48;
			}
			else if (QParserStr[itmp] == '.')
			{
				comma = true;
			}
			else if (comma)
			{
				CharAfterComma++;
				answer = answer + (QParserStr[itmp] - 48) / (float)pow(10, CharAfterComma);
			}
		}

		ReturnStruct ret(answer);
		return ret;
	}

}

bool QParser::ErrorHandling()
{
	return true;
}

ReturnStruct QParser::GetValue(pair <int, int> pairParam)
{
	limit = pairParam;
	OperatorNumber = pairParam.first;

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
		case CalcBrackets:
			return CalculatorBrackets();
			break;
		case CalcModule:
			return CalculatorModule();
			break;
		case CalcModule_:
			return CalculatorModule_();
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
		case CalcConstPI:
			return CalculatorConstPI();
			break;
		case CalcConstE:
			return CalculatorConstE();
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