#pragma once

#include "header.h"

using namespace std;

namespace Render
{

	class Rectangles
	{
	public:
		pair <float, float> x;
		int colorNumb;

		Rectangles(float xfi, float xse, int colnumb)
		{
			x.first = xfi;
			x.second = xse;
			colorNumb = colnumb;
		}
	};
	
	extern vector <Rectangles> RectVect;

}