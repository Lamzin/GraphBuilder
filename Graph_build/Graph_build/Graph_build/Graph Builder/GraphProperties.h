#pragma once

#include "header.h"
#include "Event.h"

namespace GraphProp
{
	public ref class GraphProperties
	{
	public:
		MyEvent::SomeEvent^ EventChangeSettings;

		float width, height;
		float scale, step;
		float centreX, centreY;
		float left, right, up, down;
		float window_width, window_height;
		float DeltaFunctionBuild;

		bool ScaleHyperMode = false;
		float HyperModeKoef = 16;


		GraphProperties();
		void DefaultSettings();

		void set_width(float tmp);

		void set_centreX(float tmp);

		void set_centreY(float tmp);

		void set_DeltaFunctionBuild(int tmp);

		void on_HyperMode();

		void off_HyperMode();
	};
}