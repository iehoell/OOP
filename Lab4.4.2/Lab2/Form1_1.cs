using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab2
{
    public partial class Form1_1 : Form
    {
        double b = 0, d = 0, n = 0;
        public Form1_1()
        {
            InitializeComponent();
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            if (textBox1.Text.Any(Char.IsDigit))
            {
                b = Convert.ToDouble(textBox1.Text);
            }
            else { MessageBox.Show("Неверный ввод параметра"); }
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            if (textBox2.Text.Any(Char.IsDigit))
            {
                d = Convert.ToDouble(textBox2.Text);
            }
            else { MessageBox.Show("Неверный ввод параметра"); }
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            if (textBox3.Text.Any(Char.IsDigit))
            {
                n = Convert.ToDouble(textBox3.Text);
            }
            else { MessageBox.Show("Неверный ввод параметра"); }
        }
        public static double FunctionCalculator(double b, double d, double n)
        {
            double a = 0;
            a = b + d * (n - 1);
            return a;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Text = "0";
            textBox2.Text = "0";
            textBox3.Text = "0";
            textBox4.Text = "0";
        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {
           
        }

        private void button1_Click(object sender, EventArgs e)
        {
            textBox4.Text = FunctionCalculator(b, d, n).ToString();
        }
    }
}
