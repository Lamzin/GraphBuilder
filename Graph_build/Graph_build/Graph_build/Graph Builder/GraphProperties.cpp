#include "header.h"
#include "GraphProperties.h"
#include "MathFunction.h"
#include "Render.h"

using namespace GraphProp;

GraphProperties::GraphProperties()
	{
		//float tmp = 35;
		//Main::TextBoxCentreX.Text = tmp.ToString();
		EventChangeSettings = gcnew MyEvent::SomeEvent();
		DefaultSettings();
	}

void GraphProperties :: DefaultSettings()
{
	ScaleHyperMode = false;

	DeltaFunctionBuild = 1000.0f;

	//window_width = 800.0f;
	//window_height = 800.0f;
	window_width = Render::WindowWidth;
	window_height = Render::WindowHeight;

	width = 20.0f;
	scale = window_width / width;
	height = window_height / scale;
	//step = 0.001f;
	step = (width / window_width);
	//

	centreX = (float) ((long int) (width / 2));
	centreY = (float) ((long int) (height / 2));
	left = -1 * width / 2;
	right = width / 2;
	up = -1 * height / 2;
	down = height / 2;

	EventChangeSettings->EventOn();
}

void  GraphProperties::set_width(float tmp)
{
	//tmp *= 2;
	if (width + tmp > 0.0f && width + tmp < 100.0f)
	{
		width += tmp;
		scale = window_width / width;
		height = window_height / scale;
		//
		step = (width / window_width);
		//
			
		centreX = (float)((long int)(width / 2));
		centreY = (float) ((long int) (height / 2));
		left = -1 * width / 2;
		right = width / 2;
		up = -1 * height / 2;
		down = height / 2;	
	}
	EventChangeSettings->EventOn();
};

void GraphProperties::set_centreX(float tmp)
	{
		/*left -=tmp * (width / 20);
		right -=tmp * (width / 20);
		centreX += tmp * (width / 20);*/
		int justtmp = 1;
		if (width > 100.0f) justtmp = (int) MyMath::GetIntegralPart((float) width / 25);
		left -= tmp * justtmp;
		right -= tmp * justtmp;
		centreX += tmp * justtmp;

		EventChangeSettings->EventOn();
	}

void GraphProperties::set_centreY(float tmp)
	{
		/*up -=tmp * (width / 20);
		down -=tmp * (width / 20);
		centreY += tmp * (width / 20);*/
		int justtmp = 1;
		if (width > 100.0f) justtmp = (int) MyMath::GetIntegralPart((float) width / 25);
		up -= tmp * justtmp;
		down -= tmp * justtmp;
		centreY += tmp * justtmp;

		EventChangeSettings->EventOn();
	}

void GraphProperties::set_DeltaFunctionBuild(int tmp)
	{
		if (DeltaFunctionBuild + tmp >= 100.0f && DeltaFunctionBuild + tmp <= 1000000.0f)
		{
			DeltaFunctionBuild += tmp;
		}

		EventChangeSettings->EventOn();
	}


void GraphProperties::on_HyperMode()
{
	if (ScaleHyperMode == false)
	{
		ScaleHyperMode = true;
	}
}

void GraphProperties::off_HyperMode()
{
	if (ScaleHyperMode == true)
	{
		ScaleHyperMode = false;
	}
}