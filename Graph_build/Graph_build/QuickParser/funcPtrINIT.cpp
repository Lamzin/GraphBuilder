#include "../Graph_build/Graph Builder/header.h"
#include "GraphParser.h"
#include "PointerFunction.h"
#include "QParser.h"

namespace QuickMathParser
{
	ReturnPointerFunction functionPointerINIT(CalculatorEnum operation)
	{	
		ReturnPointerFunction retStruct;

		switch (operation)
		{
		case CalcPowering:
			retStruct.function = QuickMathParser::funcPtr::funcPtrCalcPowering;
			break;
		case CalcMultiplication:
			retStruct.function = QuickMathParser::funcPtr::funcPtrCalcMultiplication;
			break;
		case CalcDivision:
			retStruct.function = QuickMathParser::funcPtr::funcPtrCalcDivision;
			break;
		case CalcAddition:
			retStruct.function = QuickMathParser::funcPtr::funcPtrCalcAddition;
			break;
		case CalcSubtraction:
			retStruct.function = QuickMathParser::funcPtr::funcPtrCalcSubtraction;
			break;
		case CalcSinus:
			retStruct.function = QuickMathParser::funcPtr::funcPtrCalcSinus;
			break;
		case CalcCosinus:
			retStruct.function = QuickMathParser::funcPtr::funcPtrCalcCosinus;
			break;
		case CalcTangens:
			retStruct.function = QuickMathParser::funcPtr::funcPtrCalcTangens;
			break;
		case CalcCotangens:
			retStruct.function = QuickMathParser::funcPtr::funcPtrCalcCotangens;
			break;
		case CalcArcsinus:
			retStruct.function = QuickMathParser::funcPtr::funcPtrCalcArcsinus;
			break;
		case CalcArccosinus:
			retStruct.function = QuickMathParser::funcPtr::funcPtrCalcArccosinus;
			break;
		case CalcArctangens:
			retStruct.function = QuickMathParser::funcPtr::funcPtrCalcArctangens;
			break;
		case CalcArccotangens:
			retStruct.function = QuickMathParser::funcPtr::funcPtrCalcArccotangens;
			break;
		case CalcFractionPart:
			retStruct.function = QuickMathParser::funcPtr::funcPtrCalcFractionPart;
			break;
		case CalcIntegralPart:
			retStruct.function = QuickMathParser::funcPtr::funcPtrCalcIntegralPart;
			break;
		case CalcBrackets:
			retStruct.function = QuickMathParser::funcPtr::funcPtrCalcBrackets;
			break;
		case CalcModule:
			retStruct.function = QuickMathParser::funcPtr::funcPtrCalcModule;
			break;
		case CalcLogarithmDecimal:
			retStruct.function = QuickMathParser::funcPtr::funcPtrCalcLogarithmDecimal;
			break;
		case CalcLogarithmNatural:
			retStruct.function = QuickMathParser::funcPtr::funcPtrCalcLogarithmNatural;
			break;
		case CalcSpecialSqrt:
			retStruct.function = QuickMathParser::funcPtr::funcPtrCalcSpecialSqrt;
			break;
		case CalcNotDetected:
			retStruct.function = QuickMathParser::funcPtr::funcPtrCalcNotDetected;
			break;
		case CalcVariableFirst:
			retStruct.function = QuickMathParser::funcPtr::funcPtrCalcVariableFirst;
			break;
		case CalcConstPI:
			retStruct.function = QuickMathParser::funcPtr::funcPtrCalcConstPI;
			break;
		case CalcConstE:
			retStruct.function = QuickMathParser::funcPtr::funcPtrCalcConstE;
			break;
		case CalcValue:
			retStruct.function = QuickMathParser::funcPtr::funcPtrCalcValue;
			break;
		case CalcVarX:
			retStruct.function = QuickMathParser::funcPtr::funcPtrCalcVarX;
			break;
		case CalcVarY:
			retStruct.function = QuickMathParser::funcPtr::funcPtrCalcVarY;
			break;
		}

		return retStruct;
	}
}