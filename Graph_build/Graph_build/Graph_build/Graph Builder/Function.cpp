#include "header.h"
#include "Function.h"
#include "../Parser/Parser.h"

using namespace Render;
using namespace MathParser;

Function::Function(System::String ^str_tmp)
{
	str = str_tmp;

	str_tmp->Copy(str);

	simple = true;

	QparserObj = gcnew QuickMathParser::GraphParser(str_tmp);
}

Function::Function(System::String ^str_tmp, bool PositionLeft_tmp, FunctionOperator Operator)
{
	str = str_tmp;
	str_tmp->Copy(str);

	simple = false;
	OperatorType = Operator;

	PositionLeft = PositionLeft_tmp;

	QparserObj = gcnew QuickMathParser::GraphParser(str_tmp);
}

float Function::Value(float x, float y)
{
	/*-------------WARNING! SLOW PARSER-------------*/

	/*Parser Name(str, x, y);
	return Name.GetValue();*/

	/*-------------WARNING! SLOW PARSER-------------*/

	return QparserObj->GetValue(x, y);
}

void Function::StringProcessing(System::String ^str_tmp)
{
	int SemicolonPos;

	tmp = gcnew System::String("");

	while (str_tmp->Length != 0)
	{
		SemicolonPos = str_tmp->IndexOf(";");
		if (SemicolonPos > 0)
		{
			tmp = System::String::Copy(str_tmp);

			tmp = tmp->Remove(SemicolonPos);
			str_tmp = str_tmp->Remove(0, SemicolonPos+1);
			StringProcessingPart(tmp);
		}
		else
		{
			tmp = System::String::Copy(str_tmp);
			StringProcessingPart(tmp);
			str_tmp = str_tmp->Remove(0);
		}
	}

}

void Function::StringProcessingPart(System::String ^str_tmp)
{
	FunctionOperator oper;
	int count_of_find_oper = 0, oper_index;

	if (str_tmp->IndexOf(">") >= NULL) count_of_find_oper = 1;
	if (str_tmp->IndexOf("<") >= NULL) count_of_find_oper = 1;
	if (str_tmp->IndexOf("=") >= NULL) count_of_find_oper = 1;

	if (count_of_find_oper == 1)
	{
		if (str_tmp->IndexOf(">=") >= NULL) oper = MoreOrEqual, oper_index = str_tmp->IndexOf(">=");
		else if (str_tmp->IndexOf(">") >= NULL) oper = More, oper_index = str_tmp->IndexOf(">");
		else if (str_tmp->IndexOf("<=") >= NULL) oper = LessOrEqual, oper_index = str_tmp->IndexOf("<=");
		else if (str_tmp->IndexOf("<") >= NULL) oper = Less, oper_index = str_tmp->IndexOf("<");
		else if (str_tmp->IndexOf("=") >= NULL) oper = Equal, oper_index = str_tmp->IndexOf("=");
		
		tmp = str_tmp->Copy(tmp);
		
		tmp = tmp->Remove(oper_index);

		Function ^FUNC = gcnew Function(tmp, true, oper);
		MyFuncArray.Add(FUNC);

		tmp = "";
		for (int i = oper_index + 1; i < str_tmp->Length; i++) tmp += str_tmp[i];

		if (oper == MoreOrEqual || oper == LessOrEqual) tmp = tmp->Remove(0, 1);

		oper = NoneOper;// only first func must have operation;
		FUNC = gcnew Function(tmp, false, oper);
		MyFuncArray.Add(FUNC);
		
		MyFuncArray[MyFuncArray.Count - 1]->ExpressionFunction = MyFuncArray[MyFuncArray.Count - 2];
		MyFuncArray[MyFuncArray.Count - 2]->ExpressionFunction = MyFuncArray[MyFuncArray.Count - 1];

	}
	else if (count_of_find_oper == 0)
	{
		Function ^FUNC = gcnew Function(tmp);
		MyFuncArray.Add(FUNC);
	}
}