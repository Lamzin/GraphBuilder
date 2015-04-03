#include "header.h"
#include "MathFunction.h"
#include "GraphProperties.h"
#include "Render.h"
#include "Function.h"
#include "..\Animation\Animation.h"
#include "Rectangles.h"
#include "Event.h"

using namespace std;
using namespace Render;

HRESULT Render::hr;
ID2D1Factory *Render::d2dFactory;
IDWriteTextFormat *Render::m_pTextFormat;
IDWriteFactory *Render::m_pDWriteFactory;
ID2D1StrokeStyle *Render::d2dStrokeStyle = NULL, *Render::m_pStrokeStyleCustomOffsetZero, *Render::m_pStrokeStyleDot, *Render::m_pStrokeStyleDash, *Render::m_pStrokeStyleDashDot;
ID2D1HwndRenderTarget *Render::d2dRenderTarget;
ID2D1SolidColorBrush *Render::d2dBrush_axis, *Render::d2dBrush_reticulum, *Render::d2dBrush_default, *Render::d2dBrush_line, *Render::d2dBrush_simple, *Render::d2dBrush_Asymptotes, *Render::d2dBrush_rect;
string Render::strtmp;
TypeOfAnimation Render::AnimOnOf = None;
vector <Rectangles> Render::RectVect;
MyGraphPointStruct Render::MyGraphPointObject;
bool Render::bGraphBuildDefault[10] = { false };
float Render::CONST_EMPTY_POINT = 10.0f, Render::WindowWidth = 800.0f, Render::WindowHeight = 800.0f;

ID2D1Bitmap *Render::d2dBitmap;
pair <int, int> Render::outputSize;
uint32* Render::outputBitmap;

//unsigned long __stdcall Render::RenderThreadMain(void* args)
//{
//	/*HANDLE hEvent = CreateEvent(0, true, false, L"hEvent");
//	CreateThread(nullptr, 0, RenderThreadMain, hWnd, 0, nullptr);*/
//	while (true)
//	{
//		WaitForSingleObject(hEventRender, INFINITY);
//		Renderer::Render();
//	};
//	return 0;
//}

void Renderer::Render()
{
	long long  BEG = clock();

	// -------------------- INIT BITMAP BACKGROUND -------------------- //
	uint32 WIND_HEI = (uint32) Graph->window_height, WIND_WID = (uint32) Graph->window_width;
	uint32 ColorBackGround = FuncColorEquation(-1, 128);
	
	for (uint32 y = 0; y < WIND_HEI; y++)
	for (uint32 x = 0; x < WIND_WID; x++)
		Render::outputBitmap[x + y * Render::outputSize.first] = ColorBackGround;
	// -------------------- INIT BITMAP BACKGROUND -------------------- //


	{
		bool firstIteration = true;

		Animation::AnimationStatus = ANIMBegin;

		while (Animation::AnimationStatus != ANIMEnd)
		{
			d2dRenderTarget->BeginDraw();
			d2dRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::Snow));

			if (AnimOnOf == IntegOfFunc && Animation::AnimationAllow == ANIMAllow)
			{
				if (firstIteration) Animation::AnimationStatus = ANIMBegin;
				firstIteration = false;
				Animation::IntegralPartOfFunction();
			}
			else if (AnimOnOf == IntegOfArg && Animation::AnimationAllow == ANIMAllow)
			{
				if (firstIteration) Animation::AnimationStatus = ANIMBegin;
				firstIteration = false;
				Animation::IntegralPartOfArgument();
			}
			else if (AnimOnOf == FracOfFunc && Animation::AnimationAllow == ANIMAllow)
			{
				if (firstIteration) Animation::AnimationStatus = ANIMBegin;
				firstIteration = false;
				Animation::FractionalPartOfFunction();
			}
			else if (AnimOnOf == FracOfArg && Animation::AnimationAllow == ANIMAllow)
			{
				if (firstIteration) Animation::AnimationStatus = ANIMBegin;
				firstIteration = false;
				Animation::FractionalPartOfArgument();
			}
			else
			{
				Animation::AnimationStatus = ANIMEnd;
				RenderDrawGraph();
				RenderDrawAllRectangle();
			}

			RenderDrawReticulum();
			RenderWriteScale();
			d2dRenderTarget->EndDraw();
		}
	}

	d2dRenderTarget->BeginDraw();
	Renderer::RenderWriteTotalTime((double) (clock() - BEG) / CLOCKS_PER_SEC);
	d2dRenderTarget->EndDraw();
};


void Renderer::DrawLine(float xtmp1, float ytmp1, float xtmp2, float ytmp2, D2D1::ColorF LineColor)
{
	d2dBrush_line->SetColor(LineColor);

	d2dRenderTarget->DrawLine(
		D2D1::Point2F(Graph->centreX * Graph->scale + xtmp1 * Graph->scale, Graph->centreY * Graph->scale - ytmp1 * Graph->scale),
		D2D1::Point2F(Graph->centreX * Graph->scale + xtmp2 * Graph->scale, Graph->centreY * Graph->scale - ytmp2 * Graph->scale),
		d2dBrush_line, 2.0f);
}

void Renderer::DrawEmptyPoint(float xtmp1, float ytmp1, D2D1::ColorF PointColor)
{
	//if (bDrawEmptyPoints == true)
	{
		static float Radius;
		Radius = 3.0f;
		
		d2dBrush_line->SetColor(D2D1::ColorF(D2D1::ColorF::Snow));
		d2dRenderTarget->FillEllipse(D2D1::Ellipse(D2D1::Point2F(Graph->centreX * Graph->scale + xtmp1 * Graph->scale, Graph->centreY * Graph->scale - ytmp1 * Graph->scale), Radius, Radius), d2dBrush_line);

		d2dBrush_line->SetColor(PointColor);
		d2dRenderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(Graph->centreX * Graph->scale + xtmp1 * Graph->scale, Graph->centreY * Graph->scale - ytmp1 * Graph->scale), Radius, Radius), d2dBrush_line);
	}
}

