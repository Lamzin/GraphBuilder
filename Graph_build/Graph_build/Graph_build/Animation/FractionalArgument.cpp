#include "../Graph Builder/header.h"
#include "../Graph Builder/MathFunction.h"
#include "../Graph Builder/GraphProperties.h"
#include "../Graph Builder/Render.h"
#include "../Graph Builder/Function.h"
#include "../Graph Builder/Rectangles.h"
#include "Animation.h"

using namespace std;
using namespace Render;

void Animation::FractionalPartOfArgument()
{
	//fstream test("test.txt", ios::app);

	if (Function::MyFuncArray.Count > 0)
	{
		float xtmp, ytmp, ynext, xnext;

		if (AnimationStatus == ANIMBegin)
		{
			MyGraphPointObject.X.clear();
			MyGraphPointObject.Y.clear();
			MyGraphPointObject.Xnext.clear();
			MyGraphPointObject.Ynext.clear();
			MyGraphPointObject.Xneed.clear();
			MyGraphPointObject.Yneed.clear();
			MyGraphPointObject.type.clear();
			MyGraphPointObject.size = 0;

			for (xtmp = Renderer::Graph->left; xtmp <= Renderer::Graph->right; xtmp += Renderer::Graph->step/4)
			{
				xnext = xtmp + Renderer::Graph->step;

				ytmp = Function::MyFuncArray[0]->Value(MyMath::GetFractionalPart(xtmp), 0.0f);
				ynext = Function::MyFuncArray[0]->Value(MyMath::GetFractionalPart(xnext), 0.0f);

				MyGraphPointObject.X.push_back(MyMath::GetFractionalPart(xtmp));
				MyGraphPointObject.Y.push_back(ytmp);
				
				if (MyMath::GetFractionalPart(xnext) < MyMath::GetFractionalPart(xtmp))
				{
					MyGraphPointObject.Xnext.push_back(MyMath::GetFractionalPart(xtmp));
					MyGraphPointObject.Ynext.push_back(ytmp);
				}
				else
				{
					MyGraphPointObject.Xnext.push_back(MyMath::GetFractionalPart(xnext));
					MyGraphPointObject.Ynext.push_back(ynext);
				}

				MyGraphPointObject.Yneed.push_back(ytmp);
				MyGraphPointObject.Xneed.push_back(xtmp);
				MyGraphPointObject.type.push_back(Line);
				MyGraphPointObject.size++;

				//test << "X = " << MyMath::GetFractionalPart(xtmp) << "; ";
				//test << "xneed = " << xtmp << "; ";
				//test << endl;

			}
		}

		AnimationStatus = ANIMProcessing;

		{
			float MinValue = 100500, MaxValue = -100500;

			//MyGraphPointObject.ChangeDefaultType();

			for (int itmp = 0; itmp < MyGraphPointObject.size; itmp++)
			{
				if (MyGraphPointObject.type[itmp] == Line)
				{
					if (MyGraphPointObject.Y[itmp] < -1 * Renderer::Graph->up
						&&
						MyGraphPointObject.Y[itmp] > -1 * Renderer::Graph->down
						&&
						MyGraphPointObject.Ynext[itmp] < -1 * Renderer::Graph->up
						&&
						MyGraphPointObject.Ynext[itmp] > -1 * Renderer::Graph->down
						&&
						!(MyGraphPointObject.Y[itmp] == MyGraphPointObject.Yneed[itmp]
						&& abs(MyGraphPointObject.Y[itmp] - MyGraphPointObject.Ynext[itmp]) == 1)
						)
					{
						//test << "DRAW :: X = " << MyGraphPointObject.X[itmp] << "; ";
						//test << "xneed = " << MyGraphPointObject.Xneed[itmp] << "; ";
						//test << endl;

						Renderer::DrawLine(
							MyGraphPointObject.X[itmp],
							MyGraphPointObject.Y[itmp],
							MyGraphPointObject.Xnext[itmp],
							MyGraphPointObject.Ynext[itmp],
							Renderer::FuncColor(0, 1.0f));
					}

					MinValue = min(MinValue, MyGraphPointObject.X[itmp]);
					MaxValue = max(MaxValue, MyGraphPointObject.X[itmp]);
				}				
			}

			d2dBrush_rect->SetColor(Renderer::FuncColor(1, 0.1f));
			d2dRenderTarget->FillRectangle(
				D2D1::RectF(
				(MinValue + Renderer::Graph->centreX)*Renderer::Graph->scale,
				0.0f,
				(MaxValue + Renderer::Graph->centreX)*Renderer::Graph->scale,
				WindowHeight),
				d2dBrush_rect);


			AnimationStatus = ANIMEnd;

			while (AnimationStatus == ANIMEnd)
			{
				for (int itmp = 0; itmp < MyGraphPointObject.size; itmp++)
				{
					//AnimationStatus = ANIMEnd;

					if (MyGraphPointObject.X[itmp] > MyGraphPointObject.Xneed[itmp])
					{
						AnimationStatus = ANIMProcessing;
						MyGraphPointObject.X[itmp] = MyGraphPointObject.X[itmp] - 0.2f;
						//
						MyGraphPointObject.Xnext[itmp] = MyGraphPointObject.Xnext[itmp] - 0.2f;
						//
						if (MyGraphPointObject.X[itmp] < MyGraphPointObject.Xneed[itmp])
						{
							MyGraphPointObject.X[itmp] = MyGraphPointObject.Xneed[itmp];
							MyGraphPointObject.Xnext[itmp] = MyGraphPointObject.Xneed[itmp] + 0.2f;
						}
					}
					else if (MyGraphPointObject.X[itmp] < MyGraphPointObject.Xneed[itmp])
					{
						AnimationStatus = ANIMProcessing;
						MyGraphPointObject.X[itmp] = MyGraphPointObject.X[itmp] + 0.2f;
						//
						MyGraphPointObject.Xnext[itmp] = MyGraphPointObject.Xnext[itmp] + 0.2f;
						//
						if (MyGraphPointObject.X[itmp] > MyGraphPointObject.Xneed[itmp])
						{
							MyGraphPointObject.X[itmp] = MyGraphPointObject.Xneed[itmp];
							MyGraphPointObject.Xnext[itmp] = MyGraphPointObject.Xneed[itmp] + 0.2f; 
						}
					}
					else MyGraphPointObject.X[itmp] = MyGraphPointObject.Xnext[itmp] = MyGraphPointObject.Xneed[itmp];
				}

				break;
			}
		}
		//Sleep(150);
	}
	else AnimationStatus = ANIMEnd;
}