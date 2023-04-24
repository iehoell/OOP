using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab_4_1
{
    public class MyCalc
    {
        protected double val_a = 0;
        protected double val_b = 0;
        protected double val_d = 0;
        protected double val_summ = 0;
        public double A
        {
            get { return val_a; }
            set { if (value >= 0) val_a = value; else val_a = 0; }
        }
        public double B
        {
            get { return val_b; }
            set { if (value >= 0) val_b = value; else val_b = 0; }
        }
        public double D
        {
            get { return val_d; }
            set { if (value >= 0) val_d = value; else val_d = 0; }
        }
        public double Get_Summ 
        {
            get { return val_summ; }
        }
        public String ToString(double number)
        {
            String str = "ответ = " + number;
            return str;
        }
        public String ToString()
        {
            return "ответ = " + Get_Summ.ToString();
        }
        public double Calc(double a, double b)
        {
            val_a = a; val_b = b;
            val_summ = (val_a * val_b) / (val_a + 2) / (val_b - 1);
            return val_summ;
        }

        public double Calc(double a, double b, double d)
        {
            if (d > b)
            {
                val_summ = (a * d) / (a + b);
            }
            else
            {
                val_summ = a + b - d;
            }
            return val_summ;
        }
    }
}
