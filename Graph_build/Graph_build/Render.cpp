#include <Windows.h>
#include <d2d1.h>
#include <math.h>
#include <string>
#include <vcclr.h>

using namespace std;

#include "MathFunction.h"
#include "GraphProperties.h"
#include "Render.h"

using namespace Render;

ID2D1Factory *d2dFactory;
ID2D1HwndRenderTarget *d2dRenderTarget;
ID2D1SolidColorBrush *d2dBrush_axis, *d2dBrush_reticulum, *d2dBrush_integral, *d2dBrush_fractional, *d2dBrush_simple;
bool bGraphBuildDefault[10] = {false};
string strtmp;

void Renderer::DrawLine(double xtmp1, double ytmp1, double xtmp2, double ytmp2)
{
	d2dRenderTarget->DrawLine(
		D2D1::Point2F(Graph->centreX * Graph->scale + xtmp1 * Graph->scale, Graph->centreY * Graph->scale - ytmp1 * Graph->scale), 
		D2D1::Point2F(Graph->centreX * Graph->scale + xtmp2 * Graph->scale, Graph->centreY * Graph->scale - ytmp2 * Graph->scale), 
		d2dBrush_integral, 1.0f);
}

void Renderer::RenderDrawGraph()
{
	if (bDrawGraph)
	{
		double xtmp, ytmp, ynext, xnext;
		
		for (xtmp = Graph->left; xtmp <= Graph->right; xtmp += Graph->step)
		{
			xnext = xtmp + Graph->step;

			ytmp = MyMath::Math::MainFunction(xtmp);
			ynext = MyMath::Math::MainFunction(xnext);
			if (abs(ytmp-ynext) < 0.9f) DrawLine(xtmp, ytmp, xnext, ynext);

		}	
	}
};

void Renderer::RenderDrawALLDefaultGraph()
{
	double xtmp, ytmp, ynext, xnext;
		
	for (xtmp = Graph->left; xtmp <= Graph->right; xtmp += Graph->step)
	{
		xnext = xtmp + Graph->step;

		for (int itmp = 0; itmp < 10; itmp++)
			if (bGraphBuildDefault[itmp] == true)
			{
				ytmp = MyMath::Math::MainFunction(xtmp, itmp);
				ynext = MyMath::Math::MainFunction(xnext, itmp);
				if (abs(ytmp-ynext) < 0.9f) DrawLine(xtmp, ytmp, xnext, ynext);
			}
	}	
};

void Renderer::RenderDrawReticulum()
{

	if (bDrawAxis == true)
	{
		d2dRenderTarget->DrawLine(D2D1::Point2F(0.0f, Graph->centreY * Graph->scale), D2D1::Point2F(Graph->window_width, Graph->centreY * Graph->scale), d2dBrush_axis, 1.0f);
		d2dRenderTarget->DrawLine(D2D1::Point2F(Graph->centreX * Graph->scale, 0.0f), D2D1::Point2F(Graph->centreX * Graph->scale, Graph->window_height), d2dBrush_axis, 1.0f);
	}

	if (bDrawReticulum == true)
	{
		for (double itmp = 0.0f; itmp<= Graph->window_width; itmp += Graph->scale)
			d2dRenderTarget->DrawLine(D2D1::Point2F(itmp, 0.0f), D2D1::Point2F(itmp, Graph->window_height), d2dBrush_reticulum, 0.5f);

		for (double itmp = 0.0f; itmp<= Graph->window_height; itmp+=Graph->scale)
			d2dRenderTarget->DrawLine(D2D1::Point2F(0.0f, itmp), D2D1::Point2F(Graph->window_width, itmp), d2dBrush_reticulum, 0.5f); 
	}

};

double Renderer::inte(double tmp)
{
	return MyMath::Math::GetIntegralPart(tmp);
}

double Renderer::frac(double tmp)
{
	return MyMath::Math::GetFractionalPart(tmp);
}

void Renderer::Initialize()
	{		
		WNDCLASSEX wcex;
		HINSTANCE hInstance = GetModuleHandleW(nullptr);

		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = WndProc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = hInstance;
		wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
		wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wcex.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
		wcex.lpszMenuName = nullptr;
		wcex.lpszClassName = L"WndClass";
		wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
		RegisterClassEx(&wcex);	
	};
void Renderer::Render()
{
	d2dRenderTarget->BeginDraw();
	d2dRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::FloralWhite));
	//
	RenderDrawReticulum();
	RenderDrawGraph();	
	RenderDrawALLDefaultGraph();
	//
	d2dRenderTarget->EndDraw();		 
};

