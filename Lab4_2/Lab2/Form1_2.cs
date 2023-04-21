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

namespace Lab2
{
    public partial class Form1_2 : Form
    {
        int N = 0;
        public Form1_2()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            if (textBox1.Text.Any(Char.IsDigit))
            {
                N = Convert.ToInt32(textBox1.Text);
            }
            else { MessageBox.Show("Неверный ввод параметра"); }
        }

        private void button1_Click(object sender, EventArgs e)
        {  
            textBox2.Text = DefinitionOfACentury(N).ToString();
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Text = "0";
            textBox2.Text = "0";
        }
        public static int DefinitionOfACentury(int N)
        {
            int c = 0;
            if (N > 0)
            {
                if (N % 100 == 0) { c = N / 100; }
                else
                {
                    c = (N / 100) + 1;
                }
                return c;
            }
            return 0;
        }
    }
}
