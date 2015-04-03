namespace Main
{
    partial class SetGraphSettings
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
            this.LabelCentreX = new System.Windows.Forms.Label();
            this.TextBoxCentreX = new System.Windows.Forms.TextBox();
            this.TextBoxCentreY = new System.Windows.Forms.TextBox();
            this.LabelCentreY = new System.Windows.Forms.Label();
            this.TextBoxHeight = new System.Windows.Forms.TextBox();
            this.LabelHeight = new System.Windows.Forms.Label();
            this.TextBoxWidth = new System.Windows.Forms.TextBox();
            this.LabelWidth = new System.Windows.Forms.Label();
            this.TextBoxStep = new System.Windows.Forms.TextBox();
            this.LabelStep = new System.Windows.Forms.Label();
            this.TextBoxScale = new System.Windows.Forms.TextBox();
            this.LabelScale = new System.Windows.Forms.Label();
            this.ButtonSetX = new System.Windows.Forms.Button();
            this.ButtonSetY = new System.Windows.Forms.Button();
            this.ButtonSetHeight = new System.Windows.Forms.Button();
            this.ButtonSetWidth = new System.Windows.Forms.Button();
            this.ButtonSetStep = new System.Windows.Forms.Button();
            this.ButtonSetScale = new System.Windows.Forms.Button();
            this.groupBoxMainProp = new System.Windows.Forms.GroupBox();
            this.groupBoxWinProp = new System.Windows.Forms.GroupBox();
            this.textBoxWinHei = new System.Windows.Forms.TextBox();
            this.textBoxWinWid = new System.Windows.Forms.TextBox();
            this.labelWinHei = new System.Windows.Forms.Label();
            this.labelWinWid = new System.Windows.Forms.Label();
            this.labelHyperModeKoef = new System.Windows.Forms.Label();
            this.textBoxHyperKoef = new System.Windows.Forms.TextBox();
            this.ButtonSetHyperKoef = new System.Windows.Forms.Button();
            this.groupBoxMainProp.SuspendLayout();
            this.groupBoxWinProp.SuspendLayout();
            this.SuspendLayout();
            // 
            // LabelCentreX
            // 
            this.LabelCentreX.AutoSize = true;
            this.LabelCentreX.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LabelCentreX.Location = new System.Drawing.Point(10, 20);
            this.LabelCentreX.Name = "LabelCentreX";
            this.LabelCentreX.Size = new System.Drawing.Size(64, 15);
            this.LabelCentreX.TabIndex = 0;
            this.LabelCentreX.Text = "Centre X =";
            this.LabelCentreX.Click += new System.EventHandler(this.LabelCentreX_Click);
            // 
            // TextBoxCentreX
            // 
            this.TextBoxCentreX.Location = new System.Drawing.Point(80, 19);
            this.TextBoxCentreX.Name = "TextBoxCentreX";
            this.TextBoxCentreX.Size = new System.Drawing.Size(58, 20);
            this.TextBoxCentreX.TabIndex = 1;
            this.TextBoxCentreX.TextChanged += new System.EventHandler(this.TextBoxCentreX_TextChanged);
            // 
            // TextBoxCentreY
            // 
            this.TextBoxCentreY.Location = new System.Drawing.Point(80, 47);
            this.TextBoxCentreY.Name = "TextBoxCentreY";
            this.TextBoxCentreY.Size = new System.Drawing.Size(58, 20);
            this.TextBoxCentreY.TabIndex = 3;
            this.TextBoxCentreY.TextChanged += new System.EventHandler(this.TextBoxCentreY_TextChanged);
            // 
            // LabelCentreY
            // 
            this.LabelCentreY.AutoSize = true;
            this.LabelCentreY.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LabelCentreY.Location = new System.Drawing.Point(10, 48);
            this.LabelCentreY.Name = "LabelCentreY";
            this.LabelCentreY.Size = new System.Drawing.Size(63, 15);
            this.LabelCentreY.TabIndex = 2;
            this.LabelCentreY.Text = "Centre Y =";
            // 
            // TextBoxHeight
            // 
            this.TextBoxHeight.Location = new System.Drawing.Point(80, 100);
            this.TextBoxHeight.Name = "TextBoxHeight";
            this.TextBoxHeight.Size = new System.Drawing.Size(58, 20);
            this.TextBoxHeight.TabIndex = 7;
            this.TextBoxHeight.TextChanged += new System.EventHandler(this.TextBoxHeight_TextChanged);
            // 
            // LabelHeight
            // 
            this.LabelHeight.AutoSize = true;
            this.LabelHeight.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LabelHeight.Location = new System.Drawing.Point(10, 101);
            this.LabelHeight.Name = "LabelHeight";
            this.LabelHeight.Size = new System.Drawing.Size(53, 15);
            this.LabelHeight.TabIndex = 6;
            this.LabelHeight.Text = "Height =";
            // 
            // TextBoxWidth
            // 
            this.TextBoxWidth.Location = new System.Drawing.Point(80, 73);
            this.TextBoxWidth.Name = "TextBoxWidth";
            this.TextBoxWidth.Size = new System.Drawing.Size(58, 20);
            this.TextBoxWidth.TabIndex = 5;
            this.TextBoxWidth.TextChanged += new System.EventHandler(this.TextBoxWidth_TextChanged);
            // 
            // LabelWidth
            // 
            this.LabelWidth.AutoSize = true;
            this.LabelWidth.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LabelWidth.Location = new System.Drawing.Point(10, 74);
            this.LabelWidth.Name = "LabelWidth";
            this.LabelWidth.Size = new System.Drawing.Size(48, 15);
            this.LabelWidth.TabIndex = 4;
            this.LabelWidth.Text = "Width =";
            // 
            // TextBoxStep
            // 
            this.TextBoxStep.Location = new System.Drawing.Point(80, 156);
            this.TextBoxStep.Name = "TextBoxStep";
            this.TextBoxStep.Size = new System.Drawing.Size(58, 20);
            this.TextBoxStep.TabIndex = 11;
            this.TextBoxStep.TextChanged += new System.EventHandler(this.TextBoxStep_TextChanged);
            // 
            // LabelStep
            // 
            this.LabelStep.AutoSize = true;
            this.LabelStep.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LabelStep.Location = new System.Drawing.Point(10, 157);
            this.LabelStep.Name = "LabelStep";
            this.LabelStep.Size = new System.Drawing.Size(45, 15);
            this.LabelStep.TabIndex = 10;
            this.LabelStep.Text = "Step = ";
            // 
            // TextBoxScale
            // 
            this.TextBoxScale.Location = new System.Drawing.Point(80, 128);
            this.TextBoxScale.Name = "TextBoxScale";
            this.TextBoxScale.Size = new System.Drawing.Size(58, 20);
            this.TextBoxScale.TabIndex = 9;
            this.TextBoxScale.TextChanged += new System.EventHandler(this.TextBoxScale_TextChanged);
            // 
            // LabelScale
            // 
            this.LabelScale.AutoSize = true;
            this.LabelScale.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LabelScale.Location = new System.Drawing.Point(10, 129);
            this.LabelScale.Name = "LabelScale";
            this.LabelScale.Size = new System.Drawing.Size(51, 15);
            this.LabelScale.TabIndex = 8;
            this.LabelScale.Text = "Scale = ";
            // 
            // ButtonSetX
            // 
            this.ButtonSetX.Location = new System.Drawing.Point(144, 17);
            this.ButtonSetX.Name = "ButtonSetX";
            this.ButtonSetX.Size = new System.Drawing.Size(43, 23);
            this.ButtonSetX.TabIndex = 12;
            this.ButtonSetX.Text = "Set";
            this.ButtonSetX.UseVisualStyleBackColor = true;
            this.ButtonSetX.Click += new System.EventHandler(this.ButtonSetX_Click);
            // 
            // ButtonSetY
            // 
            this.ButtonSetY.Location = new System.Drawing.Point(144, 45);
            this.ButtonSetY.Name = "ButtonSetY";
            this.ButtonSetY.Size = new System.Drawing.Size(43, 23);
            this.ButtonSetY.TabIndex = 13;
            this.ButtonSetY.Text = "Set";
            this.ButtonSetY.UseVisualStyleBackColor = true;
            this.ButtonSetY.Click += new System.EventHandler(this.ButtonSetY_Click);
            // 
            // ButtonSetHeight
            // 
            this.ButtonSetHeight.Location = new System.Drawing.Point(144, 98);
            this.ButtonSetHeight.Name = "ButtonSetHeight";
            this.ButtonSetHeight.Size = new System.Drawing.Size(43, 23);
            this.ButtonSetHeight.TabIndex = 15;
            this.ButtonSetHeight.Text = "Set";
            this.ButtonSetHeight.UseVisualStyleBackColor = true;
            this.ButtonSetHeight.Click += new System.EventHandler(this.ButtonSetHeight_Click);
            // 
            // ButtonSetWidth
            // 
            this.ButtonSetWidth.Location = new System.Drawing.Point(144, 70);
            this.ButtonSetWidth.Name = "ButtonSetWidth";
            this.ButtonSetWidth.Size = new System.Drawing.Size(43, 23);
            this.ButtonSetWidth.TabIndex = 14;
            this.ButtonSetWidth.Text = "Set";
            this.ButtonSetWidth.UseVisualStyleBackColor = true;
            this.ButtonSetWidth.Click += new System.EventHandler(this.ButtonSetWidth_Click);
            // 
            // ButtonSetStep
            // 
            this.ButtonSetStep.Location = new System.Drawing.Point(144, 154);
            this.ButtonSetStep.Name = "ButtonSetStep";
            this.ButtonSetStep.Size = new System.Drawing.Size(43, 23);
            this.ButtonSetStep.TabIndex = 17;
            this.ButtonSetStep.Text = "Set";
            this.ButtonSetStep.UseVisualStyleBackColor = true;
            this.ButtonSetStep.Click += new System.EventHandler(this.ButtonSetStep_Click);
            // 
            // ButtonSetScale
            // 
            this.ButtonSetScale.Location = new System.Drawing.Point(144, 126);
            this.ButtonSetScale.Name = "ButtonSetScale";
            this.ButtonSetScale.Size = new System.Drawing.Size(43, 23);
            this.ButtonSetScale.TabIndex = 16;
            this.ButtonSetScale.Text = "Set";
            this.ButtonSetScale.UseVisualStyleBackColor = true;
            this.ButtonSetScale.Click += new System.EventHandler(this.ButtonSetScale_Click);
            // 
            // groupBoxMainProp
            // 
            this.groupBoxMainProp.Controls.Add(this.ButtonSetHyperKoef);
            this.groupBoxMainProp.Controls.Add(this.textBoxHyperKoef);
            this.groupBoxMainProp.Controls.Add(this.labelHyperModeKoef);
            this.groupBoxMainProp.Controls.Add(this.TextBoxCentreX);
            this.groupBoxMainProp.Controls.Add(this.ButtonSetStep);
            this.groupBoxMainProp.Controls.Add(this.LabelCentreX);
            this.groupBoxMainProp.Controls.Add(this.ButtonSetScale);
            this.groupBoxMainProp.Controls.Add(this.LabelCentreY);
            this.groupBoxMainProp.Controls.Add(this.ButtonSetHeight);
            this.groupBoxMainProp.Controls.Add(this.TextBoxCentreY);
            this.groupBoxMainProp.Controls.Add(this.ButtonSetWidth);
            this.groupBoxMainProp.Controls.Add(this.LabelWidth);
            this.groupBoxMainProp.Controls.Add(this.ButtonSetY);
            this.groupBoxMainProp.Controls.Add(this.TextBoxWidth);
            this.groupBoxMainProp.Controls.Add(this.ButtonSetX);
            this.groupBoxMainProp.Controls.Add(this.LabelHeight);
            this.groupBoxMainProp.Controls.Add(this.TextBoxStep);
            this.groupBoxMainProp.Controls.Add(this.TextBoxHeight);
            this.groupBoxMainProp.Controls.Add(this.LabelStep);
            this.groupBoxMainProp.Controls.Add(this.LabelScale);
            this.groupBoxMainProp.Controls.Add(this.TextBoxScale);
            this.groupBoxMainProp.Location = new System.Drawing.Point(12, 12);
            this.groupBoxMainProp.Name = "groupBoxMainProp";
            this.groupBoxMainProp.Size = new System.Drawing.Size(205, 220);
            this.groupBoxMainProp.TabIndex = 18;
            this.groupBoxMainProp.TabStop = false;
            this.groupBoxMainProp.Text = "Main Properties";
            // 
            // groupBoxWinProp
            // 
            this.groupBoxWinProp.Controls.Add(this.textBoxWinHei);
            this.groupBoxWinProp.Controls.Add(this.textBoxWinWid);
            this.groupBoxWinProp.Controls.Add(this.labelWinHei);
            this.groupBoxWinProp.Controls.Add(this.labelWinWid);
            this.groupBoxWinProp.Location = new System.Drawing.Point(11, 238);
            this.groupBoxWinProp.Name = "groupBoxWinProp";
            this.groupBoxWinProp.Size = new System.Drawing.Size(204, 76);
            this.groupBoxWinProp.TabIndex = 19;
            this.groupBoxWinProp.TabStop = false;
            this.groupBoxWinProp.Text = "Window Properties";
            // 
            // textBoxWinHei
            // 
            this.textBoxWinHei.Location = new System.Drawing.Point(79, 47);
            this.textBoxWinHei.Name = "textBoxWinHei";
            this.textBoxWinHei.Size = new System.Drawing.Size(58, 20);
            this.textBoxWinHei.TabIndex = 3;
            // 
            // textBoxWinWid
            // 
            this.textBoxWinWid.Location = new System.Drawing.Point(79, 20);
            this.textBoxWinWid.Name = "textBoxWinWid";
            this.textBoxWinWid.Size = new System.Drawing.Size(58, 20);
            this.textBoxWinWid.TabIndex = 2;
            // 
            // labelWinHei
            // 
            this.labelWinHei.AutoSize = true;
            this.labelWinHei.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelWinHei.Location = new System.Drawing.Point(12, 47);
            this.labelWinHei.Name = "labelWinHei";
            this.labelWinHei.Size = new System.Drawing.Size(53, 15);
            this.labelWinHei.TabIndex = 1;
            this.labelWinHei.Text = "Height =";
            // 
            // labelWinWid
            // 
            this.labelWinWid.AutoSize = true;
            this.labelWinWid.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelWinWid.Location = new System.Drawing.Point(12, 20);
            this.labelWinWid.Name = "labelWinWid";
            this.labelWinWid.Size = new System.Drawing.Size(48, 15);
            this.labelWinWid.TabIndex = 0;
            this.labelWinWid.Text = "Width =";
            // 
            // labelHyperModeKoef
            // 
            this.labelHyperModeKoef.AutoSize = true;
            this.labelHyperModeKoef.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelHyperModeKoef.Location = new System.Drawing.Point(11, 184);
            this.labelHyperModeKoef.Name = "labelHyperModeKoef";
            this.labelHyperModeKoef.Size = new System.Drawing.Size(68, 15);
            this.labelHyperModeKoef.TabIndex = 18;
            this.labelHyperModeKoef.Text = "Precision =";
            // 
            // textBoxHyperKoef
            // 
            this.textBoxHyperKoef.Location = new System.Drawing.Point(80, 183);
            this.textBoxHyperKoef.Name = "textBoxHyperKoef";
            this.textBoxHyperKoef.Size = new System.Drawing.Size(58, 20);
            this.textBoxHyperKoef.TabIndex = 19;
            this.textBoxHyperKoef.TextChanged += new System.EventHandler(this.textBoxHyperKoef_TextChanged);
            // 
            // ButtonSetHyperKoef
            // 
            this.ButtonSetHyperKoef.Location = new System.Drawing.Point(144, 181);
            this.ButtonSetHyperKoef.Name = "ButtonSetHyperKoef";
            this.ButtonSetHyperKoef.Size = new System.Drawing.Size(43, 23);
            this.ButtonSetHyperKoef.TabIndex = 20;
            this.ButtonSetHyperKoef.Text = "Set";
            this.ButtonSetHyperKoef.UseVisualStyleBackColor = true;
            this.ButtonSetHyperKoef.Click += new System.EventHandler(this.ButtonSetHyperKoef_Click);
            // 
            // SetGraphSettings
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(227, 324);
            this.Controls.Add(this.groupBoxWinProp);
            this.Controls.Add(this.groupBoxMainProp);
            this.Name = "SetGraphSettings";
            this.Text = "Settings";
            this.TopMost = true;
            this.Load += new System.EventHandler(this.SetGraphSettings_Load);
            this.groupBoxMainProp.ResumeLayout(false);
            this.groupBoxMainProp.PerformLayout();
            this.groupBoxWinProp.ResumeLayout(false);
            this.groupBoxWinProp.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Label LabelCentreX;
        private System.Windows.Forms.TextBox TextBoxCentreX;
        private System.Windows.Forms.TextBox TextBoxCentreY;
        private System.Windows.Forms.Label LabelCentreY;
        private System.Windows.Forms.TextBox TextBoxHeight;
        private System.Windows.Forms.Label LabelHeight;
        private System.Windows.Forms.TextBox TextBoxWidth;
        private System.Windows.Forms.Label LabelWidth;
        private System.Windows.Forms.TextBox TextBoxStep;
        private System.Windows.Forms.Label LabelStep;
        private System.Windows.Forms.TextBox TextBoxScale;
        private System.Windows.Forms.Label LabelScale;
        private System.Windows.Forms.Button ButtonSetX;
        private System.Windows.Forms.Button ButtonSetY;
        private System.Windows.Forms.Button ButtonSetHeight;
        private System.Windows.Forms.Button ButtonSetWidth;
        private System.Windows.Forms.Button ButtonSetStep;
        private System.Windows.Forms.Button ButtonSetScale;
        private System.Windows.Forms.GroupBox groupBoxMainProp;
        private System.Windows.Forms.GroupBox groupBoxWinProp;
        private System.Windows.Forms.TextBox textBoxWinHei;
        private System.Windows.Forms.TextBox textBoxWinWid;
        private System.Windows.Forms.Label labelWinHei;
        private System.Windows.Forms.Label labelWinWid;
        private System.Windows.Forms.TextBox textBoxHyperKoef;
        private System.Windows.Forms.Label labelHyperModeKoef;
        private System.Windows.Forms.Button ButtonSetHyperKoef;
    }
}