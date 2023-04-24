using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab4
{
    public abstract class ParentClass
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
        public double Sum
        {
            get { return val_summ; }
            set { if (value >= 0) val_summ = value; else val_summ = 0; }
        }
        public void CalcValue()
        {
            val_summ = Calc();
        }
        public virtual Double Calc()
        {
            return 0;
        }

        public string ToString(string suffix)
        {
            return suffix + val_summ;
        }
    }
    public class Calc1 : ParentClass
    {
        public override Double Calc()
        {
            return (val_a * val_b) / (val_a + 2) / (val_b - 1);
        }

        public override string ToString()
        {
            return "ответ 1 =" + Sum;
        }
    }
    public class Calc2 : ParentClass
    {
        public override Double Calc()
        {
                            
            if (val_d > val_b)
            {
                return (val_a * val_d) / (val_a + val_b);
            }
            else
            {
                return (val_a + val_b - val_d);
            }
        }
        public override string ToString()
        {
            return "ответ 2 =" + Sum;
        }
    }
}
