#include "header.h"
#include "MathFunction.h"
#include "GraphProperties.h"
#include "Render.h"
#include "Function.h"
#include "../Animation/Animation.h"

using namespace Render;
using namespace std;

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

void Renderer::RenderWindow(float WinWidth, float WinHeight, int animationParam)
{
	Render::WindowWidth = WinWidth;
	Render::WindowHeight = WinHeight;
	Graph->DefaultSettings();

	wchar_t Name[256] = L"";
	for (int i = 0; i < strtmp.length(); i++)
		Name[i] = wchar_t(strtmp[i]);

	HWND hWnd = CreateWindowW(L"WndClass", Name/*L"Render"*/, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, (int)Graph->window_width, (int)Graph->window_height,
		nullptr, nullptr, GetModuleHandleW(nullptr), nullptr);

	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	Render::Animation::RunDefaultAnimation(animationParam);

	//hEventRender = CreateEvent(0, true, false, L"hEvent");
	//CreateThread(nullptr, 0, RenderThreadMain, hWnd, 0, nullptr);

	/*MSG message = { 0 };
	do
	{
		if (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		else
		{
			Render();
		}
	} while (message.message != WM_QUIT);*/

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
};

LRESULT __stdcall Render::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static bool needRender;
	static bool LeftButton = false;
	static std::pair <float, float> Prev, New;
	static std::pair <int, int> delta;

	needRender = false;

	switch (message)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
				case VK_ESCAPE:
					DestroyWindow(hWnd);
					break;
				case VK_SPACE:
					Renderer::Graph->on_HyperMode();
					Renderer::Render();
					Renderer::Graph->off_HyperMode();
					break;
				case VK_LEFT:
					Render::Renderer::Graph->set_centreX(1);
					needRender = true;
					break;
				case VK_RIGHT:
					Render::Renderer::Graph->set_centreX(-1);
					needRender = true;
					break;
				case VK_UP:
					Render::Renderer::Graph->set_centreY(1);
					needRender = true;
					break;
				case VK_DOWN:
					Render::Renderer::Graph->set_centreY(-1);
					needRender = true;
					break;
				case VK_OEM_PLUS:
					Render::Renderer::Graph->set_width(-2);
					needRender = true;
					break;
				case VK_OEM_MINUS:
					Render::Renderer::Graph->set_width(2);
					needRender = true;
					break;
				case VK_F1:
					Animation::RunDefaultAnimation(1);
					break;
				case VK_F2:
					Animation::RunDefaultAnimation(3);
					break;
				case VK_F3:
					Animation::RunDefaultAnimation(2);
					break;
				case VK_F4:
					Animation::RunDefaultAnimation(4);
					break;
				case VK_F5:
					Animation::SetAnimOnOf(5);
					needRender = true;
					break;
				/*case 0x41://press A
					Render::Renderer::SetbDrawAxis();
					{
						Renderer::Graph->off_HyperMode();
						Renderer::Render();
					}
					break;*/
				/*case 0x52://press R
					Render::Renderer::SetbDrawReticulum();
					{
						Renderer::Graph->off_HyperMode();
						Renderer::Render();
					}
					break;*/
				/*case 0x47://press G
					Render::Renderer::SetbDrawGraph();
					{
						Renderer::Graph->off_HyperMode();
						Renderer::Render();
					}
					break;*/

				case 0x4E://press N
					Renderer::Graph->set_DeltaFunctionBuild(-100);
					needRender = true;
					break;
				case 0x4D://press M
					Renderer::Graph->set_DeltaFunctionBuild(100);
					needRender = true;
					break;
				case 0x5A://press Z
					CONST_EMPTY_POINT = abs(CONST_EMPTY_POINT - 1);
					needRender = true;
					break;
				case 0x58://press X
					CONST_EMPTY_POINT = CONST_EMPTY_POINT + 1;
					needRender = true;
					break;
				case VK_BACK://press BACKSPACE
					Renderer::Graph->DefaultSettings();
					needRender = true;
					break;
				case 0x30://0
					Render::Renderer::bDrawReticulum = 
					Render::Renderer:: bDrawAxis = 
					Render::Renderer::bDrawGraph =
					Render::Renderer::bDrawAsymptotes = true;
					Render::Renderer::bDrawEmptyPoints = 1;
					needRender = true;
					break;
				case 0x31://1
					Render::Renderer::SetbDrawAxis();
					needRender = true;
					break;
				case 0x32://2
					Render::Renderer::SetbDrawReticulum();
					needRender = true;
					break;
				case 0x33://3
					Render::Renderer::SetbDrawGraph();
					needRender = true;
					break;
				case 0x34://4
					Render::Renderer::SetbDrawAsymptotes();
					needRender = true;
					break;
				case 0x35://5
					Render::Renderer::SetbDrawEmptyPoints();
					needRender = true;
					break;
				case 0x36://6
					break;
				case 0x37://7
					break;
				case 0x38://8
					break;//9
				case 0x39:
					break;
					//
		}
		break;
	case WM_MOUSEMOVE:

		switch (wParam)
		{
		case MK_LBUTTON:
			if (!LeftButton)
			{
				LeftButton = true;
				Prev.first = LOWORD(lParam);
				Prev.second = HIWORD(lParam);
				needRender = true;
			}
			break;
		case MK_RBUTTON:
		default:
			if (LeftButton)
			{
				New.first = LOWORD(lParam);
				New.second = HIWORD(lParam);

				delta.first = (int)((float)(New.first - Prev.first) / Render::Renderer::Graph->scale);
				delta.second = (int)((float)(New.second - Prev.second) / Render::Renderer::Graph->scale);
		
				Render::Renderer::Graph->set_centreX((float) delta.first);
				Render::Renderer::Graph->set_centreY((float) delta.second);

				LeftButton = false;

				needRender = true;
			}
			break;
		};

		break;
	case WM_MOUSEWHEEL:
		{
			if (GET_WHEEL_DELTA_WPARAM(wParam) > 0)
				Render::Renderer::Graph->set_width(-2);
			else if (GET_WHEEL_DELTA_WPARAM(wParam) < 0)
				Render::Renderer::Graph->set_width(2);
			needRender = true;
		}
		break;
	case WM_CREATE:
		D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, D2D1_FACTORY_OPTIONS(), &d2dFactory);
		RECT rect;
		GetClientRect(hWnd, &rect);
		d2dFactory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(),
			D2D1::HwndRenderTargetProperties(hWnd, D2D1::SizeU(rect.right - rect.left, rect.bottom - rect.top)), &d2dRenderTarget);
		d2dRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Black), &d2dBrush_axis);
		d2dRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Gray), &d2dBrush_reticulum);
		d2dRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Black), &d2dBrush_default);
		d2dRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Black), &d2dBrush_line);
		d2dRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Black), &d2dBrush_simple);
		d2dRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Black), &d2dBrush_Asymptotes);
		d2dRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::White, 0.5f), &d2dBrush_rect);

		DWriteCreateFactory(
			DWRITE_FACTORY_TYPE_SHARED,
			__uuidof(m_pDWriteFactory),
			reinterpret_cast<IUnknown **>(&m_pDWriteFactory)
			);

		m_pDWriteFactory->CreateTextFormat(
			L"Verdana",
			NULL,
			DWRITE_FONT_WEIGHT_NORMAL,
			DWRITE_FONT_STYLE_NORMAL,
			DWRITE_FONT_STRETCH_NORMAL,
			10.0f,
			L"", //locale
			&m_pTextFormat
			);


		//outputSize = make_pair((int) Renderer::Graph->window_width, (int) Renderer::Graph->window_height);
		//outputBitmap = (uint32*) malloc(sizeof(uint32) * outputSize.first * outputSize.second);

		Renderer::CreateStrokeStyleObject();

		//Renderer::Render();

		break;
	case WM_SIZE:
		{
			Render::WindowWidth = (float)LOWORD(lParam) + 14.0f;
			Render::WindowHeight = (float) HIWORD(lParam) + 39.0f;

			RECT rc;
			GetClientRect(hWnd, &rc);
			D2D1_SIZE_U size = D2D1::SizeU(rc.right, rc.bottom);
			d2dRenderTarget->Resize(size);
			Render::Renderer::Graph->DefaultSettings();			
			InvalidateRect(hWnd, NULL, FALSE);

			
			// ------------------INIT BITMAP------------------ //

			free(outputBitmap);
			outputSize = make_pair((int) Renderer::Graph->window_width, (int) Renderer::Graph->window_height);
			d2dRenderTarget->CreateBitmap(D2D1::SizeU(outputSize.first, outputSize.second), D2D1::BitmapProperties(D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_PREMULTIPLIED)), &d2dBitmap);
			outputBitmap = (uint32*) malloc(sizeof(uint32) * outputSize.first * outputSize.second);
			//realloc(outputBitmap, sizeof(uint32) * outputSize.first * outputSize.second);

			// ------------------INIT BITMAP------------------ //

		}
		break;
	case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
			needRender = true;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	if (needRender)
	{
		//SetEvent(Render::hEventRender);
		Renderer::Render();
	}

	return 0;
}