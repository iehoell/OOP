using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab8_4
{
    public partial class Form1 : Form
    {
        int mouseDown = 0;
        int mouseUp = 0;
        int oldX;
        int oldY;
        public Form1()
        {
            InitializeComponent();
        }


        private void pictureBox1_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                mouseUp = 0;
                mouseDown = 1;
            }
            else 
            {
                mouseDown = 0;
            }
        }

        private void pictureBox1_MouseMove(object sender, MouseEventArgs e)
        {
            if (mouseDown != 0 && mouseUp == 0) 
            {
                Graphics g = pictureBox1.CreateGraphics();
                g.DrawLine(new Pen(Brushes.Red, 4), new Point(oldX, oldY), new Point(e.X, e.Y));
            }
            oldX = e.X;
            oldY = e.Y;
        }

        private void pictureBox1_MouseUp(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                mouseUp = 1;
            }
            else
            {
                mouseUp = 0;
            }
        }
    }
}
