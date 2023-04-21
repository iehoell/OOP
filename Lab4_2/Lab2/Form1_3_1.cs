using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Linq;

namespace Lab2
{
    public partial class Form1_3_1 : Form
    {
        double Xn = 0, Xk = 0, h = 0, Yx = 0;
        public Form1_3_1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            double Xn, Xk, Xn2, h;
            Xn = Convert.ToDouble(textBox1.Text);
            Xn2 = Xn;
            Xk = Convert.ToDouble(textBox2.Text);
            double answerX, answerY;
            String str = "";
            h = (Xk - Xn) / 10;
            for (; Xn < Xk; Xn += h)
            {
                answerX = FunctionOfY(Xn, 1);
                answerY = FunctionOfY(Xn, 2);
                str += $"При x равным {answerX} , Y(x) = {answerY}\n";
            }
            MessageBox.Show(str);
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            if (textBox1.Text.Any(Char.IsDigit))
            {
                Xn = Convert.ToDouble(textBox1.Text);
            }
            else { MessageBox.Show("Неверный ввод параметра"); }
        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            if (textBox1.Text.Any(Char.IsDigit))
            {
                Xk = Convert.ToDouble(textBox1.Text);
            }
            else { MessageBox.Show("Неверный ввод параметра"); }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Text = "0";
            textBox2.Text = "0";
        }
        public static double FunctionOfY(double Xn, int change)
        {

            double e = 2.71828;

            switch(change)
            {
                case 1:
                    return Math.Round(Xn, 5);
                case 2:
                    return Math.Round(((Xn * Xn) / 4 + Xn / 2 + 1) * Math.Pow(e, Xn / 2), 5);
                default:
                    return 0;

            }
        }
    }
}
