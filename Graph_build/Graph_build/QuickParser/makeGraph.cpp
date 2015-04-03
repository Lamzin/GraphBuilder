#include <deque>
#include <fstream>

#include "GraphParser.h"
#include "PointerFunction.h"
#include "QParser.h"

namespace QuickMathParser
{
	float GraphParser::GetValue(float x, float y)
	{
		xtmp = x;
		ytmp = y;

		return returnList[1]->GetValue(returnList[1]->simpleOperation);
	}

	void GraphParser::makeGraph()
	{
		deque <pair<ReturnStruct, pair<int, bool>>> que;
		ReturnStruct *LeftStruct = nullptr, *RightStruct = nullptr;

		float(*funcPtr)(float a, float b) = nullptr;

		QuickMathParser::QParser parser(str);
		pair <int, int> fail = make_pair(-1, -1);

		returnList.Add(gcnew GraphParserStruct(0.0f));
		que.push_back(make_pair(parser.GetValue(make_pair(0, str->Length - 1)), make_pair(0, false)));
		
		while (que.size())
		{
			if (que.front().first.leftOperand != fail && que.front().first.rightOperand != fail)
			{
				LeftStruct  = &parser.GetValue(que.front().first.leftOperand);
				RightStruct = &parser.GetValue(que.front().first.rightOperand);

				funcPtr = functionPointerINIT(que.front().first.operation).function;

				returnList.Add(gcnew GraphParserStruct(funcPtr, returnList[0], returnList[0]));

				que.push_back(make_pair(*LeftStruct, make_pair(returnList.Count - 1, true)));
				que.push_back(make_pair(*RightStruct, make_pair(returnList.Count - 1, false)));
			}
			else if (que.front().first.leftOperand != fail && que.front().first.rightOperand == fail)
			{
				LeftStruct = &parser.GetValue(que.front().first.leftOperand);

				funcPtr = functionPointerINIT(que.front().first.operation).function;

				returnList.Add(gcnew GraphParserStruct(funcPtr, returnList[0], returnList[0]));

				que.push_back(make_pair(*LeftStruct, make_pair(returnList.Count - 1, true)));
			}
			else if (que.front().first.leftOperand == fail && que.front().first.rightOperand == fail)
			{
				if (que.front().first.operation == QuickMathParser::CalcValue)
				{
					returnList.Add(gcnew GraphParserStruct(que.front().first.value));
				}
				else
				{
					funcPtr = functionPointerINIT(que.front().first.operation).function;
					returnList.Add(gcnew GraphParserStruct(funcPtr));
				}
			}

			if (que.front().second.second == true) returnList[que.front().second.first]->leftOperand = returnList[returnList.Count - 1];
			else returnList[que.front().second.first]->rightOperand = returnList[returnList.Count - 1];

			que.pop_front();
		}
	}
}