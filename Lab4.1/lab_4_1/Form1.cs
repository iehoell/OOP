using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using lab_4_1;

namespace lab_4_1
{
    public partial class Form1 : Form
    {
        MyCalc calc = new MyCalc();
        double a;
        double b;
        double d;
        double sum;
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                a = Convert.ToDouble(textBoxA.Text);
                b = Convert.ToDouble(textBoxB.Text);
            }
            catch
            {
                MessageBox.Show("неправильно введены данные");
            }
            try
            {
                textBoxOut.AppendText("ответ = " + calc.Calc(a, b) + "\r\n");
                textBoxOut.AppendText(calc.ToString(calc.Calc(a, b)) + "\r\n");
                textBoxOut.AppendText(calc.ToString() + "\r\n");
                textBoxOut.AppendText("---------------------------------------\r\n");
            }
            catch
            {
                MessageBox.Show("недопусимые значения вывода");
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                a = Convert.ToDouble(textBoxA.Text);
                b = Convert.ToDouble(textBoxB.Text);
                d = Convert.ToDouble(textBoxD.Text);
            }
            catch
            {
                MessageBox.Show("неправильно введены данные");
            }
            try
            {
                textBoxOut.AppendText("ответ = " + calc.Calc(a, b, d) + "\r\n");
                textBoxOut.AppendText(calc.ToString(calc.Calc(a, b, d)) + "\r\n");
                textBoxOut.AppendText(calc.ToString() + "\r\n");
                textBoxOut.AppendText("---------------------------------------\r\n");
            }
            catch
            {
                MessageBox.Show("недопусимые значения вывода");
            }
        }

        private void textBoxOut_TextChanged(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }
    }
}
