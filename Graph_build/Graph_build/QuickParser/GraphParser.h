#pragma once

#include "../Graph_build/Graph Builder/header.h"
#include "PointerFunction.h"
#include "QHeader.h"

using namespace std;
using namespace System::Collections;

namespace QuickMathParser
{
	struct ReturnStruct
	{
		CalculatorEnum operation;
		pair <int, int> leftOperand, rightOperand;
		float value;

		ReturnStruct(CalculatorEnum op, pair <int, int> left, pair <int, int> right)
		{
			operation = op;
			leftOperand = left;
			rightOperand = right;
			value = 0.0f;
		}

		ReturnStruct(CalculatorEnum op, pair <int, int> left)
		{
			operation = op;
			leftOperand = left;
			rightOperand = make_pair(-1,-1);
			value = 0.0f;
		}

		ReturnStruct(CalculatorEnum op)
		{
			operation = op;
			value = 0.0f;

			leftOperand = make_pair(-1, -1);
			rightOperand = make_pair(-1, -1);
		}

		ReturnStruct(float val)
		{
			operation = QuickMathParser::CalcValue;
			value = val;

			leftOperand = make_pair(-1, -1);
			rightOperand = make_pair(-1, -1);
		}
	};

	public ref class GraphParserStruct
	{
		public:
		
		float (*funcPointer)(float a, float b);
		float value;
		bool simpleOperation;
		GraphParserStruct ^leftOperand, ^rightOperand;

		inline float GetValue(bool simpleOp)
		{
			if (!simpleOp)
			{
				return (*funcPointer)(
									leftOperand->GetValue(leftOperand->simpleOperation), 
									rightOperand->GetValue(rightOperand->simpleOperation));
			}
			else return (*funcPointer)(value, 0.0f);
		};
			
		GraphParserStruct(float val)
		{
			//funcPointer = PointerFunction::funcPtrReturnValue;
			//functionPointerINIT(CalcValue, funcPointer);
			funcPointer = QuickMathParser::funcPtr::funcPtrCalcValue;
			value = val;
			simpleOperation = true;
			leftOperand = rightOperand = nullptr;
		}
		GraphParserStruct(float(*funcPtr)(float a, float b))
		{
			funcPointer = funcPtr;
			value = 0.0f;
			simpleOperation = true;
			leftOperand = rightOperand = nullptr;
		}
		GraphParserStruct(float(*funcPtr)(float a, float b), GraphParserStruct ^lOp, GraphParserStruct ^rOp)
		{
			funcPointer = funcPtr;
			value = 0.0f;
			simpleOperation = false;
			leftOperand = lOp;
			rightOperand = rOp;
		}
	};

	public ref class GraphParser
	{
	private:
		System::String ^str;
		Generic::List<GraphParserStruct^> returnList;

	public:
		static float xtmp, ytmp;

		void makeGraph();
		//static void functionPointerINIT(CalculatorEnum operation, float(*funcPtr)(float a, float b));
		
		float GetValue(float x, float y);

		GraphParser(System::String ^strtmp)
		{
			str = strtmp;
			makeGraph();
		}
	};
}