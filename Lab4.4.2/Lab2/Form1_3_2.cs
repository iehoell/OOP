using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.ProgressBar;

namespace Lab2
{
    public partial class Form1_3_2 : Form
    {
        double Xn = 0, Xk = 0, h = 0, Yx = 0;
        public Form1_3_2()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            double Xn, Xk, h;
            Xn = Convert.ToDouble(textBox1.Text);
            Xk = Convert.ToDouble(textBox2.Text);
            double answerX, answerS, answerY;
            String str = "";
            h = (Xk - Xn) / 10;
            int count = 0;
            double Sx = 0, factorial = 1;
            for (int n = 1; n <= 14; n++)
            {
                Sx += Math.Round(((n-1) * (n-1) + 1) / Factorial((n-1), factorial) * Math.Pow((Xn / 2), (n-1)), 5);
                count++;
                if (count == 14)
                {
                    answerX = FunctionOfYAndS(Xn, 1);
                    answerY = FunctionOfYAndS(Xn, 2);
                    answerS = FunctionOfYAndS(Sx, 3);
                    str += $"При X = {answerX} , Y(x) = {answerY} , S(x) = {answerS}\n";
                    Xn += h;
                    n = 0;
                    count = 0;
                    Sx = 0;
                }
                if (Xn >= Xk) break;
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

        public static double FunctionOfYAndS(double Xn, int change)
        {

            double e = 2.71828;

            switch (change)
            {
                case 1:
                    return Math.Round(Xn, 5);
                case 2:
                    return Math.Round(((Xn * Xn) / 4 + Xn / 2 + 1) * Math.Pow(e, Xn / 2), 5);
                case 3:
                    return Math.Round(Xn, 5);
                default:
                    return 0;
                }
        }

        public static Double Factorial(double n, double factorial)
        {
            for (int i = 2; i <= n; i++)
            {
                factorial = factorial * i;
            }
            return factorial;
        }
    }
}
