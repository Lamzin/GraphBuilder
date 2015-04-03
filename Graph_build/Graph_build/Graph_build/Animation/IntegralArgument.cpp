#include "../Graph Builder/header.h"
#include "../Graph Builder/MathFunction.h"
#include "../Graph Builder/GraphProperties.h"
#include "../Graph Builder/Render.h"
#include "../Graph Builder/Function.h"
#include "../Graph Builder/Rectangles.h"
#include "Animation.h"

using namespace std;
using namespace Render;

void Animation::IntegralPartOfArgument()
{
	if (Function::MyFuncArray.Count > 0)
	{
		float xtmp, ytmp, ynext, xnext;

		Xanim = Renderer::Graph->left;
		//Xanim - vertical animation param

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

			for (xtmp = Renderer::Graph->left; xtmp <= Renderer::Graph->right; xtmp += Renderer::Graph->step)
			{
				xnext = xtmp + Renderer::Graph->step;

				ytmp = Function::MyFuncArray[0]->Value(xtmp, 0.0f);
				ynext = Function::MyFuncArray[0]->Value(xnext, 0.0f);

				MyGraphPointObject.X.push_back(xtmp);
				MyGraphPointObject.Y.push_back(ytmp);
				MyGraphPointObject.Xnext.push_back(xnext);
				MyGraphPointObject.Ynext.push_back(ynext);
				MyGraphPointObject.Yneed.push_back(Function::MyFuncArray[0]->Value(MyMath::GetIntegralPart(xtmp), 0.0f));
				MyGraphPointObject.type.push_back(Line);
				MyGraphPointObject.size++;
			}
		}

		AnimationStatus = ANIMProcessing;

		{
			MyGraphPointObject.ChangeDefaultType();

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
						Renderer::DrawLine(
							MyGraphPointObject.X[itmp],
							MyGraphPointObject.Y[itmp],
							MyGraphPointObject.Xnext[itmp],
							MyGraphPointObject.Ynext[itmp],
							Renderer::FuncColor(0, 1.0f));
					}
				}
			}

			{
				AnimationStatus = ANIMEnd;

				bool CHANGE_SOMETHING = false;

				while (AnimationStatus == ANIMEnd)
				{
					d2dBrush_rect->SetColor(Renderer::FuncColor(1, 0.1f));
					d2dRenderTarget->FillRectangle(
						D2D1::RectF(
						MyMath::GetIntegralPart((float)((int) (Renderer::Graph->centreX + Xanim))) * Renderer::Graph->scale,
						0.0f,
						MyMath::GetIntegralPart(((float)(int) (Renderer::Graph->centreX + Xanim + 1))) * Renderer::Graph->scale,
						WindowHeight),
						d2dBrush_rect);

					for (int itmp = 0; itmp < MyGraphPointObject.size; itmp++)
					{
						if (MyGraphPointObject.Y[itmp] > -1 * Renderer::Graph->down && MyGraphPointObject.Y[itmp] < -1 * Renderer::Graph->up)
						{
							if (MyGraphPointObject.X[itmp] >= Xanim && MyGraphPointObject.X[itmp] < Xanim + 1)
							{
								if (MyGraphPointObject.Y[itmp] > MyGraphPointObject.Yneed[itmp])
								{
									AnimationStatus = ANIMProcessing;
									MyGraphPointObject.Y[itmp] = MyGraphPointObject.Y[itmp] - 0.3f;
									//
									MyGraphPointObject.Ynext[itmp] = MyGraphPointObject.Ynext[itmp] - 0.3f;
									//
									if (MyGraphPointObject.Y[itmp] < MyGraphPointObject.Yneed[itmp])
									{
										MyGraphPointObject.Y[itmp] = MyGraphPointObject.Yneed[itmp];
										MyGraphPointObject.Ynext[itmp] = MyGraphPointObject.Yneed[itmp];
									}
								}
								else if (MyGraphPointObject.Y[itmp] < MyGraphPointObject.Yneed[itmp])
								{
									AnimationStatus = ANIMProcessing;
									MyGraphPointObject.Y[itmp] = MyGraphPointObject.Y[itmp] + 0.3f;
									//
									MyGraphPointObject.Ynext[itmp] = MyGraphPointObject.Ynext[itmp] + 0.3f;
									//
									if (MyGraphPointObject.Y[itmp] > MyGraphPointObject.Yneed[itmp])
									{
										MyGraphPointObject.Y[itmp] = MyGraphPointObject.Yneed[itmp];
										MyGraphPointObject.Ynext[itmp] = MyGraphPointObject.Yneed[itmp];
									}
								}
								else MyGraphPointObject.Y[itmp] = MyGraphPointObject.Ynext[itmp] = MyGraphPointObject.Yneed[itmp];
							}
						}
						else
						{
							MyGraphPointObject.Ynext[itmp] = MyGraphPointObject.Y[itmp];
						}
					}

					if (AnimationStatus == ANIMEnd) Xanim = Xanim + 1.0f;
					if (Xanim > Renderer::Graph->right)
					{
						AnimationStatus = ANIMEnd;
						break;
					}
				}
			}
			// </change Y>
		}
		//Sleep(15);
	}
	else AnimationStatus = ANIMEnd;
}