using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab5_1
{
    public partial class Form2 : Form
    {
        double a = 0;
        public Form2(double a)
        {
            InitializeComponent();
            this.a = a;
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Graphics picture = graphWind.CreateGraphics();
            Pen usedPen = new Pen(Color.Blue);
            float Pi = 3.1415F;
            int countOfPoint = 100;
            float xMin = 0 , xMax = 6 * Pi;
            float xStep = (xMax - xMin) / countOfPoint;
            float yMin = (float)(Math.Cos((2 * Pi) + xMin) * Math.Exp⁡(xMin * a)), yMax = (float)(Math.Cos((2 * Pi) + xMax) * Math.Exp⁡(xMax * a));
            float kx = graphWind.Width / (xMax - xMin), ky = graphWind.Height / (yMax - yMin);
            float x1 = xMin, y1 = (float)(Math.Sin((2 * Pi) + x1) * Math.Exp⁡(x1 * a));
            for (int i = 0; i < countOfPoint; i++)
            {
                float x2 = x1 + xStep;
                float y2 = (float)(Math.Cos((2 * Pi) + x2) * Math.Exp⁡(x2 * a));    
                picture.DrawLine(usedPen, (float)(kx * x1), (float)graphWind.Height - (graphWind.Height + ky * y1), (float)(kx * x2), (float)graphWind.Height - (graphWind.Height + ky * y2));
                x1 = x2;                     
                y1 = y2;                     
            }

        }
    }
}
