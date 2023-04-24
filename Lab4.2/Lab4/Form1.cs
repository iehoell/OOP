using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Lab4;

namespace Lab4
{
    public partial class Form1 : Form
    {
        ParentClass calc1 = new Calc1();
        ParentClass calc2 = new Calc2();
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void textBoxA_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBoxB_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBoxC_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBoxOut_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            try 
            {
                calc1.A = Convert.ToDouble(textBoxA.Text);
                calc1.B = Convert.ToDouble(textBoxB.Text);
            }
            catch 
            {
                MessageBox.Show("неправильно введены данные");
            }
            try
            {
                calc1.CalcValue();
                textBoxOut.AppendText("ответ 1 =" + calc1.Sum.ToString() + "\r\n");
                textBoxOut.AppendText(calc1.ToString("ответ 1 =") + "\r\n");
                textBoxOut.AppendText(calc1.ToString() + "\r\n");
                textBoxOut.AppendText("---------------------------------------\r\n");
            }
            catch 
            {
                MessageBox.Show("недопусимые значения вывода");
            }
        }
        private void button2_Click_1(object sender, EventArgs e)
        {
            try
            {
                calc2.A = Convert.ToDouble(textBoxA.Text);
                calc2.B = Convert.ToDouble(textBoxB.Text);
                calc2.D = Convert.ToDouble(textBoxD.Text);
            }
            catch
            {
                MessageBox.Show("неправильно введены данные");
            }
            try
            {
                calc2.CalcValue();
                textBoxOut.AppendText("ответ 2 =" + calc2.Sum.ToString() + "\r\n");
                textBoxOut.AppendText(calc2.ToString("ответ 2 =") + "\r\n");
                textBoxOut.AppendText(calc2.ToString() + "\r\n");
                textBoxOut.AppendText("---------------------------------------\r\n");
            }
            catch
            {
                MessageBox.Show("недопусимые значения вывода");
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
