using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using MyLibrary;

namespace Main
{
    public partial class SetGraphSettings : Form
    {
        public SetGraphSettings()
        {
            InitializeComponent();

            ButtonHideAll();
        }

        public void ShowSettings()
        {
            TextBoxCentreX.Text = GetProperties.GetCentreX().ToString();
            TextBoxCentreY.Text = GetProperties.GetCentreY().ToString();
            TextBoxWidth.Text = GetProperties.GetWidth().ToString();
            TextBoxHeight.Text = GetProperties.GetHeight().ToString();
            TextBoxScale.Text = GetProperties.GetScale().ToString();
            TextBoxStep.Text = GetProperties.GetStep().ToString();
            textBoxWinWid.Text = GetProperties.GetWinWid().ToString();
            textBoxWinHei.Text = GetProperties.GetWinHei().ToString();
            textBoxHyperKoef.Text = GetProperties.GetHyperKoef().ToString();
        }
   
        private void LabelCentreX_Click(object sender, EventArgs e)
        {

        }

        private void SetGraphSettings_Load(object sender, EventArgs e)
        {

        }

        private void ButtonSetX_Click(object sender, EventArgs e)
        {
            ButtonHideAll();
        }

        private void ButtonSetY_Click(object sender, EventArgs e)
        {
            ButtonHideAll();
        }

        private void ButtonSetWidth_Click(object sender, EventArgs e)
        {
            ButtonHideAll();
        }

        private void ButtonSetHeight_Click(object sender, EventArgs e)
        {
            ButtonHideAll();
        }

        private void ButtonSetScale_Click(object sender, EventArgs e)
        {
            ButtonHideAll();
        }

        private void textBoxHyperKoef_TextChanged(object sender, EventArgs e)
        {
            ButtonSetHyperKoef.Show();
            //ButtonHideAll();
        }

        private void ButtonSetStep_Click(object sender, EventArgs e)
        {
            ButtonSetStep.Hide();
        }

        private void TextBoxCentreX_TextChanged(object sender, EventArgs e)
        {
            ButtonSetX.Show();
        }

        private void TextBoxCentreY_TextChanged(object sender, EventArgs e)
        {
            ButtonSetY.Show();
        }

        private void TextBoxWidth_TextChanged(object sender, EventArgs e)
        {
            ButtonSetWidth.Show();
        }

        private void TextBoxHeight_TextChanged(object sender, EventArgs e)
        {
            ButtonSetHeight.Show();
        }

        private void TextBoxScale_TextChanged(object sender, EventArgs e)
        {
            ButtonSetScale.Show();
        }

        private void TextBoxStep_TextChanged(object sender, EventArgs e)
        {
            ButtonSetStep.Show();
        }

        private void ButtonHideAll()
        {
            ButtonSetX.Hide();
            ButtonSetY.Hide();
            ButtonSetWidth.Hide();
            ButtonSetHeight.Hide();
            ButtonSetScale.Hide();
            ButtonSetStep.Hide();
            ButtonSetHyperKoef.Hide();

            //this.Hide();
        }

        private void ButtonSetHyperKoef_Click(object sender, EventArgs e)
        {
            SetProperties.SetHyperKoef(Convert.ToSingle(textBoxHyperKoef.Text));

            ButtonSetHyperKoef.Hide();
        }
    }
}
