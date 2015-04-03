namespace Main
{
    partial class SetEmptyPoint
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBoxColor = new System.Windows.Forms.GroupBox();
            this.comboBox2 = new System.Windows.Forms.ComboBox();
            this.groupBoxEmpty = new System.Windows.Forms.GroupBox();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.buttonApply = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.groupBoxColor.SuspendLayout();
            this.groupBoxEmpty.SuspendLayout();
            this.SuspendLayout();
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.Items.AddRange(new object[] {
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8",
            "9",
            "10",
            "11",
            "12",
            "13",
            "14",
            "15",
            "16",
            "17",
            "18",
            "19",
            "20",
            "21",
            "22",
            "23",
            "24",
            "25",
            "26",
            "27",
            "28",
            "29",
            "30",
            "31",
            "32"});
            this.listBox1.Location = new System.Drawing.Point(6, 19);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(70, 160);
            this.listBox1.TabIndex = 0;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.listBox1);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(109, 196);
            this.groupBox1.TabIndex = 2;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Function number";
            // 
            // groupBoxColor
            // 
            this.groupBoxColor.Controls.Add(this.comboBox2);
            this.groupBoxColor.Location = new System.Drawing.Point(128, 13);
            this.groupBoxColor.Name = "groupBoxColor";
            this.groupBoxColor.Size = new System.Drawing.Size(150, 48);
            this.groupBoxColor.TabIndex = 3;
            this.groupBoxColor.TabStop = false;
            this.groupBoxColor.Text = "Color";
            // 
            // comboBox2
            // 
            this.comboBox2.FormattingEnabled = true;
            this.comboBox2.Items.AddRange(new object[] {
            "Black ",
            "Blue ",
            "Brown ",
            "Chocolate ",
            "DarkBlue ",
            "DarkGoldenrod",
            "DarkGray",
            "DarkGreen ",
            "DarkOrange",
            "DarkRed ",
            "Gold",
            "Goldenrod ",
            "Gray",
            "Green",
            "GreenYellow ",
            "Honeydew ",
            "HotPink ",
            "LimeGreen ",
            "Orange ",
            "Purple ",
            "Red ",
            "Silver ",
            "SkyBlue",
            "Snow ",
            "Tomato ",
            "White ",
            "Yellow "});
            this.comboBox2.Location = new System.Drawing.Point(7, 18);
            this.comboBox2.Name = "comboBox2";
            this.comboBox2.Size = new System.Drawing.Size(121, 21);
            this.comboBox2.TabIndex = 0;
            // 
            // groupBoxEmpty
            // 
            this.groupBoxEmpty.Controls.Add(this.comboBox1);
            this.groupBoxEmpty.Location = new System.Drawing.Point(128, 68);
            this.groupBoxEmpty.Name = "groupBoxEmpty";
            this.groupBoxEmpty.Size = new System.Drawing.Size(150, 53);
            this.groupBoxEmpty.TabIndex = 4;
            this.groupBoxEmpty.TabStop = false;
            this.groupBoxEmpty.Text = "Empty Point";
            // 
            // comboBox1
            // 
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Items.AddRange(new object[] {
            "Up",
            "Down",
            "Only first(defalut)",
            "Only second"});
            this.comboBox1.Location = new System.Drawing.Point(7, 20);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(121, 21);
            this.comboBox1.TabIndex = 0;
            // 
            // buttonApply
            // 
            this.buttonApply.Location = new System.Drawing.Point(203, 168);
            this.buttonApply.Name = "buttonApply";
            this.buttonApply.Size = new System.Drawing.Size(75, 23);
            this.buttonApply.TabIndex = 5;
            this.buttonApply.Text = "Apply";
            this.buttonApply.UseVisualStyleBackColor = true;
            // 
            // SetEmptyPoint
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(297, 218);
            this.Controls.Add(this.buttonApply);
            this.Controls.Add(this.groupBoxEmpty);
            this.Controls.Add(this.groupBoxColor);
            this.Controls.Add(this.groupBox1);
            this.Name = "SetEmptyPoint";
            this.Text = "SetEmptyPoint";
            this.groupBox1.ResumeLayout(false);
            this.groupBoxColor.ResumeLayout(false);
            this.groupBoxEmpty.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBoxColor;
        private System.Windows.Forms.ComboBox comboBox2;
        private System.Windows.Forms.GroupBox groupBoxEmpty;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.Button buttonApply;










    }
}