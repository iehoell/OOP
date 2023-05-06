namespace Lab5_1
{
    partial class Form2
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
            this.graphWind = new System.Windows.Forms.PictureBox();
            this.button1 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.graphWind)).BeginInit();
            this.SuspendLayout();
            // 
            // graphWind
            // 
            this.graphWind.BackColor = System.Drawing.Color.White;
            this.graphWind.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.graphWind.Location = new System.Drawing.Point(12, 12);
            this.graphWind.Name = "graphWind";
            this.graphWind.Size = new System.Drawing.Size(317, 475);
            this.graphWind.TabIndex = 1;
            this.graphWind.TabStop = false;
            this.graphWind.Click += new System.EventHandler(this.pictureBox1_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(83, 493);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(179, 56);
            this.button1.TabIndex = 2;
            this.button1.Text = "нарисовать график";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(343, 561);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.graphWind);
            this.Name = "Form2";
            this.Text = "ЛР 1.1";
            ((System.ComponentModel.ISupportInitialize)(this.graphWind)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox graphWind;
        private System.Windows.Forms.Button button1;
    }
}