void Renderer::RenderDrawReticulum()
{

	if (bDrawAxis == true)
	{
		d2dRenderTarget->DrawLine(D2D1::Point2F(0.0f, Graph->centreY * Graph->scale), D2D1::Point2F(Graph->window_width, Graph->centreY * Graph->scale), d2dBrush_axis, 1.0f);
		d2dRenderTarget->DrawLine(D2D1::Point2F(Graph->centreX * Graph->scale, 0.0f), D2D1::Point2F(Graph->centreX * Graph->scale, Graph->window_height), d2dBrush_axis, 1.0f);
	}

	if (bDrawReticulum == true)
	{
		//Create d2dStrokeStyle;
		CreateStrokeStyleObject();

		for (float itmp = 0.0f; itmp <= Graph->window_width; itmp += Graph->scale)
			d2dRenderTarget->DrawLine(D2D1::Point2F(itmp, 0.0f), D2D1::Point2F(itmp, Graph->window_height), d2dBrush_reticulum, 0.5f);

		for (float itmp = 0.0f; itmp <= Graph->window_height; itmp += Graph->scale)
			d2dRenderTarget->DrawLine(D2D1::Point2F(0.0f, itmp), D2D1::Point2F(Graph->window_width, itmp), d2dBrush_reticulum, 0.5f);
	}

};

float Renderer::inte(float tmp)
{
	return MyMath::GetIntegralPart(tmp);
}

float Renderer::frac(float tmp)
{
	return MyMath::GetFractionalPart(tmp);
}

void Renderer::SetString(System::String ^str)
{
	System::String ^strResult = "";

	strtmp = "";
	for (int i = 0; i < str->Length; i++)
	if (str[i] != '\r' && str[i] != '\n' && str[i] != '\r\n' && str[i] != '\t' && str[i] != ' ')
	{
		strtmp += (char) str[i];
		strResult += str[i];
	}

	fstream data("Function.txt", ios::app);
	data << strtmp << endl;

	Function::MyFuncArray.Clear();//clear array of all prev functions!
	Function::StringProcessing(strResult);
};

void Renderer::SetbDrawReticulum()
{
	if (bDrawReticulum == true) bDrawReticulum = false;
	else bDrawReticulum = true;
}

void Renderer::SetbDrawAxis()
{
	if (bDrawAxis == true) bDrawAxis = false;
	else bDrawAxis = true;
}

void Renderer::SetbDrawGraph()
{
	if (bDrawGraph == true) bDrawGraph = false;
	else bDrawGraph = true;
}

void Renderer::SetbDrawAsymptotes()
{
	if (bDrawAsymptotes == true) bDrawAsymptotes = false;
	else bDrawAsymptotes = true;
}

void Renderer::SetbDrawEmptyPoints()
{
	if (bDrawEmptyPoints < 5) bDrawEmptyPoints++;
	else bDrawEmptyPoints = 1;
}

void Renderer::DrawAsymptotes(float xasymptote, int funcNumber)
{
	//Create d2dStrokeStyle;
	//CreateStrokeStyleObject();
	if (bDrawAsymptotes == true)
	{
		d2dBrush_default->SetColor(FuncColor(funcNumber, 1.0f));

		d2dRenderTarget->DrawLine(
			D2D1::Point2F(Graph->centreX * Graph->scale + xasymptote * Graph->scale, Graph->centreY * Graph->scale + Graph->up * Graph->scale),
			D2D1::Point2F(Graph->centreX * Graph->scale + xasymptote * Graph->scale, Graph->centreY * Graph->scale + Graph->down * Graph->scale),
			d2dBrush_default/*d2dBrush_Asymptotes*/, 1.0f, m_pStrokeStyleCustomOffsetZero);

		d2dBrush_default->SetColor(D2D1::ColorF(D2D1::ColorF::Black));
	}
}

void MyGraphPointStruct::ChangeDefaultType()
{
	for (int i = 1; i < MyGraphPointObject.size - 1; i++)
	{
		TryFindAsymptotes(i);
		TryFindEmptyPoint(i);
	}
}

void MyGraphPointStruct::TryFindAsymptotes(int number)
{
	if (abs((Y[number] - Ynext[number]) / (X[number] - Xnext[number])) > Renderer::Graph->DeltaFunctionBuild)
		type[number] = Asymptote;
}

void MyGraphPointStruct::TryFindEmptyPoint(int number)
{
	if (number > 2 && number < Y.size())
	{
		if (abs(((Y[number-2] - Ynext[number-2]) / (X[number-2] - Xnext[number-2])) - ((Y[number-1] - Ynext[number-1]) / (X[number-1] - Xnext[number-1]))) < 0.1f
			&& abs((Y[number] - Ynext[number]) / (X[number] - Xnext[number])) > CONST_EMPTY_POINT) type[number] = EmptyPoint;
	}
}

void Renderer::RenderDrawAllRectangle()
{
	for (int i = 0; i < RectVect.size(); i++)
	{
		d2dBrush_rect->SetColor(FuncColor(RectVect[i].colorNumb, 0.25f));
		d2dRenderTarget->FillRectangle(
			D2D1::RectF(
					RectVect[i].x.first * Graph->scale + Graph->centreX * Graph->scale, 
					0.0f, 
					RectVect[i].x.second* Graph->scale + Graph->centreX * Graph->scale, 
					WindowHeight), 
			d2dBrush_rect);
	}
	RectVect.clear();
}