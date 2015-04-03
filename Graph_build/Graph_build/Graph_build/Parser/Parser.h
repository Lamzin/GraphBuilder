#include <string>

using namespace std;

namespace MathParser
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
		CalcModule,
		CalcLogarithmDecimal,
		CalcLogarithmNatural,
		CalcSpecialSqrt,
		CalcNotDetected,
		CalcVariableFirst,
		CalcConstPI,
		CalcConstE
	};

	enum Nesting
	{
		NestingNull,
		NestingError,
		NestingNotNull
	};

	class Parser
	{
	private:
		static string ParserStr;
		static float variable, variable2;

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

		float ConvertToFloat();
		float CalculatorPowering();
		float CalculatorMultiplication();
		float CalculatorDivision();
		float CalculatorAddition();
		float CalculatorSubstraction();
		float CalculatorSinus();
		float CalculatorCosinus();
		float CalculatorTangens();
		float CalculatorCotangens();
		float CalculatorArcsinus();
		float CalculatorArccosinus();
		float CalculatorArctangens();
		float CalculatorArccotangens();
		float CalculatorFractionPart();
		float CalculatorIntegralPart();
		float CalculatorModule();
		float CalculatorSpecialSqrt();
		float CalculatorLogarithmDecimal();
		float CalculatorLogarithmNatural();
		float CalculatorConstPI();
		float CalculatorConstE();

	public:
		Parser(System::String ^str, float var, float var2);
		Parser(string *tmp, float var, float var2);
		Parser(int left, int right);

		float GetValue();

	private:
		void Parser_default(string *tmp, float var, float var2);
	};
}