void Renderer::RenderWindow()
{
	HWND hWnd = CreateWindowW(L"WndClass", L"Render", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, Graph->window_width, Graph->window_height,
		nullptr, nullptr, GetModuleHandleW(nullptr), nullptr);

	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	MSG message = {0};
	do
	{
		if (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		else
			Render();
	} while (message.message != WM_QUIT);		
};

void Renderer::SetString(System::String ^str)
{
	//pin_ptr<wchar_t> strPinPtr = &str->ToCharArray[0];
	/*pin_ptr<const wchar_t> strPinPtr = PtrToStringChars(str);
	const wchar_t *strPtr = strPinPtr;
	*/ 
	//strtmp = myString;

	//unsigned int length = wcslen(strtmp);
	//memcpy(&strtmp, myString, sizeof(wchar_t) * (length + 1));
	//char* myString = new char[str->Length];
	/*for (int i = 0; i < str->Length; i++)
		myString += (char) str[i];*/
		//myString[i] = (char) str[i];
	//memcpy(&strtmp, myString, sizeof(char) * (str->Length));
	//strtmp = (string)(myString);
	//MathExpression = &strtmp;

	for (int i = 0; i < str->Length; i++)
		strtmp += (char) str[i];
	MathExpression = &strtmp;
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

LRESULT __stdcall Render::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			DestroyWindow(hWnd);
			break;
		case VK_LEFT:
			Render::Renderer::Graph->set_centreX(1);
			break;
		case VK_RIGHT:
			Render::Renderer::Graph->set_centreX(-1);
			break;
		case VK_UP:
			Render::Renderer::Graph->set_centreY(1);
			break;
		case VK_DOWN:
			Render::Renderer::Graph->set_centreY(-1);
			break;
		case VK_OEM_PLUS:
			Render::Renderer::Graph->set_width(-2);
			break;
		case VK_OEM_MINUS:
			Render::Renderer::Graph->set_width(2);
			break;
		case 0x41://press A
			Render::Renderer::SetbDrawAxis();
			break;
		case 0x52://press R
			Render::Renderer::SetbDrawReticulum();
			break;
		case 0x47://press G
			Render::Renderer::SetbDrawGraph();
			break;
			//
		case 0x30: 
			for (int i = 0; i<9; i++) bGraphBuildDefault[i] = false;
			break;
		case 0x31: 
			bGraphBuildDefault[0] = (bGraphBuildDefault[0]) ? false : true;
			break;
		case 0x32: 
			bGraphBuildDefault[1] = (bGraphBuildDefault[1]) ? false : true;
			break;
		case 0x33: 
			bGraphBuildDefault[2] = (bGraphBuildDefault[2]) ? false : true;
			break;
		case 0x34: 
			bGraphBuildDefault[3] = (bGraphBuildDefault[3]) ? false : true;
			break;
		case 0x35: 
			bGraphBuildDefault[4] = (bGraphBuildDefault[4]) ? false : true;
			break;
		case 0x36: 
			bGraphBuildDefault[5] = (bGraphBuildDefault[5]) ? false : true;
			break;
		case 0x37: 
			bGraphBuildDefault[6] = (bGraphBuildDefault[6]) ? false : true;
			break;
		case 0x38: 
			bGraphBuildDefault[7] = (bGraphBuildDefault[7]) ? false : true;
			break;
		case 0x39: 
			bGraphBuildDefault[8] = (bGraphBuildDefault[8]) ? false : true;
			break;
			//
		}
		break;
	case WM_MOUSEHOVER:
		switch(wParam)
		{
		case MK_LBUTTON: 
			Render::Renderer::Graph->set_width(-2);
		case MK_RBUTTON:
			Render::Renderer::Graph->set_width(2);
		}
	case WM_CREATE:
		D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, D2D1_FACTORY_OPTIONS(), &d2dFactory);
		RECT rect;
		GetClientRect(hWnd, &rect);
		d2dFactory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(),
			D2D1::HwndRenderTargetProperties(hWnd, D2D1::SizeU(rect.right - rect.left, rect.bottom - rect.top)), &d2dRenderTarget);
		d2dRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::DarkBlue), &d2dBrush_axis);
		d2dRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Blue), &d2dBrush_reticulum);
		d2dRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Brown), &d2dBrush_integral);
		d2dRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::DarkGreen), &d2dBrush_fractional);
		d2dRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Black), &d2dBrush_simple);
		break;
	case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	return 0;
}