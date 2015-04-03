#include "header.h"
#include "Render.h"

using namespace Render;

D2D1::ColorF Renderer::FuncColor(int count, float opacity)
{
	switch (count)
	{
	case 0:
		return D2D1::ColorF(D2D1::ColorF::DarkRed, opacity);
		break;
	case 1:
		return D2D1::ColorF(D2D1::ColorF::DarkBlue, opacity);
		break;
	case 2:
		return D2D1::ColorF(D2D1::ColorF::DarkGreen, opacity);
		break;
	case 3:
		return D2D1::ColorF(D2D1::ColorF::Indigo, opacity);
		break;
	case 4:
		return D2D1::ColorF(D2D1::ColorF::MediumVioletRed, opacity);
		break;
	case 5:
		return D2D1::ColorF(D2D1::ColorF::MidnightBlue, opacity);
		break;
	case 6:
		return D2D1::ColorF(D2D1::ColorF::Maroon, opacity);
		break;
	case 7:
		return D2D1::ColorF(D2D1::ColorF::Teal, opacity);
		break;
	case 8:
		return D2D1::ColorF(D2D1::ColorF::Aqua, opacity);
		break;
	case 9:
		return D2D1::ColorF(D2D1::ColorF::Orange, opacity);
		break;
	case 10:
		return D2D1::ColorF(D2D1::ColorF::DarkKhaki, opacity);
		break;
	case 11:
		return D2D1::ColorF(D2D1::ColorF::ForestGreen, opacity);
		break;
	default:
		return D2D1::ColorF(D2D1::ColorF::DarkRed, opacity);
	}
}

uint32 Renderer::FuncColorEquation(uint32 count, uint32 opacity)
{
	switch (count)
	{
	case -1://default backGroundColor!
		return (uint32) D2D1::ColorF::Snow + 0xff000000;
		break;
	case 0:
		return (uint32) D2D1::ColorF::DarkRed + opacity * (1 << 24);
		break;
	case 1:
		return (uint32) D2D1::ColorF::DarkBlue + opacity * (1 << 24);
		break;
	case 2:
		return (uint32) D2D1::ColorF::DarkGreen + opacity * (1 << 24);
		break;
	case 3:
		return (uint32) D2D1::ColorF::Indigo + opacity * (1 << 24);
		break;
	case 4:
		return (uint32) D2D1::ColorF::MediumVioletRed + opacity * (1 << 24);
		break;
	case 5:
		return (uint32) D2D1::ColorF::MidnightBlue + opacity * (1 << 24);
		break;
	case 6:
		return (uint32) D2D1::ColorF::Maroon + opacity * (1 << 24);
		break;
	case 7:
		return (uint32) D2D1::ColorF::Teal + opacity * (1 << 24);
		break;
	case 8:
		return (uint32) D2D1::ColorF::Aqua + opacity * (1 << 24);
		break;
	case 9:
		return (uint32) D2D1::ColorF::Orange + opacity * (1 << 24);
		break;
	case 10:
		return (uint32) D2D1::ColorF::DarkKhaki + opacity * (1 << 24);
		break;
	case 11:
		return (uint32) D2D1::ColorF::ForestGreen + opacity * (1 << 24);
		break;
	default:
		return (uint32) D2D1::ColorF::DarkRed + opacity * (1 << 24);
	}
}