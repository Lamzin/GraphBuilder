using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

using Render;
using MyEvent;
using GraphProp;

namespace Main
{
    static class Program
    {
        /// <summary>
        /// Главная точка входа для приложения.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

            //Renderer.Graph.EventChangeSettings.Event += SetGraphSettings.ShowSettings;
            Renderer.Initialize();

            MainForm MainMainMain = new MainForm();

            //Renderer.Graph.EventChangeSettings.AddEvent(new MyEventHandler(MainMainMain.SetForm.ShowSettings));

            //Application.Run(new MainForm());
            Application.Run(MainMainMain);

        }
    }
    public class WindowSettingsClass
    {
        static public float WindowWidth = 1000.0f, WindowHeight = 600.0f;
    };
}
