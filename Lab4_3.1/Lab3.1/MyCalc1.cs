using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab3._1
{
    public class MyCalc1
    {
        private int _a;
        private int _b;
        public int b
        {
            get { return _b; }
            set
            {
                if (value == 0) //Генерируем исключение - нулевые значения запрещены!
                    throw new Exception("Нулевое значение a недопустимо!");
                else
                    _b = value;
            }
        }

        public int a
        {
            get { return _a; }
            set
            {
                if (value == 0) //Генерируем исключение - нулевые значения запрещены!
                    throw new Exception("Нулевое значение b недопустимо!");
                else
                    _a = value;
            }
        }

        public double Calc()
        {
            double c = (a * b) / (a + 2) / (b - 1);
            return c;
        }
    }
}
