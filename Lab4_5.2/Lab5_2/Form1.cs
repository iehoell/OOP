using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab5_2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            Random rand = new Random();
            Graphics g = graphWind.CreateGraphics();
            Pen myPen = new Pen(Color.Red);
            Pen myPen1 = new Pen(Color.Green);
            Pen myPen2 = new Pen(Color.Blue);
            Pen myPen3 = new Pen(Color.Purple);
            Font fnt = new Font("Arial", 16);
            myPen.Width = 1;

            for (int i = 0; i < rand.Next(2) + 1; i++)
            {
                g.DrawRectangle(myPen, rand.Next(graphWind.Width), rand.Next(graphWind.Height),
                    rand.Next(graphWind.Height), rand.Next(graphWind.Height));
                //прямоугольник
                g.DrawArc(myPen1, rand.Next(100), rand.Next(100),
                    rand.Next(graphWind.Width), rand.Next(graphWind.Height), rand.Next(45),
                    rand.Next(45));
                //дуга
                g.DrawBezier(myPen2, rand.Next(graphWind.Width), rand.Next(graphWind.Height),
                    rand.Next(graphWind.Width), rand.Next(graphWind.Height),
                    rand.Next(graphWind.Width), rand.Next(graphWind.Height),
                    rand.Next(graphWind.Width), rand.Next(graphWind.Height));
                //сплайн
                g.DrawLine(myPen3, rand.Next(graphWind.Width), rand.Next(graphWind.Height),
                    rand.Next(graphWind.Width), rand.Next(graphWind.Height));
                //прямая
                g.DrawString("X", fnt, new SolidBrush(Color.Black), rand.Next(graphWind.Width),
                    rand.Next(graphWind.Height));
                //строка
                g.DrawPie(myPen3, new Rectangle(0,0,rand.Next(200),rand.Next(100)), rand.Next(0),
                    rand.Next(360));
                //круг/часть круга
            }
        }

        private void button2_Click_1(object sender, EventArgs e)
        {
            Graphics g = graphWind.CreateGraphics();
            g.Clear(Color.White);
        }
    }
}
