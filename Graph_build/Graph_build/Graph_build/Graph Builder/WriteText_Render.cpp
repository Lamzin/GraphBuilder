#include "header.h"
#include "MathFunction.h"
#include "GraphProperties.h"
#include "Render.h"
#include "Function.h"

using namespace std;
using namespace Render;

void Renderer::RenderWriteScale()
{
	D2D1_SIZE_F renderTargetSize = d2dRenderTarget->GetSize();

	d2dBrush_default->SetColor(D2D1::ColorF(D2D1::ColorF::Black));
	
	float TMP_STEP = 1;

	if (Graph->width < 40) TMP_STEP = 1;
	else if (Graph->width < 100) TMP_STEP = 2;

	for (float xtmp = 0; xtmp <= Graph->width; xtmp += TMP_STEP)
	{
		wchar_t sc_string[16] = L"", wcharTmp;

		int tmp = (int)(Graph->left + xtmp), len = 0;

		if (tmp > 0)
		{
			while (tmp)
			{
				sc_string[len++] = wchar_t(tmp % 10 + 48);
				tmp /= 10;
			}
		}
		else if (tmp < 0)
		{
			tmp *= -1;
			while (tmp)
			{
				sc_string[len++] = wchar_t(tmp % 10 + 48);
				tmp /= 10;
			}
			sc_string[len++] = '-';
		}
		else sc_string[0] = wchar_t(48);

		for (int k = 0; k < len / 2; k++)
		{
			wcharTmp = sc_string[k];
			sc_string[k] = sc_string[len - k - 1];
			sc_string[len - k - 1] = wcharTmp;
		}

		float ytext = Graph->centreY * Graph->scale;
		if (ytext < 0) ytext = 0;
		else if (ytext > Graph->window_height - 50) ytext = Graph->window_height - 50;

		d2dRenderTarget->DrawText(
			sc_string,
			ARRAYSIZE(sc_string) - 1,
			m_pTextFormat,
			D2D1::RectF((Graph->left + Graph->centreX) * Graph->scale + xtmp * Graph->scale, ytext, renderTargetSize.width, renderTargetSize.height),
			d2dBrush_default
			);
	}

	for (float xtmp = 0; xtmp <= Graph->height; xtmp += TMP_STEP)
	{
		wchar_t sc_string[16] = L"", wcharTmp;

		int tmp = (int)(-1 * ((int)Graph->up + xtmp)), len = 0;

		if (tmp > 0)
		{
			while (tmp)
			{
				sc_string[len++] = wchar_t(tmp % 10 + 48);
				tmp /= 10;
			}
		}
		else if (tmp < 0)
		{
			tmp *= -1;
			while (tmp)
			{
				sc_string[len++] = wchar_t(tmp % 10 + 48);
				tmp /= 10;
			}
			sc_string[len++] = '-';
		}
		else sc_string[0] = wchar_t(48);

		for (int k = 0; k < len / 2; k++)
		{
			wcharTmp = sc_string[k];
			sc_string[k] = sc_string[len - k - 1];
			sc_string[len - k - 1] = wcharTmp;
		}

		float xtext = Graph->centreX * Graph->scale;
		if (xtext < 0) xtext = 0;
		else if (xtext > Graph->window_width - 40) xtext = Graph->window_width - 40;

		d2dRenderTarget->DrawText(
			sc_string,
			ARRAYSIZE(sc_string) - 1,
			m_pTextFormat,
			D2D1::RectF(xtext, ((int)Graph->up + Graph->centreY) * Graph->scale + xtmp * Graph->scale, renderTargetSize.width, renderTargetSize.height),
			d2dBrush_default
			);
	}

}

