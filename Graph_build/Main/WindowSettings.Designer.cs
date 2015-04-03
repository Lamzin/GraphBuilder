namespace Main
{
    partial class WindowSettings
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
            this.Width = new System.Windows.Forms.Label();
            this.Height = new System.Windows.Forms.Label();
            this.textBoxWindowsWidth = new System.Windows.Forms.TextBox();
            this.textBoxWindowsHeight = new System.Windows.Forms.TextBox();
            this.buttonApply = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // Width
            // 
            this.Width.AutoSize = true;
            this.Width.Location = new System.Drawing.Point(13, 13);
            this.Width.Name = "Width";
            this.Width.Size = new System.Drawing.Size(89, 13);
            this.Width.TabIndex = 0;
            this.Width.Text = "Window width   =";
            // 
            // Height
            // 
            this.Height.AutoSize = true;
            this.Height.Location = new System.Drawing.Point(13, 49);
            this.Height.Name = "Height";
            this.Height.Size = new System.Drawing.Size(87, 13);
            this.Height.TabIndex = 1;
            this.Height.Text = "Window height =";
            this.Height.Click += new System.EventHandler(this.Height_Click);
            // 
            // textBoxWindowsWidth
            // 
            this.textBoxWindowsWidth.Location = new System.Drawing.Point(126, 10);
            this.textBoxWindowsWidth.Name = "textBoxWindowsWidth";
            this.textBoxWindowsWidth.Size = new System.Drawing.Size(61, 20);
            this.textBoxWindowsWidth.TabIndex = 2;
            this.textBoxWindowsWidth.TextChanged += new System.EventHandler(this.textBoxWindowsWidth_TextChanged);
            // 
            // textBoxWindowsHeight
            // 
            this.textBoxWindowsHeight.Location = new System.Drawing.Point(126, 49);
            this.textBoxWindowsHeight.Name = "textBoxWindowsHeight";
            this.textBoxWindowsHeight.Size = new System.Drawing.Size(61, 20);
            this.textBoxWindowsHeight.TabIndex = 3;
            this.textBoxWindowsHeight.TextChanged += new System.EventHandler(this.textBoxWindowsHeight_TextChanged);
            // 
            // buttonApply
            // 
            this.buttonApply.Location = new System.Drawing.Point(126, 86);
            this.buttonApply.Name = "buttonApply";
            this.buttonApply.Size = new System.Drawing.Size(61, 22);
            this.buttonApply.TabIndex = 4;
            this.buttonApply.Text = "Apply";
            this.buttonApply.UseVisualStyleBackColor = true;
            this.buttonApply.Click += new System.EventHandler(this.buttonApply_Click);
            // 
            // WindowSettings
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(203, 120);
            this.Controls.Add(this.buttonApply);
            this.Controls.Add(this.textBoxWindowsHeight);
            this.Controls.Add(this.textBoxWindowsWidth);
            this.Controls.Add(this.Height);
            this.Controls.Add(this.Width);
            this.Cursor = System.Windows.Forms.Cursors.Default;
            this.MaximumSize = new System.Drawing.Size(219, 159);
            this.MinimumSize = new System.Drawing.Size(219, 159);
            this.Name = "WindowSettings";
            this.Text = "WindowSettings";
            this.Load += new System.EventHandler(this.WindowSettings_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label Width;
        private System.Windows.Forms.Label Height;
        private System.Windows.Forms.TextBox textBoxWindowsWidth;
        private System.Windows.Forms.TextBox textBoxWindowsHeight;
        private System.Windows.Forms.Button buttonApply;
    }
}