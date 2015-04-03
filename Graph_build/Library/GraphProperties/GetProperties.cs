using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Render;

namespace MyLibrary
{
    public class GetProperties
    {
        public static double GetCentreX()
        {
            return Renderer.Graph.centreX;
        }

        public static double GetCentreY()
        {
            return Renderer.Graph.centreY;
        }

        public static double GetWidth()
        {
            return Renderer.Graph.width;
        }

        public static double GetHeight()
        {
            return Renderer.Graph.height;
        }

        public static double GetScale()
        {
            return Renderer.Graph.scale;
        }

        public static double GetStep()
        {
            return Renderer.Graph.step;
        }

        public static double GetWinWid()
        {
            return Renderer.Graph.window_width;
        }

        public static double GetWinHei()
        {
            return Renderer.Graph.window_height;
        }

        public static double GetHyperKoef()
        {
            return Renderer.Graph.HyperModeKoef;
        }
    }
}
