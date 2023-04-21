using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MyLib;

namespace Lab3._2
{
    internal class MyCalc2 : MyCalc1
    {
        protected double val_d;
        protected double c2; //результат


        public double D
        {
            get { return val_d; }
            set { val_d = value; }
        }

        public double C2
        {
            get { return c2; }
        }

        public MyCalc2() : base() { }
        public override double Calc1()
        {
            if (val_d > val_b)
            {
                if (val_a == -val_b)
                    throw new Exception("A = -B ???");
                else
                    c2 = (val_a * val_d) / (val_a + val_b);
            }
            else
            {
                c2 = val_a + val_b - val_d;
            }
            return c2;
        }
    }
}
