using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab8_2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void pictureBox1_MouseClick(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left) 
            {
                Bitmap bmp = new Bitmap(pictureBox1.Width, pictureBox1.Height, System.Drawing.Imaging.PixelFormat.Format24bppRgb);
                Graphics g = Graphics.FromImage(bmp);
                Pen myPen = new Pen(System.Drawing.Color.White, 2);
                g.DrawLine(myPen, pictureBox1.Width, pictureBox1.Height, e.X, e.Y);
                pictureBox1.Image = bmp;
            }
            if (e.Button == MouseButtons.Right)
            {
                Bitmap bmp = new Bitmap(pictureBox1.Width, pictureBox1.Height, System.Drawing.Imaging.PixelFormat.Format24bppRgb);
                Graphics g = Graphics.FromImage(bmp);
                Pen myPen = new Pen(System.Drawing.Color.White, 2);
                g.DrawLine(myPen, 0, 0, e.X, e.Y);
                pictureBox1.Image = bmp;
            }
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }
    }
}
