#include "../Graph Builder/header.h"
#include "../Graph Builder/MathFunction.h"
#include "../Graph Builder/GraphProperties.h"
#include "../Graph Builder/Render.h"
#include "../Graph Builder/Function.h"
#include "../Graph Builder/Rectangles.h"
#include "Animation.h"

using namespace std;
using namespace Render;

void Animation::FractionalPartOfFunction()
{
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

			for (xtmp = Renderer::Graph->left; xtmp <= Renderer::Graph->right; xtmp += Renderer::Graph->step/2)
			{
				xnext = xtmp + Renderer::Graph->step;

				ytmp = Function::MyFuncArray[0]->Value(xtmp, 0.0f);
				ynext = Function::MyFuncArray[0]->Value(xnext, 0.0f);

				MyGraphPointObject.X.push_back(xtmp);
				MyGraphPointObject.Y.push_back(ytmp);
				MyGraphPointObject.Xnext.push_back(xnext);
				MyGraphPointObject.Ynext.push_back(ynext);
				MyGraphPointObject.Yneed.push_back(MyMath::GetFractionalPart(ytmp));
				MyGraphPointObject.type.push_back(Line);
				MyGraphPointObject.size++;
			}
		}

		AnimationStatus = ANIMProcessing;

		{
			MyGraphPointObject.ChangeDefaultType();

			float MinValue = 100500, MaxValue = -100500;

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
						)
					{
						Renderer::DrawLine(
							MyGraphPointObject.X[itmp],
							MyGraphPointObject.Y[itmp],
							MyGraphPointObject.Xnext[itmp],
							MyGraphPointObject.Ynext[itmp],
							Renderer::FuncColor(0, 1.0f));
					}

					if (MyGraphPointObject.Y[itmp] < -1 * Renderer::Graph->up
						&&
						MyGraphPointObject.Y[itmp] > -1 * Renderer::Graph->down
						&&
						MyGraphPointObject.Ynext[itmp] < -1 * Renderer::Graph->up
						&&
						MyGraphPointObject.Ynext[itmp] > -1 * Renderer::Graph->down
						)
					{
						//MinValue = min(MinValue, min(MyGraphPointObject.Y[itmp], MyGraphPointObject.Ynext[itmp]));
						//MaxValue = max(MaxValue, max(MyGraphPointObject.Y[itmp], MyGraphPointObject.Ynext[itmp]));

						MinValue = min(MinValue, MyGraphPointObject.Y[itmp]);
						MaxValue = max(MaxValue, MyGraphPointObject.Y[itmp]);
					}
				}
			}

			d2dBrush_rect->SetColor(Renderer::FuncColor(1, 0.1f));

			d2dRenderTarget->FillRectangle(
				D2D1::RectF(
				0.0f,
				(Renderer::Graph->centreY - MinValue) * Renderer::Graph->scale,
				WindowWidth,
				WindowHeight * Renderer::Graph->scale),
				d2dBrush_rect);

			d2dRenderTarget->FillRectangle(
				D2D1::RectF(
				0.0f,
				(Renderer::Graph->centreY - MaxValue) * Renderer::Graph->scale,
				WindowWidth,
				0),
				d2dBrush_rect);

			// <change Y>
			{
				AnimationStatus = ANIMEnd;

				for (int itmp = 0; itmp < MyGraphPointObject.size; itmp++)
				{
					if (MyGraphPointObject.Y[itmp] > -1 * Renderer::Graph->down && MyGraphPointObject.Y[itmp] < -1 * Renderer::Graph->up)
					{
						if (MyGraphPointObject.Y[itmp] > MyGraphPointObject.Yneed[itmp])
						{
							AnimationStatus = ANIMProcessing;

							MyGraphPointObject.Y[itmp] = MyGraphPointObject.Y[itmp] - 0.1f;

							if (MyGraphPointObject.Y[itmp] < MyGraphPointObject.Yneed[itmp])
							{
								MyGraphPointObject.Y[itmp] = MyGraphPointObject.Yneed[itmp];
								MyGraphPointObject.Ynext[itmp] = MyGraphPointObject.Yneed[itmp];
							}
						}
						else if (MyGraphPointObject.Y[itmp] < MyGraphPointObject.Yneed[itmp])
						{
							AnimationStatus = ANIMProcessing;

							MyGraphPointObject.Y[itmp] = MyGraphPointObject.Y[itmp] + 0.1f;

							if (MyGraphPointObject.Y[itmp] > MyGraphPointObject.Yneed[itmp])
							{
								MyGraphPointObject.Y[itmp] = MyGraphPointObject.Yneed[itmp];
								MyGraphPointObject.Ynext[itmp] = MyGraphPointObject.Yneed[itmp];
							}
						}
						else MyGraphPointObject.Y[itmp] = MyGraphPointObject.Yneed[itmp];

						if (itmp > 0) MyGraphPointObject.Ynext[itmp - 1] = MyGraphPointObject.Y[itmp];
					}
					else
					{
						MyGraphPointObject.Ynext[itmp] = MyGraphPointObject.Y[itmp];
					}
				}
			}
			// </change Y>
		}
		//Sleep(30);
	}
	else AnimationStatus = ANIMEnd;
}