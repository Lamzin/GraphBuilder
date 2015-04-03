#pragma once

#include "../Graph_build/Graph Builder/header.h"
#include "GraphParser.h"

using namespace std;

namespace QuickMathParser
{
	enum Nesting
	{
		NestingNull,
		NestingError,
		NestingNotNull
	};

	class QParser
	{
	private:
		static string QParserStr;

		pair <int, int> limit;
		CalculatorEnum Operator;
		int OperatorNumber;

		void RemoveUnnecessaryChar();
		void TryShiftBrackets();

		void OneOperandOperatorFind();
		bool TwoOperandOperatorFind();
		CalculatorEnum OperatorIdentify(int StringNumber, bool SimpleOperator);

		int TwoOperandOperationPrior(char tmp);
		int CheckNullNesting(int left, int right);
		bool ErrorHandling();

		ReturnStruct ConvertToFloat();
		ReturnStruct CalculatorPowering();
		ReturnStruct CalculatorMultiplication();
		ReturnStruct CalculatorDivision();
		ReturnStruct CalculatorAddition();
		ReturnStruct CalculatorSubstraction();
		ReturnStruct CalculatorSinus();
		ReturnStruct CalculatorCosinus();
		ReturnStruct CalculatorTangens();
		ReturnStruct CalculatorCotangens();
		ReturnStruct CalculatorArcsinus();
		ReturnStruct CalculatorArccosinus();
		ReturnStruct CalculatorArctangens();
		ReturnStruct CalculatorArccotangens();
		ReturnStruct CalculatorFractionPart();
		ReturnStruct CalculatorIntegralPart();
		ReturnStruct CalculatorBrackets();
		ReturnStruct CalculatorModule();
		ReturnStruct CalculatorModule_();
		ReturnStruct CalculatorSpecialSqrt();
		ReturnStruct CalculatorLogarithmDecimal();
		ReturnStruct CalculatorLogarithmNatural();
		ReturnStruct CalculatorConstPI();
		ReturnStruct CalculatorConstE();
		ReturnStruct CalculatorCDefault_one(CalculatorEnum op, int lparam, int rparam);
		ReturnStruct CalculatorCDefault_two(CalculatorEnum op, int lparam1, int rparam1, int lparam2, int rparam2);

	public:
		QParser(System::String ^str);
		QParser(string *tmp);
		QParser(int left, int right);

		ReturnStruct GetValue(pair <int, int> pairParam);

	private:
		void QParser_default(string *tmp);
	};
}