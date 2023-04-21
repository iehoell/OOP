using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab3._2
{
    public partial class Form1 : Form
    {
        public double answer;
        MyCalc2 Calc = new MyCalc2();
        public Form1()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                Calc.A = Convert.ToDouble(textBox1.Text);
                Calc.B = Convert.ToDouble(textBox2.Text);
                Calc.D = Convert.ToDouble(textBox3.Text);
                answer = Calc.Calc1();
                textBox4.Text = Convert.ToString(answer);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
