#pragma once

namespace QuickMathParser
{
	enum CalculatorEnum
	{
		CalcPowering, // ^
		CalcMultiplication, // *
		CalcDivision, // /
		CalcAddition, // +
		CalcSubtraction, // -
		CalcSinus,
		CalcCosinus,
		CalcTangens,
		CalcCotangens,
		CalcArcsinus,
		CalcArccosinus,
		CalcArctangens,
		CalcArccotangens,
		CalcFractionPart,
		CalcIntegralPart,
		CalcBrackets,
		CalcModule,
		CalcModule_,
		CalcLogarithmDecimal,
		CalcLogarithmNatural,
		CalcSpecialSqrt,
		CalcNotDetected,
		CalcVariableFirst,
		CalcConstPI,
		CalcConstE,
		CalcValue,
		CalcVarX,
		CalcVarY
	};
	
	struct ReturnPointerFunction
	{
		float(*function)(float a, float b);
	};

	ReturnPointerFunction functionPointerINIT(CalculatorEnum operation);

	class funcPtr
	{
	public:
		static float funcPtrReturnValue(float a, float b);
		static float funcPtrCalcPowering(float a, float b);
		static float funcPtrCalcMultiplication(float a, float b);
		static float funcPtrCalcDivision(float a, float b);
		static float funcPtrCalcAddition(float a, float b);
		static float funcPtrCalcSubtraction(float a, float b);
		static float funcPtrCalcSinus(float a, float b);
		static float funcPtrCalcCosinus(float a, float b);
		static float funcPtrCalcTangens(float a, float b);
		static float funcPtrCalcCotangens(float a, float b);
		static float funcPtrCalcArcsinus(float a, float b);
		static float funcPtrCalcArccosinus(float a, float b);
		static float funcPtrCalcArctangens(float a, float b);
		static float funcPtrCalcArccotangens(float a, float b);
		static float funcPtrCalcFractionPart(float a, float b);
		static float funcPtrCalcIntegralPart(float a, float b);
		static float funcPtrCalcBrackets(float a, float b);
		static float funcPtrCalcModule(float a, float b);
		static float funcPtrCalcLogarithmDecimal(float a, float b);
		static float funcPtrCalcLogarithmNatural(float a, float b);
		static float funcPtrCalcSpecialSqrt(float a, float b);
		static float funcPtrCalcNotDetected(float a, float b);
		static float funcPtrCalcVariableFirst(float a, float b);
		static float funcPtrCalcConstPI(float a, float b);
		static float funcPtrCalcConstE(float a, float b);
		static float funcPtrCalcValue(float a, float b);
		static float funcPtrCalcVarX(float a, float b);
		static float funcPtrCalcVarY(float a, float b);
	};
}