using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using Render;
using MyEvent;
using GraphProp;

namespace Main
{
    public partial class MainForm : Form
    {
        //public SetGraphSettings SetForm = new SetGraphSettings();
        public MainForm()
        {
            InitializeComponent();
            textBox1.ScrollBars = ScrollBars.Vertical;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void ButtonBuild_Click(object sender, EventArgs e)
        {
            String tmp = textBox1.Text;

            while (tmp.IndexOf('\n') >= 0) tmp = tmp.Remove(tmp.IndexOf('\n'), 1);
            while (tmp.IndexOf('\r') >= 0) tmp = tmp.Remove(tmp.IndexOf('\r'), 1);

            Renderer.SetString(tmp);
            Renderer.RenderWindow(WindowSettingsClass.WindowWidth, WindowSettingsClass.WindowHeight, 5);
        }

        private void letsBuildToolStripMenuItem_Click(object sender, EventArgs e)
        {            
            String tmp = textBox1.Text;

            while (tmp.IndexOf('\n') >= 0) tmp = tmp.Remove(tmp.IndexOf('\n'), 1);
            while (tmp.IndexOf('\r') >= 0) tmp = tmp.Remove(tmp.IndexOf('\r'), 1);

            Renderer.SetString(tmp);
            Renderer.RenderWindow(WindowSettingsClass.WindowWidth, WindowSettingsClass.WindowHeight, 5);
        }

        private void graphToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SetGraphSettings SetForm = new SetGraphSettings();
            Renderer.Graph.EventChangeSettings.AddEvent(new MyEventHandler(SetForm.ShowSettings));
            SetForm.Show();
        }

        private void windowToolStripMenuItem_Click(object sender, EventArgs e)
        {
            WindowSettings WinSetForm = new WindowSettings();
            WinSetForm.Show();
        }

        private void menuStrip_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {
            
        }

        private void fxToolStripMenuItem_Click(object sender, EventArgs e)
        {
            String tmp = textBox1.Text;

            while (tmp.IndexOf('\n') >= 0) tmp = tmp.Remove(tmp.IndexOf('\n'), 1);
            while (tmp.IndexOf('\r') >= 0) tmp = tmp.Remove(tmp.IndexOf('\r'), 1);

            Renderer.SetString(tmp);
            Renderer.RenderWindow(WindowSettingsClass.WindowWidth, WindowSettingsClass.WindowHeight, 1);
        }

        private void fxToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            String tmp = textBox1.Text;

            while (tmp.IndexOf('\n') >= 0) tmp = tmp.Remove(tmp.IndexOf('\n'), 1);
            while (tmp.IndexOf('\r') >= 0) tmp = tmp.Remove(tmp.IndexOf('\r'), 1);

            Renderer.SetString(tmp);
            Renderer.RenderWindow(WindowSettingsClass.WindowWidth, WindowSettingsClass.WindowHeight, 3);
        }

        private void fxToolStripMenuItem2_Click(object sender, EventArgs e)
        {
            String tmp = textBox1.Text;

            while (tmp.IndexOf('\n') >= 0) tmp = tmp.Remove(tmp.IndexOf('\n'), 1);
            while (tmp.IndexOf('\r') >= 0) tmp = tmp.Remove(tmp.IndexOf('\r'), 1);

            Renderer.SetString(tmp);
            Renderer.RenderWindow(WindowSettingsClass.WindowWidth, WindowSettingsClass.WindowHeight, 2);
        }

        private void fxToolStripMenuItem3_Click(object sender, EventArgs e)
        {
            String tmp = textBox1.Text;

            while (tmp.IndexOf('\n') >= 0) tmp = tmp.Remove(tmp.IndexOf('\n'), 1);
            while (tmp.IndexOf('\r') >= 0) tmp = tmp.Remove(tmp.IndexOf('\r'), 1);

            Renderer.SetString(tmp);
            Renderer.RenderWindow(WindowSettingsClass.WindowWidth, WindowSettingsClass.WindowHeight, 4);
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("http://vk.com/id229278257");
        }

        private void emptyPointsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SetEmptyPoint SetEmpPointObj = new SetEmptyPoint();
            SetEmpPointObj.Show();
        }

        private void helpToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            Help HelpObject = new Help();

            HelpObject.Show();
        }
    }
}
