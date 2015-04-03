#include "GraphProperties.h"

GraphProperties::GraphProperties()
	{
		window_width = 800.0f;
		window_height = 800.0f;

		width = 20.0f;
		scale = window_width / width;
		height = window_height / scale;
		//step = 0.001f;
		step = (width / window_width)/4;
		//

		centreX = (double)((long int)(width / 2));
		centreY = (double)((long int)(height / 2));
		left = -1 * width / 2;
		right = width / 2;
		up = -1 * height / 2;
		down = height / 2;
	}

void  GraphProperties::set_width(double tmp)
{
	tmp *= 2;
	if (width + tmp > 0)
	{
		width += tmp;
		scale = window_width / width;
		height = window_height / scale;
		//
		step = (width / window_width)/4;
		//
			
		centreX = (double)((long int)(width / 2));
		centreY = (double)((long int)(height / 2));
		left = -1 * width / 2;
		right = width / 2;
		up = -1 * height / 2;
		down = height / 2;	
	}
};


void GraphProperties::set_centreX(int tmp)
	{
		left -=tmp * (width / 20);
		right -=tmp * (width / 20);
		centreX += tmp * (width / 20);
	}

void GraphProperties::set_centreY(int tmp)
	{
		up -=tmp * (width / 20);
		down -=tmp * (width / 20);
		centreY += tmp * (width / 20);
	}