using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Render;

namespace MyLibrary
{
    public class SetProperties
    {
        public static void SetHyperKoef(float param)
        {
            Renderer.Graph.HyperModeKoef = param;
        }
    }
}
