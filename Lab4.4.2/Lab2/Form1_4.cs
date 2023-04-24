using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Rebar;

namespace Lab2
{
    public partial class Form1_4 : Form
    {
        int size = 0;
        public Form1_4()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            if (textBox1.Text.Any(Char.IsDigit))
            {
                size = Convert.ToInt32(textBox1.Text);
            }
            else
            {
                MessageBox.Show("Неверный ввод параметра");
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            String str = "", massive1;
            Random rand = new Random(System.DateTime.Now.Millisecond);
            int[] mas = new int[size];
            int i = 0;
            for (i = 0; i < size; i++)
            {
                mas[i] = rand.Next() % 30 - 15;
            }
            massive1 = printMassive(mas, size, str);
            Array(mas, str, size, massive1);
        }
        public static void Array(int[] mas, string str, int size, String massive1)
        {
            List<int> l = new List<int>();
            foreach (int elem in mas)
                if (elem < 0)
                    l.Add(elem);
            foreach (int elem in mas)
                if (elem >= 0)
                    l.Add(elem);
            mas = l.ToArray();
            MessageBox.Show("Исходный массив:\n" + massive1 + "\nПреобразованный массив:\n" + printMassive(mas, size, str));
        }

        public static String printMassive(int[] mas, int size, string str)
        {
            for (int i = 0; i < size; i++)
            {
                str += $"{mas[i]} ";
            }
            return str;
        }
    }
}
