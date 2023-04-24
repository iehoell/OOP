using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab1
{
    static class Lab1
    {
        public static double FunctionCalculator(double b, double d, double n)
        {
            double a = 0;
            a = b + d * (n - 1);
            return a;
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

        public static double FunctionOfY(double Xn, double Xk, double Yx)
        {
            Yx = ((Xn * Xn) / 4 + Xn / 2 + 1) * Math.Pow(2.718, Xn / 2);
            return Yx;
        }

        public static double FunctionOfYAndS(double Xn, double Xk, double Yx, double Sx)
        {
            double factorial = 1, x = 0;
            x = Xn;
            Yx = ((Xn * Xn) / 4 + Xn / 2 + 1) * Math.Pow(2.718, Xn / 2);
            return Yx;
        }

       public static void Array(int size, int[] mas)
        {
            List<int> l = new List<int>();
            foreach (int elem in mas)
                if (elem < 0)
                    l.Add(elem);
            foreach (int elem in mas)
                if (elem >= 0)
                    l.Add(elem);
            mas = l.ToArray();
            foreach (int elem in mas)
                Console.Write(elem + " ");
        }
    }
}