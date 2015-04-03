#include <string>

namespace Render
{
	static LRESULT __stdcall WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	public ref class Renderer
	{
	private:
		static void DrawLine(double xtmp1, double ytmp1, double xtmp2, double ytmp2);
		static inline void RenderDrawGraph();
		static inline void RenderDrawALLDefaultGraph();
		static inline void RenderDrawReticulum();
		static inline double inte(double tmp);
		static inline double frac(double tmp);
		static bool bDrawReticulum = true, bDrawAxis = true, bDrawGraph = true;
	public:
		static std :: string *MathExpression;
		static GraphProperties *Graph = new GraphProperties();
		static inline void Initialize();
		static inline void Render();
		static inline void RenderWindow();
		static inline void SetString(System::String ^str);
		static void SetbDrawReticulum();
		static void SetbDrawAxis();
		static void SetbDrawGraph();
	};
}