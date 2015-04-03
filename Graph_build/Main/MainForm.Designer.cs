namespace Main
{
    partial class MainForm
    {
        /// <summary>
        /// Требуется переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Обязательный метод для поддержки конструктора - не изменяйте
        /// содержимое данного метода при помощи редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.label2 = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.ButtonBuild = new System.Windows.Forms.Button();
            this.menuStrip = new System.Windows.Forms.MenuStrip();
            this.buildToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.letsBuildToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.animationToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.fxToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.fxToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.fxToolStripMenuItem2 = new System.Windows.Forms.ToolStripMenuItem();
            this.fxToolStripMenuItem3 = new System.Windows.Forms.ToolStripMenuItem();
            this.settingsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.graphToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.windowToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.emptyPointsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.examplesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip.SuspendLayout();
            this.SuspendLayout();
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(14, 60);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(58, 25);
            this.label2.TabIndex = 4;
            this.label2.Text = "f(x) =";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // textBox1
            // 
            this.textBox1.BackColor = System.Drawing.SystemColors.Window;
            this.textBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox1.Location = new System.Drawing.Point(78, 41);
            this.textBox1.Multiline = true;
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(400, 150);
            this.textBox1.TabIndex = 1;
            this.textBox1.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(75, 153);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(0, 13);
            this.label4.TabIndex = 6;
            // 
            // ButtonBuild
            // 
            this.ButtonBuild.BackColor = System.Drawing.SystemColors.Window;
            this.ButtonBuild.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ButtonBuild.Location = new System.Drawing.Point(368, 197);
            this.ButtonBuild.Name = "ButtonBuild";
            this.ButtonBuild.Size = new System.Drawing.Size(110, 29);
            this.ButtonBuild.TabIndex = 11;
            this.ButtonBuild.Text = "Let\'s build";
            this.ButtonBuild.UseVisualStyleBackColor = false;
            this.ButtonBuild.Click += new System.EventHandler(this.ButtonBuild_Click);
            // 
            // menuStrip
            // 
            this.menuStrip.Font = new System.Drawing.Font("Segoe UI", 9F);
            this.menuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.buildToolStripMenuItem,
            this.animationToolStripMenuItem,
            this.settingsToolStripMenuItem,
            this.helpToolStripMenuItem});
            this.menuStrip.Location = new System.Drawing.Point(0, 0);
            this.menuStrip.Name = "menuStrip";
            this.menuStrip.Size = new System.Drawing.Size(492, 24);
            this.menuStrip.TabIndex = 14;
            this.menuStrip.Text = "menuStrip";
            this.menuStrip.ItemClicked += new System.Windows.Forms.ToolStripItemClickedEventHandler(this.menuStrip_ItemClicked);
            // 
            // buildToolStripMenuItem
            // 
            this.buildToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.letsBuildToolStripMenuItem});
            this.buildToolStripMenuItem.Font = new System.Drawing.Font("Segoe UI", 9F);
            this.buildToolStripMenuItem.Name = "buildToolStripMenuItem";
            this.buildToolStripMenuItem.Size = new System.Drawing.Size(46, 20);
            this.buildToolStripMenuItem.Text = "Build";
            // 
            // letsBuildToolStripMenuItem
            // 
            this.letsBuildToolStripMenuItem.Name = "letsBuildToolStripMenuItem";
            this.letsBuildToolStripMenuItem.Size = new System.Drawing.Size(128, 22);
            this.letsBuildToolStripMenuItem.Text = "Let\'s build";
            this.letsBuildToolStripMenuItem.Click += new System.EventHandler(this.letsBuildToolStripMenuItem_Click);
            // 
            // animationToolStripMenuItem
            // 
            this.animationToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fxToolStripMenuItem,
            this.fxToolStripMenuItem1,
            this.fxToolStripMenuItem2,
            this.fxToolStripMenuItem3});
            this.animationToolStripMenuItem.Name = "animationToolStripMenuItem";
            this.animationToolStripMenuItem.Size = new System.Drawing.Size(75, 20);
            this.animationToolStripMenuItem.Text = "Animation";
            // 
            // fxToolStripMenuItem
            // 
            this.fxToolStripMenuItem.Name = "fxToolStripMenuItem";
            this.fxToolStripMenuItem.Size = new System.Drawing.Size(99, 22);
            this.fxToolStripMenuItem.Text = "[f(x)]";
            this.fxToolStripMenuItem.Click += new System.EventHandler(this.fxToolStripMenuItem_Click);
            // 
            // fxToolStripMenuItem1
            // 
            this.fxToolStripMenuItem1.Name = "fxToolStripMenuItem1";
            this.fxToolStripMenuItem1.Size = new System.Drawing.Size(99, 22);
            this.fxToolStripMenuItem1.Text = "{f(x)}";
            this.fxToolStripMenuItem1.Click += new System.EventHandler(this.fxToolStripMenuItem1_Click);
            // 
            // fxToolStripMenuItem2
            // 
            this.fxToolStripMenuItem2.Name = "fxToolStripMenuItem2";
            this.fxToolStripMenuItem2.Size = new System.Drawing.Size(99, 22);
            this.fxToolStripMenuItem2.Text = "f([x])";
            this.fxToolStripMenuItem2.Click += new System.EventHandler(this.fxToolStripMenuItem2_Click);
            // 
            // fxToolStripMenuItem3
            // 
            this.fxToolStripMenuItem3.Name = "fxToolStripMenuItem3";
            this.fxToolStripMenuItem3.Size = new System.Drawing.Size(99, 22);
            this.fxToolStripMenuItem3.Text = "f({x})";
            this.fxToolStripMenuItem3.Click += new System.EventHandler(this.fxToolStripMenuItem3_Click);
            // 
            // settingsToolStripMenuItem
            // 
            this.settingsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.graphToolStripMenuItem,
            this.windowToolStripMenuItem,
            this.emptyPointsToolStripMenuItem});
            this.settingsToolStripMenuItem.Name = "settingsToolStripMenuItem";
            this.settingsToolStripMenuItem.Size = new System.Drawing.Size(61, 20);
            this.settingsToolStripMenuItem.Text = "Settings";
            // 
            // graphToolStripMenuItem
            // 
            this.graphToolStripMenuItem.Name = "graphToolStripMenuItem";
            this.graphToolStripMenuItem.Size = new System.Drawing.Size(144, 22);
            this.graphToolStripMenuItem.Text = "Graph";
            this.graphToolStripMenuItem.Click += new System.EventHandler(this.graphToolStripMenuItem_Click);
            // 
            // windowToolStripMenuItem
            // 
            this.windowToolStripMenuItem.Name = "windowToolStripMenuItem";
            this.windowToolStripMenuItem.Size = new System.Drawing.Size(144, 22);
            this.windowToolStripMenuItem.Text = "Window";
            this.windowToolStripMenuItem.Click += new System.EventHandler(this.windowToolStripMenuItem_Click);
            // 
            // emptyPointsToolStripMenuItem
            // 
            this.emptyPointsToolStripMenuItem.Name = "emptyPointsToolStripMenuItem";
            this.emptyPointsToolStripMenuItem.Size = new System.Drawing.Size(144, 22);
            this.emptyPointsToolStripMenuItem.Text = "Empty Points";
            this.emptyPointsToolStripMenuItem.Click += new System.EventHandler(this.emptyPointsToolStripMenuItem_Click);
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.helpToolStripMenuItem1,
            this.examplesToolStripMenuItem,
            this.aboutToolStripMenuItem});
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.Size = new System.Drawing.Size(44, 20);
            this.helpToolStripMenuItem.Text = "Help";
            // 
            // helpToolStripMenuItem1
            // 
            this.helpToolStripMenuItem1.Name = "helpToolStripMenuItem1";
            this.helpToolStripMenuItem1.Size = new System.Drawing.Size(152, 22);
            this.helpToolStripMenuItem1.Text = "Help";
            this.helpToolStripMenuItem1.Click += new System.EventHandler(this.helpToolStripMenuItem1_Click);
            // 
            // examplesToolStripMenuItem
            // 
            this.examplesToolStripMenuItem.Name = "examplesToolStripMenuItem";
            this.examplesToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.examplesToolStripMenuItem.Text = "Examples";
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.aboutToolStripMenuItem.Text = "About";
            this.aboutToolStripMenuItem.Click += new System.EventHandler(this.aboutToolStripMenuItem_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Window;
            this.ClientSize = new System.Drawing.Size(492, 237);
            this.Controls.Add(this.ButtonBuild);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.menuStrip);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximumSize = new System.Drawing.Size(508, 276);
            this.MinimumSize = new System.Drawing.Size(508, 276);
            this.Name = "MainForm";
            this.Text = "Graph Builder";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.menuStrip.ResumeLayout(false);
            this.menuStrip.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button ButtonBuild;
        private System.Windows.Forms.MenuStrip menuStrip;
        private System.Windows.Forms.ToolStripMenuItem buildToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem letsBuildToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem animationToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem fxToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem fxToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem fxToolStripMenuItem2;
        private System.Windows.Forms.ToolStripMenuItem fxToolStripMenuItem3;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem examplesToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem settingsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem graphToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem windowToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem emptyPointsToolStripMenuItem;
    }
}

