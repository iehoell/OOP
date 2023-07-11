using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Menu
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try 
            {
                double a = double.Parse(textBox1.Text);
                Graphics picture = graphWind.CreateGraphics();
                Pen usedPen = new Pen(Color.Blue);
                float Pi = 3.1415F;
                int countOfPoint = 100;
                float xMin = 0, xMax = 6 * Pi;
                float xStep = (xMax - xMin) / countOfPoint;
                float yMin = (float)(Math.Sin((2 * Pi) - (a * Math.Exp⁡(-xMin)))), yMax = (float)(Math.Sin((2 * Pi) - (a * Math.Exp⁡(-xMax))));
                float kx = graphWind.Width / (xMax - xMin), ky = graphWind.Height / (yMax - yMin);
                float x1 = xMin, y1 = (float)(Math.Sin((2 * Pi) - (a * Math.Exp⁡(-x1))));
                for (int i = 0; i < countOfPoint; i++)
                {
                    float x2 = x1 + xStep;
                    float y2 = (float)(Math.Sin((2 * Pi) - (a * Math.Exp⁡(-x2))));
                    picture.DrawLine(usedPen, (float)(kx * x1), (float)graphWind.Height - (graphWind.Height + ky * y1), (float)(kx * x2), (float)graphWind.Height - (graphWind.Height + ky * y2));
                    x1 = x2;
                    y1 = y2;
                }
            }
            catch 
            {
                MessageBox.Show("не верно введено значение а!!!");
            }

        }

        private void contextMenuStrip1_Opening(object sender, CancelEventArgs e)
        {

        }

        private void свойстваГрафиковToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("sin((2*PI) - (a * Exp(-x2)))");
        }
    }
}
