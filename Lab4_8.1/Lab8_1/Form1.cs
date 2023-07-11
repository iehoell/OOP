using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab8_1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left) 
            {
                MessageForm form2 = new MessageForm();
                form2.DesktopLocation = new Point(e.X + this.Left, e.Y + this.Top);
                form2.textBox1.Text = $"вы нажали левую кнопку мыши X = {e.X + this.Left} Y = {e.Y + this.Top}";
                form2.Show();
            }
            else if (e.Button == MouseButtons.Right)
            {
                MessageForm form2 = new MessageForm();
                form2.Location = new Point(e.X + this.Left, e.Y + this.Top);
                form2.textBox1.Text = $"вы нажали правую кнопку мыши + X = {e.X + this.Left} Y = {e.Y + this.Top}";
                form2.Show();
            }
        }
    }
}
