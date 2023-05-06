using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab5_1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            double a = 0;
            try
            {
                a = double.Parse(textBox1.Text);
                if (a >= 4)
                {
                    a = 0;
                    textBox1.Text = "0";
                    MessageBox.Show("При значении переменной \"a\" больше 4, расчёты не могут быть корректны!\n" +
                        "По умолчанию значение переменной \"a\" будет равняться нулю!");
                }
                Form2 newForm = new Form2(a);
                newForm.Show();
            }
            catch
            {
                MessageBox.Show("некорректно введено значение");
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            double a = 0;
            try
            {

                a = double.Parse(textBox1.Text);
                if (a >= 4)
                {
                    a = 0;
                    textBox1.Text = "0";
                    MessageBox.Show("При значении переменной \"a\" больше 4, расчёты не могут быть корректны!\n" +
                        "По умолчанию значение переменной \"a\" будет равняться нулю!");
                }
                Form3 newForm = new Form3(a);
                newForm.Show();
            }
            catch
            {
                MessageBox.Show("некорректно введено значение");
            }
        }
    }
}
