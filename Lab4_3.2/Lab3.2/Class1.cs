using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyLib
{
    internal class MyCalc1
    {
        protected double val_a = 0;
        protected double val_b = 0;

        private double c; //Результат
        public double A
        {
            get { return val_a; }
            set
            {
                if (value == -2)
                    throw new Exception("A = -2 ???");
                else
                    val_a = value;
            }
        }
        public double B
        {
            get { return val_b; }
            set
            {
                if (value == 1)
                    throw new Exception("B = 1 ????");
                else
                    val_b = value;
            }
        }

        public double C
        { get { return c; } }

        public virtual double Calc1()
        {
            c = (val_a * val_b) / (val_a + 2) / (val_b - 1);
            return c;
        }
    }

}