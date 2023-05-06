using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace Lab5._3._1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.chart1.Series[0].Points.Clear(); //S(x)
            this.chart1.Series[1].Points.Clear(); //Y(x)
            this.chart1.Series[2].Points.Clear(); //Y(x) - S(x)
            int factorial = 1, count = 0;
            //--------------------------------
            double x, yY, yS = 0;
            double countSteps = 1000;
            double xMin = Convert.ToDouble(textBox1.Text);
            double xMax = Convert.ToDouble(textBox2.Text);
            double xStep = (xMax - xMin) / countSteps;
            x = xMin;
            for (int n = 1; n <= 10; n++)
            {
                factorial *= n;
                yS += Math.Pow(2 * x, n) / factorial;
                count++;
                if (count == 10)
                {
                    // S(x) ----------------------------
                    this.chart1.Series[0].Points.AddXY(x, yS);
                    factorial = 1;
                    n = 0;
                    count = 0;
                    yS = 0;
                    // Y(s) ----------------------------
                    yY = Math.Pow(Math.E, 2 * x);
                    this.chart1.Series[1].Points.AddXY(x, yY);
                    x += xStep;
                }
                if (x >= xMax) break;
            }
            chart1.SaveImage("Graph3.jpeg", System.Windows.Forms.DataVisualization.Charting.ChartImageFormat.Jpeg);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.chart1.Series[0].Points.Clear(); //S(x)
            this.chart1.Series[1].Points.Clear(); //Y(x)
            this.chart1.Series[2].Points.Clear(); //Y(x) - S(x)
            // Y(x)
            int factorial = 1, count = 0;
            //--------------------------------
            double x, yY, yS = 0;
            double countSteps = 1000;
            double xMin = Convert.ToDouble(textBox1.Text);
            double xMax = Convert.ToDouble(textBox2.Text);
            double xStep = (xMax - xMin) / countSteps;
            x = xMin;
            for (int n = 1; n <= 10; n++)
            {
                factorial *= n;
                yS += Math.Pow(2 * x, n) / factorial;
                count++;
                if (count == 10)
                {

                    yY = Math.Pow(Math.E, 2 * x);
                    this.chart1.Series[0].Points.AddXY(x, yS);
                    this.chart1.Series[1].Points.AddXY(x, yY);
                    this.chart1.Series[2].Points.AddXY(x, yY - yS);
                    factorial = 1;
                    n = 0;
                    count = 0;
                    yS = 0;
                    x += xStep;
                }
                if (x >= xMax) break;
            }
            chart1.SaveImage("diffGraph3.jpeg", System.Windows.Forms.DataVisualization.Charting.ChartImageFormat.Jpeg);
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
                
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
