namespace Main
{
    partial class Help
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
            this.textBoxHelp = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // textBoxHelp
            // 
            this.textBoxHelp.Location = new System.Drawing.Point(12, 12);
            this.textBoxHelp.Multiline = true;
            this.textBoxHelp.Name = "textBoxHelp";
            this.textBoxHelp.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textBoxHelp.Size = new System.Drawing.Size(560, 338);
            this.textBoxHelp.TabIndex = 3;
            // 
            // Help
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(584, 362);
            this.Controls.Add(this.textBoxHelp);
            this.Name = "Help";
            this.Text = "Help";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBoxHelp;
    }
}