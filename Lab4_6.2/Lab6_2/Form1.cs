using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab6_2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void toolStripStatusLabel1_Click(object sender, EventArgs e)
        {

        }

        private void statusStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }

        private void сотрудникToolStripMenuItem_Click(object sender, EventArgs e)
        {
            toolStripStatusLabel1.Text = "информация о сотруднике";
            MessageBox.Show("Объект -> сотрудник\nинформация о сотруднике");
        }

        private void клиентToolStripMenuItem_Click(object sender, EventArgs e)
        {
            toolStripStatusLabel1.Text = "информация о клиенте";
            MessageBox.Show("Объект -> клиент\nинформация о клиенте");
        }

        private void договорToolStripMenuItem_Click(object sender, EventArgs e)
        {
            toolStripStatusLabel1.Text = "информация о договоре";
            MessageBox.Show("Объект -> договор\nинформация о договоре");
        }

        private void поручениеToolStripMenuItem_Click(object sender, EventArgs e)
        {
            toolStripStatusLabel1.Text = "информация о поучении";
            MessageBox.Show("Объект -> поручение\nинформация о поручение");
        }

        private void сделкаToolStripMenuItem_Click(object sender, EventArgs e)
        {
            toolStripStatusLabel1.Text = "информация о сделке";
            MessageBox.Show("Объект -> сделка\nинформация о сделке");
        }

        private void выходToolStripMenuItem_Click(object sender, EventArgs e)
        {
            DialogResult rsl = MessageBox.Show("Закрыть приложение?", "Внимание!", MessageBoxButtons.YesNo, MessageBoxIcon.Question);

            // Если пользователь нажал кнопку да 
            if (rsl == DialogResult.Yes)
                Application.Exit();
        }

        private void узнатьОбщуюИнформациюToolStripMenuItem_Click(object sender, EventArgs e)
        {
            toolStripStatusLabel1.Text = "общая информация";
            MessageBox.Show("Справочник -> узнать общую информацию\nобщая информация");
        }

        private void должностьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            toolStripStatusLabel1.Text = "должность";
            MessageBox.Show("Справочник -> должность\nдолжность");
        }

        private void странаToolStripMenuItem_Click(object sender, EventArgs e)
        {
            toolStripStatusLabel1.Text = "страна";
            MessageBox.Show("Справочник -> страна\nстрана");
        }

        private void регионToolStripMenuItem_Click(object sender, EventArgs e)
        {
            toolStripStatusLabel1.Text = "регион";
            MessageBox.Show("Справочник -> регион\nрегион");
        }

        private void городToolStripMenuItem_Click(object sender, EventArgs e)
        {
            toolStripStatusLabel1.Text = "город";
            MessageBox.Show("Справочник -> город\nгород");
        }

        private void иМНСToolStripMenuItem_Click(object sender, EventArgs e)
        {
            toolStripStatusLabel1.Text = "ИНМС";
            MessageBox.Show("Справочник -> ИНМС\nИНМС");
        }

        private void справочникToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void обьектToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void оПрограммеToolStripMenuItem_Click(object sender, EventArgs e)
        {
            toolStripStatusLabel1.Text = "о программе";
            MessageBox.Show("Справка -> о программе\nо программе");
        }
    }
}
