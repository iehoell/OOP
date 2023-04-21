using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MyLib;

namespace Lab3._1
{
    public partial class Form1 : Form
    {
        private double[,] History = new double[2,7];
        MyCalc1 Calc = new MyCalc1();

        double answer;
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try 
            {
                Calc.A = Convert.ToDouble(textBox1.Text);
                Calc.B = Convert.ToDouble(textBox2.Text);
                answer = Calc.Calc1();
                textBox3.Text = Convert.ToString(answer);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            textBox1.Text = Convert.ToString(History[0, 0]);
            textBox2.Text = Convert.ToString(History[1, 0]);
            textBox3.Text = Convert.ToString((History[0, 0] * History[1, 0]) / (History[0, 0] + 2) / (History[1, 0] - 1));
        }

        private void button4_Click(object sender, EventArgs e)
        {
            textBox1.Text = Convert.ToString(History[0, 1]);
            textBox2.Text = Convert.ToString(History[1, 1]);
            textBox3.Text = Convert.ToString((History[0, 1] * History[1, 1]) / (History[0, 1] + 2) / (History[1, 1] - 1));
        }

        private void button5_Click(object sender, EventArgs e)
        {
            textBox1.Text = Convert.ToString(History[0, 2]);
            textBox2.Text = Convert.ToString(History[1, 2]);
            textBox3.Text = Convert.ToString((History[0, 2] * History[1, 2]) / (History[0, 2] + 2) / (History[1, 2] - 1));
        }

        private void button6_Click(object sender, EventArgs e)
        {
            textBox1.Text = Convert.ToString(History[0, 3]);
            textBox2.Text = Convert.ToString(History[1, 3]);
            textBox3.Text = Convert.ToString((History[0, 3] * History[1, 3]) / (History[0, 3] + 2) / (History[1, 3] - 1));
        }

        private void button7_Click(object sender, EventArgs e)
        {
            textBox1.Text = Convert.ToString(History[0, 4]);
            textBox2.Text = Convert.ToString(History[1, 4]);
            textBox3.Text = Convert.ToString((History[0, 4] * History[1, 4]) / (History[0, 4] + 2) / (History[1, 4] - 1));
        }

        private void button8_Click(object sender, EventArgs e)
        {
            textBox1.Text = Convert.ToString(History[0, 5]);
            textBox2.Text = Convert.ToString(History[1, 5]);
            textBox3.Text = Convert.ToString((History[0, 5] * History[1, 5]) / (History[0, 5] + 2) / (History[1, 5] - 1));
        }
        private void button9_Click(object sender, EventArgs e)
        {
            textBox1.Text = Convert.ToString(History[0, 6]);
            textBox2.Text = Convert.ToString(History[1, 6]);
            textBox3.Text = Convert.ToString((History[0, 6] * History[1, 6]) / (History[0, 6] + 2) / (History[1, 6] - 1));
        }
        private void history_update(MyCalc1 new_val) 
        {
            for (int num_of_history_val = 6; num_of_history_val > 0; num_of_history_val--)
            {
                History[0, num_of_history_val] = History[0, num_of_history_val - 1];
                History[1, num_of_history_val] = History[1, num_of_history_val - 1];
            }
            History[0, 0] = new_val.A;
            History[1, 0] = new_val.B;
            if (History[0, 0] == 0 && History[1, 0] == 0) { button3.Text = ""; }
            else { button3.Text = "A = " + Convert.ToString(History[0, 0]) + " B = " + Convert.ToString(History[1, 0]); }
            if (History[0, 1] == 0 && History[1, 1] == 0) { button4.Text = ""; }
            else { button4.Text = "A = " + Convert.ToString(History[0, 1]) + " B = " + Convert.ToString(History[1, 1]); }
            if (History[0, 2] == 0 && History[1, 2] == 0) { button5.Text = ""; }
            else { button5.Text = "A = " + Convert.ToString(History[0, 2]) + " B = " + Convert.ToString(History[1, 2]); }
            if (History[0, 3] == 0 && History[1, 3] == 0) { button6.Text = ""; }
            else { button6.Text = "A = " + Convert.ToString(History[0, 3]) + " B = " + Convert.ToString(History[1, 3]); }
            if (History[0, 4] == 0 && History[1, 4] == 0) { button7.Text = ""; }
            else { button7.Text = "A = " + Convert.ToString(History[0, 4]) + " B = " + Convert.ToString(History[1, 4]); }
            if (History[0, 5] == 0 && History[1, 5] == 0) { button8.Text = ""; }
            else { button8.Text = "A = " + Convert.ToString(History[0, 5]) + " B = " + Convert.ToString(History[1, 5]); }
            if (History[0, 6] == 0 && History[1, 6] == 0) { button9.Text = ""; }
            else { button9.Text = "A = " + Convert.ToString(History[0, 6]) + " B = " + Convert.ToString(History[1, 6]); }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
