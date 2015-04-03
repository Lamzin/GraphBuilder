#pragma once

#include "header.h"
#include "..//..//QuickParser/GraphParser.h"
#include "..//..//QuickParser/PointerFunction.h"
#include "..//..//QuickParser/QParser.h"

using namespace std;
using namespace System::Collections;

namespace Render
{
	enum FunctionOperator
	{
		More,
		MoreOrEqual,
		Less,
		LessOrEqual,
		NoneOper,
		Equal
	};

	public ref class Function
	{
	public:
		bool simple, PositionLeft;
		System::String ^str;
		Function ^ExpressionFunction;
		FunctionOperator OperatorType;

		QuickMathParser::GraphParser ^QparserObj;

		static System::String ^tmp;
		static Generic::List<Function^> MyFuncArray;

		Function(System::String ^str_tmp);
		Function(System::String ^str_tmp, bool PositionLeft_tmp, FunctionOperator Operator);
		
		float Value(float x, float y);

		static void StringProcessing(System::String ^str_tmp);
		static void StringProcessingPart(System::String ^str_tmp);
	};
}