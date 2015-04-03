#pragma once

using namespace std;

namespace Render
{
	enum TypeOfAnimation
	{
		None = 0,
		IntegOfFunc = 1,
		IntegOfArg = 2,
		FracOfFunc = 3,
		FracOfArg = 4,
	};

	enum TypeOfAnimationStatus
	{
		ANIMBegin,
		ANIMProcessing,
		ANIMEnd
	};

	enum TypeOfAnimationAllow
	{
		ANIMPause = 1,
		ANIMAllow = 2,
		ANIMBlock = 3
	};

	extern TypeOfAnimation AnimOnOf;

	public ref class Animation
	{
	public:

		static TypeOfAnimationStatus AnimationStatus;

		static TypeOfAnimationAllow AnimationAllow = ANIMBlock;

		static void IntegralPartOfFunction();
		
		static void FractionalPartOfFunction();
		
		static void IntegralPartOfArgument();
		
		static void FractionalPartOfArgument();
		
		static void RunDefaultAnimation(int param)
		{
			Animation::SetAnimOnOf(param);
			Animation::AnimationAllow = ANIMAllow;
			Renderer::Render();
			Animation::AnimationAllow = ANIMBlock;
		}

		static float Yanim, Xanim;

		static void SetAnimOnOf(int param)
		{
			switch (param)
			{
			case 1: 
				AnimOnOf = IntegOfFunc;
				break;
			case 2:
				AnimOnOf = IntegOfArg;
				break;
			case 3:
				AnimOnOf = FracOfFunc;
				break;
			case 4:
				AnimOnOf = FracOfArg;
				break;
			default:
				AnimOnOf = None;
				break;
			}

		};

	};

}