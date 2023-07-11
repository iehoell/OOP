using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Menu
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void ВыходToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // Переменная rsl будет хранить результат вывода окна с вопросом 
            // (пользователь нажал одну из клавиш на окне - это и есть результат) 
            // MessageBox будет содержать вопрос, а также кнопки Yes, No и иконку Question (Вопрос) 
            DialogResult rsl = MessageBox.Show("Закрыть приложение?", "Внимание!", MessageBoxButtons.YesNo, MessageBoxIcon.Question);

            // Если пользователь нажал кнопку да 
            if (rsl == DialogResult.Yes)
                Application.Exit(); // выходим из приложения 
        }

        // Память для хранения изображения
        Image MemForImage;

        // Метод загрузки изображения 
        private void LoadImage(bool IsJPEG)
        {

            // Каталог, который будет выбран как начальный в окне выбора файла 
            openFileDialog1.InitialDirectory = "c:";

            // Если будут выбиратся jpg-файлы 
            if (IsJPEG)
            {
                // Устанавка формата файлов для загрузки - jpg 
                openFileDialog1.Filter = "image (JPEG) files (*.jpg)|*.jpg|All files (*.*)|*.*";
            }
            else
            {
                // Устанавка формата файлов для загрузки - bmp 
                openFileDialog1.Filter = "image (BMP) files (*.bmp)|*.bmp|All files (*.*)|*.*";
            }

            // если открытие окна выбора файла завершилось выбором файла и нажатием кнопки ОК 
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                //Имя выбранного пользователем файла
                string FileName=openFileDialog1.FileName;
                try // Блок операторов с защитой от ошибок
                {
                    // Загрузка изображения из файла FileName. 
                    MemForImage = Image.FromFile(FileName);
                    // Вывод изображения в поле элемента PictureBox 
                    pictureBox1.Image = MemForImage;

                    textBox1.AppendText("Загружен файл " + FileName + "\r\n");
                    toolStripStatusLabel1.Text = FileName;
                }
                catch (Exception ex) // Если произошла ошибка 
                {
                    // Выводим сообщения с причиной ошибки 
                    MessageBox.Show("Не удалось загрузить файл: " + ex.Message);
                }

            }
        }

        private void вФорматеJPEGToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // Загружаем jpg-файл 
            LoadImage(true);
        }

        private void вФорматеBMPToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // Загружаем bmp-файл 
            LoadImage(false);
        }

        private void контекст1ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            toolStripStatusLabel2.Text = "";
            Control sourceControl=null;
            // Определяем выбранный пункт меню
            ToolStripItem menuItem = sender as ToolStripItem;
            if (menuItem != null)
            {
                // Находим ContextMenuStrip - владельца найденного пункта меню
                ContextMenuStrip owner = menuItem.Owner as ContextMenuStrip;
                if (owner != null)
                {
                    // Находим Сontrol, для которого вызвано контекстное меню
                    sourceControl = owner.SourceControl;
                }
            }
            toolStripStatusLabel2.Text = sourceControl.Name;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void вывестиГрафикToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form2 newForm = new Form2();
            newForm.Show();
        }
    }
}
