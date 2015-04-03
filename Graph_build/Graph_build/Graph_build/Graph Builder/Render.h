#pragma once

#include "header.h"
#include "GraphProperties.h"

using namespace GraphProp;
using namespace std;

namespace Render
{
	/*static*/ LRESULT __stdcall WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	public ref class Renderer
	{
	public:
		static inline void DrawLine(float xtmp1, float ytmp1, float xtmp2, float ytmp2, D2D1::ColorF LineColor);
	//private:
		static inline void DrawEmptyPoint(float xtmp1, float ytmp1, D2D1::ColorF PointColor);
		static inline void RenderDrawGraph();
		static inline void RenderDrawReticulum();
		static inline void RenderWriteTotalTime(double time);
		static inline void RenderDrawAllRectangle();
		static inline void RenderEquation(int function_number);
		static inline float inte(float tmp);
		static inline float frac(float tmp);
		static bool bDrawReticulum = true, bDrawAxis = true, bDrawGraph = true, bDrawAsymptotes = true;
		static int bDrawEmptyPoints = 1;
		static inline void CreateStrokeStyleObject();
		static inline void DrawAsymptotes(float xasymptote, int funcNumber);
		static inline D2D1::ColorF FuncColor(int count, float opacity);
		static inline uint32 FuncColorEquation(uint32 count, uint32 opacity);

	public:
		static string *MathExpression;
		static GraphProperties ^Graph = gcnew GraphProperties();
		//static GraphProperties *Graph;
		static inline void Initialize();
		static inline void Render();
		static inline void RenderWindow(float WinWidth, float WinHeight, int animationParam);
		static inline void SetString(System::String ^str);
		static void SetbDrawReticulum();
		static void SetbDrawAxis();
		static void SetbDrawGraph();
		static void SetbDrawEmptyPoints();
		static void SetbDrawAsymptotes();

		static void RenderWriteScale();
	};

	enum TypeOfLine	{ Line, EmptyPoint, EmptyPointNext, Asymptote };

	struct MyGraphPointStruct
	{
	public:
		vector <float> X;
		vector <float> Y;
		vector <float> Xnext;
		vector <float> Ynext;
		vector <float> Yneed;
		vector <float> Xneed;
		vector <TypeOfLine> type;
		int size;

		void ChangeDefaultType();
	private:
		void TryFindAsymptotes(int number);
		void TryFindEmptyPoint(int number);
	};

	extern float CONST_EMPTY_POINT;

	//extern std::string strtmp;
	extern float WindowWidth, WindowHeight;
	
	extern HRESULT hr;
	extern ID2D1Factory *d2dFactory;
	extern IDWriteTextFormat *m_pTextFormat;
	extern IDWriteFactory *m_pDWriteFactory;
	extern ID2D1StrokeStyle *d2dStrokeStyle/* = NULL*/;
	extern ID2D1StrokeStyle *m_pStrokeStyleCustomOffsetZero, *m_pStrokeStyleDot, *m_pStrokeStyleDash, *m_pStrokeStyleDashDot;
	extern ID2D1HwndRenderTarget *d2dRenderTarget;
	extern ID2D1SolidColorBrush *d2dBrush_axis, *d2dBrush_reticulum, *d2dBrush_default, *d2dBrush_line, *d2dBrush_simple, *d2dBrush_Asymptotes, *d2dBrush_rect;
	extern bool bGraphBuildDefault[10]/* = { false }*/;
	extern string strtmp;
	
	extern MyGraphPointStruct MyGraphPointObject;

	extern ID2D1Bitmap *d2dBitmap;
	extern pair <int, int> outputSize;
	extern uint32* outputBitmap;

	/*HANDLE hEventRender = CreateEvent(0, true, false, L"hEvent");
	unsigned long __stdcall RenderThreadMain(void* args);*/
}