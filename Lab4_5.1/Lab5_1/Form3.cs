using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;

namespace Lab5_1
{
    public partial class Form3 : Form
    {
        double a = 0;
        public Form3(double a)
        {
            InitializeComponent();
            this.a = a;
        }

        private void Form3_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            chart1.Series[0].Points.Clear();
            chart1.Series[0].ChartType = SeriesChartType.FastLine;
            float Pi = 3.1415F;
            int countOfPoint = 100;
            float xMin = 0, xMax = 6 * Pi;
            float xStep = (xMax - xMin) / countOfPoint;
            float x1 = xMin, y1 = (float)(Math.Sin((2 * Pi) + x1) * Math.Exp⁡(x1 * a));
            for (int i = 0; i < countOfPoint; i++) 
            {
                float x2 = x1 + xStep;
                float y2 = (float)(Math.Sin((2 * Pi) + x1) * Math.Exp⁡(x2 * a));
                chart1.Series[0].Points.AddXY(x1, y1);
                x1 = x2;
                y1 = y2;
            }
        }
    }
}
