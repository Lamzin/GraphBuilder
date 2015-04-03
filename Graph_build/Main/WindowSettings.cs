using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Main
{
    public partial class WindowSettings : Form
    {
        public WindowSettings()
        {
            InitializeComponent();
            
            textBoxWindowsWidth.Text = WindowSettingsClass.WindowWidth.ToString();
            textBoxWindowsHeight.Text = WindowSettingsClass.WindowHeight.ToString();
           
        }

        private void Height_Click(object sender, EventArgs e)
        {

        }

        private void textBoxWindowsHeight_TextChanged(object sender, EventArgs e)
        {

        }

        private void WindowSettings_Load(object sender, EventArgs e)
        {

        }

        private void textBoxWindowsWidth_TextChanged(object sender, EventArgs e)
        {

        }

        private void buttonApply_Click(object sender, EventArgs e)
        {
            bool bwidth = true, bheight = true;
            for (int i = 0; i < textBoxWindowsWidth.Text.Length; i++)
            {
                if (textBoxWindowsWidth.Text[i] < 48 || textBoxWindowsWidth.Text[i] > 58) bwidth = false;
            }
            for (int i = 0; i < textBoxWindowsHeight.Text.Length; i++)
            {
                if (textBoxWindowsHeight.Text[i] < 48 || textBoxWindowsHeight.Text[i] > 58) bheight = false;
            }
            if (bwidth == true) WindowSettingsClass.WindowWidth = Convert.ToSingle(textBoxWindowsWidth.Text);
            if (bheight == true) WindowSettingsClass.WindowHeight = Convert.ToSingle(textBoxWindowsHeight.Text);

            this.Hide();
        }
    }
}