void Renderer::CreateStrokeStyleObject()
{
	//float dashes [] = { 1.0f, 2.0f, 2.0f, 3.0f, 2.0f, 2.0f };
	float dashes [] = { 5.0f, 5.0f };

	if (SUCCEEDED(hr))
	{
		hr = d2dFactory->CreateStrokeStyle(
			D2D1::StrokeStyleProperties(
			D2D1_CAP_STYLE_FLAT,
			D2D1_CAP_STYLE_FLAT,
			D2D1_CAP_STYLE_ROUND,
			D2D1_LINE_JOIN_MITER,
			10.0f,
			D2D1_DASH_STYLE_CUSTOM,
			0.0f),
			dashes,
			ARRAYSIZE(dashes),
			&m_pStrokeStyleCustomOffsetZero
			);
	}

	// Stroke Style with Dash Style -- Dash
	if (SUCCEEDED(hr))
	{
		hr = d2dFactory->CreateStrokeStyle(
			D2D1::StrokeStyleProperties(
			D2D1_CAP_STYLE_FLAT,
			D2D1_CAP_STYLE_FLAT,
			D2D1_CAP_STYLE_ROUND,
			D2D1_LINE_JOIN_MITER,
			10.0f,
			D2D1_DASH_STYLE_DASH,
			0.0f),
			NULL,
			0,
			&m_pStrokeStyleDash
			);
	}

	// Stroke Style with Dash Style -- Dot
	if (SUCCEEDED(hr))
	{
		hr = d2dFactory->CreateStrokeStyle(
			D2D1::StrokeStyleProperties(
			D2D1_CAP_STYLE_FLAT,
			D2D1_CAP_STYLE_FLAT,
			D2D1_CAP_STYLE_ROUND,
			D2D1_LINE_JOIN_ROUND,
			10.0f,
			D2D1_DASH_STYLE_DOT,
			0.0f),
			NULL,
			0,
			&m_pStrokeStyleDot
			);
	}

	// Stroke Style with Dash Style -- Dash Dot
	if (SUCCEEDED(hr))
	{
		hr = d2dFactory->CreateStrokeStyle(
			D2D1::StrokeStyleProperties(
			D2D1_CAP_STYLE_FLAT,
			D2D1_CAP_STYLE_FLAT,
			D2D1_CAP_STYLE_ROUND,
			D2D1_LINE_JOIN_MITER,
			10.0f,
			D2D1_DASH_STYLE_DASH_DOT,
			0.0f),
			NULL,
			0,
			&m_pStrokeStyleDashDot
			);
	}
}

void Renderer::RenderWriteTotalTime(double time)
{
	wchar_t sc_string[32] = L"Total time = ";

	long long TIME = (long long) (time * 1000), a = TIME / 1000, b = TIME % 1000, index;

	if (a > 99)
	{
		sc_string[14] = (a / 100) + 48;
		sc_string[15] = (a / 10 % 10) + 48;
		sc_string[16] = (a % 10) + 48;
		index = 17;
	}
	else if (a > 9)
	{
		sc_string[14] = (a / 10) + 48;
		sc_string[15] = (a % 10) + 48;
		index = 16;
	}
	else
	{
		sc_string[14] = a + 48;
		index = 15;
	}
	sc_string[index++] = '.';

	sc_string[index++] = (b / 100) + 48;
	sc_string[index++] = (b / 10 % 10) + 48;
	sc_string[index++] = (b % 10) + 48;

	d2dBrush_default->SetColor(D2D1::ColorF(D2D1::ColorF::Black));

	d2dRenderTarget->DrawText(
		sc_string,
		ARRAYSIZE(sc_string) - 1,
		m_pTextFormat,
		D2D1::RectF(12, 12, 300, 300),
		d2dBrush_default
		);

	d2dRenderTarget->DrawText(
		L"          by Oleh Lamzin\nolehtomas@gmail.com",
		ARRAYSIZE(L"          by Oleh Lamzin\nolehtomas@gmail.com") - 1,
		m_pTextFormat,
		D2D1::RectF(Graph->window_width - 150, Graph->window_height - 80, Graph->window_width, Graph->window_height),
		d2dBrush_default
		);
}