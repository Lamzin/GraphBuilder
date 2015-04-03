#include "header.h"

#include "MathFunction.h"
#include "GraphProperties.h"
#include "Render.h"
#include "Function.h"
#include "..\Animation\Animation.h"
#include "Rectangles.h"


using namespace std;
using namespace Render;

void Renderer::RenderDrawGraph()
{
	if (bDrawGraph)
	{
		float xtmp, ytmp, ynext, xnext, ynextFunction,
			RectStart, RectFinish;
		bool bRectStart = false, canmakeRect = false;

		for (int count_function = 0; count_function < Function::MyFuncArray.Count; count_function++)
		{
			if (count_function + 1 < Function::MyFuncArray.Count 
				&& 
				Function::MyFuncArray[count_function]->simple == false 
				&& 
				(Function::MyFuncArray[count_function]->str->IndexOf("y") >= NULL 
				|| 
				Function::MyFuncArray[count_function+1]->str->IndexOf("y") >= NULL))
			{
				Renderer::RenderEquation(count_function);
				count_function++;
			}
			else
			{
				MyGraphPointObject.X.clear();
				MyGraphPointObject.Y.clear();
				MyGraphPointObject.Xnext.clear();
				MyGraphPointObject.Ynext.clear();
				MyGraphPointObject.type.clear();
				MyGraphPointObject.size = 0;

				bool bflag = false;

				float STEP = Graph->step;
				if (Graph->ScaleHyperMode == true) STEP = STEP / Graph->HyperModeKoef;

				bRectStart = false;
				canmakeRect = Function::MyFuncArray[count_function]->simple == false
					&&
					Function::MyFuncArray[count_function]->OperatorType != NoneOper
					&&
					count_function < Function::MyFuncArray.Count - 1;

				for (xtmp = Graph->left; xtmp <= Graph->right; xtmp += STEP)
					//	for (xtmp = Graph->left; xtmp <= Graph->right; (inte(xtmp + Graph->step) == inte(xtmp) || xtmp == inte(xtmp)) ? xtmp += Graph->step : xtmp = inte(xtmp) + 1 +((xtmp > 0) ? 0 : 0))
				{
					xnext = xtmp + STEP;

					ytmp = Function::MyFuncArray[count_function]->Value(xtmp, 0.0f);
					ynext = Function::MyFuncArray[count_function]->Value(xnext, 0.0f);

					if (canmakeRect)
					{
						ynextFunction = Function::MyFuncArray[count_function + 1]->Value(xtmp, 0.0f);

						if ((Function::MyFuncArray[count_function]->OperatorType == Less			&&		ytmp < ynextFunction)
							||
							(Function::MyFuncArray[count_function]->OperatorType == LessOrEqual		&&		ytmp <= ynextFunction)
							||
							(Function::MyFuncArray[count_function]->OperatorType == More			&&		ytmp > ynextFunction)
							||
							(Function::MyFuncArray[count_function]->OperatorType == MoreOrEqual		&&		ytmp >= ynextFunction)
							||
							(Function::MyFuncArray[count_function]->OperatorType == Equal			&&		ytmp == ynextFunction))
						{
							if (bRectStart)
							{
								RectFinish = xtmp;
							}
							else
							{
								bRectStart = true;
								RectStart = xtmp;
								RectFinish = xtmp;
							}
						}
						else
						{
							if (bRectStart == true)
							{
								bRectStart = false;

								if (Function::MyFuncArray[count_function]->OperatorType == Less
									||
									Function::MyFuncArray[count_function]->OperatorType == LessOrEqual)
								{
									Rectangles MyRect(RectStart, RectFinish, count_function + 1);
									RectVect.push_back(MyRect);
								}
								else
								{
									Rectangles MyRect(RectStart, RectFinish, count_function);
									RectVect.push_back(MyRect);
								}
							}

						}
					}

					MyGraphPointObject.X.push_back(xtmp);
					MyGraphPointObject.Y.push_back(ytmp);
					MyGraphPointObject.Xnext.push_back(xnext);
					MyGraphPointObject.Ynext.push_back(ynext);
					MyGraphPointObject.type.push_back(Line);
					MyGraphPointObject.size++;
				}
				// Find last Rectangles!
				if (bRectStart == true)
				{
					bRectStart = false;

					if (Function::MyFuncArray[count_function]->OperatorType == Less
						||
						Function::MyFuncArray[count_function]->OperatorType == LessOrEqual)
					{
						Rectangles MyRect(RectStart, RectFinish, count_function + 1);
						RectVect.push_back(MyRect);
					}
					else
					{
						Rectangles MyRect(RectStart, RectFinish, count_function);
						RectVect.push_back(MyRect);
					}
				}
				//

				MyGraphPointObject.ChangeDefaultType();

				for (int itmp = 0; itmp < MyGraphPointObject.size; itmp++)
				{
					if (MyGraphPointObject.type[itmp] == Line)
					{
						DrawLine(
							MyGraphPointObject.X[itmp],
							MyGraphPointObject.Y[itmp],
							MyGraphPointObject.Xnext[itmp],
							MyGraphPointObject.Ynext[itmp],
							FuncColor(count_function, 1.0f));
					}
				}

				for (int itmp = 0; itmp < MyGraphPointObject.size; itmp++)
				{
					if (MyGraphPointObject.type[itmp] == EmptyPoint)
					{
						//DrawEmptyPoint(MyGraphPointObject.X[itmp], MyGraphPointObject.Y[itmp], FuncColor(count_function, 1.0f));


						if (Render::Renderer::bDrawEmptyPoints == 1)
						{
							DrawEmptyPoint(MyGraphPointObject.X[itmp], MyGraphPointObject.Y[itmp], FuncColor(count_function, 1.0f));
						}
						else if (Render::Renderer::bDrawEmptyPoints == 2)
						{
							if (MyGraphPointObject.Y[itmp] > MyGraphPointObject.Ynext[itmp])
							{
								DrawEmptyPoint(MyGraphPointObject.X[itmp], MyGraphPointObject.Y[itmp], FuncColor(count_function, 1.0f));
							}
							else
							{
								DrawEmptyPoint(MyGraphPointObject.Xnext[itmp], MyGraphPointObject.Ynext[itmp], FuncColor(count_function, 1.0f));
							}
						}
						else if (Render::Renderer::bDrawEmptyPoints == 3)
						{
							if (MyGraphPointObject.Y[itmp] < MyGraphPointObject.Ynext[itmp])
							{
								DrawEmptyPoint(MyGraphPointObject.X[itmp], MyGraphPointObject.Y[itmp], FuncColor(count_function, 1.0f));
							}
							else
							{
								DrawEmptyPoint(MyGraphPointObject.Xnext[itmp], MyGraphPointObject.Ynext[itmp], FuncColor(count_function, 1.0f));
							}
						}
						else if (Render::Renderer::bDrawEmptyPoints == 4)
						{
							DrawEmptyPoint(MyGraphPointObject.Xnext[itmp], MyGraphPointObject.Ynext[itmp], FuncColor(count_function, 1.0f));
						}
						else
						{
							//not build EMPTY POINT!!!
						}
					}

					else if (MyGraphPointObject.type[itmp] == Asymptote)
					{
						DrawAsymptotes(MyGraphPointObject.X[itmp], count_function);
					}
				}

			}
		}
	}
};
