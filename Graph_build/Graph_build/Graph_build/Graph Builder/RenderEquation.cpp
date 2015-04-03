#include "header.h"
#include "MathFunction.h"
#include "GraphProperties.h"
#include "Render.h"
#include "Function.h"

using namespace std;
using namespace Render;

inline bool CheckFuncLess(float a, float b) { return a < b; }
inline bool CheckFuncLessOrEqual(float a, float b) { return a <= b; }
inline bool CheckFuncMore(float a, float b) { return a > b; }
inline bool CheckFuncMoreOrEqual(float a, float b) { return a >= b; }
inline bool CheckFuncEqual(float a, float b) { return a == b; }

void Renderer::RenderEquation(int function_number)
{
	/*ID2D1Bitmap *d2dBitmap;
	pair <int, int> outputSize = make_pair((int) Graph->window_width, (int) Graph->window_height);
	d2dRenderTarget->CreateBitmap(D2D1::SizeU(outputSize.first, outputSize.second), D2D1::BitmapProperties(D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_PREMULTIPLIED)), &d2dBitmap);
	uint32* outputBitmap = (uint32*) malloc(sizeof(uint32) * outputSize.first * outputSize.second);*/

	uint32 ColorBackGround = FuncColorEquation(-1, 128), ColorEquation = FuncColorEquation(function_number, 64);

	bool(*check)(float a, float b);

	switch (Function::MyFuncArray[function_number]->OperatorType)
	{
	case Less: check = CheckFuncLess; break;
	case LessOrEqual: check = CheckFuncLessOrEqual; break;
	case More: check = CheckFuncMore; break;
	case MoreOrEqual: check = CheckFuncMoreOrEqual; break;
	case Equal: check = CheckFuncEqual; break;
	}

	float a, b, tmpRadius = 1.0f, xDecartes, yDecartes;
	int PIXEL_STEP = 1;
	uint32 WIND_HEI = (uint32) Graph->window_height, WIND_WID = (uint32) Graph->window_width;

	for (uint32 y = 0; y < WIND_HEI; y++)
	{
		yDecartes = -(float) y / Graph->scale + Graph->centreY;

		for (uint32 x = 0; x < WIND_WID; x++)
		{
			xDecartes = (float) x / Graph->scale - Graph->centreX;

			a = Function::MyFuncArray[function_number]->Value(xDecartes, yDecartes);
			b = Function::MyFuncArray[function_number + 1]->Value(xDecartes, yDecartes);

			if (check(a, b))
			{
				//d2dRenderTarget->FillEllipse(D2D1::Ellipse(D2D1::Point2F((float) x, (float) y), tmpRadius, tmpRadius), d2dBrush_default);
				Render::outputBitmap[x + y * Render::outputSize.first] = ColorEquation;
			}
			//else Render::outputBitmap[x + y * Render::outputSize.first] = ColorBackGround;
		}
	}

	d2dBitmap->CopyFromMemory(&D2D1::RectU(0, 0, Render::outputSize.first, Render::outputSize.second), Render::outputBitmap, Render::outputSize.first * 4);
	d2dRenderTarget->DrawBitmap(Render::d2dBitmap, D2D1::RectF(0, 0, Render::outputSize.first, Render::outputSize.second));
}


	/*if (yDecartes > xDecartes*xDecartes)
	{
	d2dRenderTarget->FillEllipse(D2D1::Ellipse(D2D1::Point2F(Graph->centreX * Graph->scale + x * Graph->scale, Graph->centreY * Graph->scale - y * Graph->scale), tmpRadius, tmpRadius), d2dBrush_default);
	d2dRenderTarget->FillEllipse(D2D1::Ellipse(D2D1::Point2F(x, y), tmpRadius, tmpRadius), d2dBrush_default);
	}*/

	//if (abs(sin(abs(x)) + cos(abs(y))) > frac(abs(y))*frac(abs(x)))
	//if (abs(pow(sin(abs(x)),2) + pow(cos(abs(y)),2)) < frac(abs(y)) / frac(abs(x)))
	//if (abs(sin(abs(x)) + cos(abs(y)) < frac(abs(y)) + frac(abs(x)))
	//if (frac(2*y)*sin(2*x) > frac(2 * x) / sin(2 * y))
	//if (a = pow(abs(sin(x)), abs(cos(y)));b = pow(frac(x), frac(y));)
	//if (a = pow(abs(sin(x)), abs(cos(y)));b = frac(x) / frac(y);); 
	//if (a = sin(frac(x));	b = cos(inte(y)););
	//if (a = sin(frac(4 * x)); b = cos(inte(4 * y));)
	//if (a = sin(inte(2*x)*frac(2*y)); b = cos(inte(2 * y));)
	//if (a = sin(inte(2 * x)*frac(2 * y));	b = cos(inte(2 * y)*frac(2 * x)););
	//if (a = sin(inte(1 * x)*frac(1 * y)); b = cos(inte(1 * y) / frac(1 * x));)
	//if (a = sin(inte(2 * x)+frac(2 * y));	b = cos(inte(2 * y) + frac(2 * x));)

	//if (inte(x) < inte(y))
	//if (inte(x)*inte(y) < 1)
	//if (frac(x/4) + frac(y/4) < 1)
	//if (abs(frac(x / 2) - frac(y / 2)) < 0.4)
	//if (inte(x*y/4)/(x*y/4) > frac(x/2)+frac(y/2))
	//if (sin(inte(x)) > cos(inte(y)))
	//if (4*inte(0.25*abs(x*y))/abs(x*y) < frac(abs(x*y)/4))  !!!!!!
	//if (inte(x)*inte(x) + inte(y)*inte(y) < 25 && inte(x)*inte(x) + inte(y)*inte(y) > 16)
	//if (inte(x)*inte(y)*inte(x)*inte(y) - 10 * inte(y)*inte(x) + 6 < 0)
	//if (sin(frac(x)) > cos(inte(y)))
	//if (cos(frac(abs(x*y*4))) > 10*sin(inte(abs(x*y*4))))
	//if (tan(frac(x+y)) > 1/tan(frac(x*y)))
	//if (inte(abs(x)+abs(y)) > 7*frac(pow(abs(x*y),3/2)))
	//if (frac(abs(x)+abs(y))>0.5)
	//if (frac(x*x + y*y) > frac(x*x - y*y))
	//if (frac(x*x/4 + y*y/4) > 0.5)
	//if (frac(abs(x) + abs(y)) > frac(abs(x) - abs(y)))
	//if (frac(abs(x/2))+frac(abs(y/2)) > frac(x*x/4)+ frac(y*y/4))
	//if (frac(abs(x)) / inte(abs(x)) > frac(abs(y)) / inte(abs(y)))
	/*if (
	(x - 6 * inte((x + 3) / 6)) * (x - 6 * inte((x + 3) / 6)) - 4 * abs((x - 6 * inte((x + 3) / 6)))
	>
	(y - 6 * inte((y + 3) / 6)) * (y - 6 * inte((y + 3) / 6)) - 4 * abs((y - 6 * inte((y + 3) / 6)))
	)*/
	/*if (
	(x + y- 6 * inte((x + y + 3) / 6)) * (x + y - 6 * inte((x + y + 3) / 6)) - 4 * abs((x + y - 6 * inte((x + y + 3) / 6)))
	>
	(x*y - 6 * inte((x*y + 3) / 6)) * (x*y - 6 * inte((x*y + 3) / 6)) - 4 * abs((x*y - 6 * inte((x*y + 3) / 6)))
	)*/
	//if (log(abs(inte(x+y)+0.5)>frac(x*y)))
	//if (pow(frac(abs(x)+abs(y)),inte(abs(x)-abs(y))) > frac(abs(x)-abs(y)))
	//if (frac(frac(x) + frac(y)) > frac(x+y)/2 + frac(x-y)/2)
	//if (frac(x*y)*frac(x*y) + frac(x/y)*frac(x/y) < 0.49)
	//if (frac(x)*frac(x) + frac(y)*frac(y) < 0.49)
	//if (frac(x)*frac(2 * x) > (frac(y)*frac(2 * y)))
	//if (frac(x)*frac(2 * x)*frac(3 * x) > (frac(y)*frac(2 * y)*frac(3 * y)))