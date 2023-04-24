using System;
using System.Collections.Generic;
using System.Text;

namespace Lab1
{
    class Program
    {
        static public bool ReadNumber<T>(string text, out T result)
        {
            int X = Console.CursorLeft;
            int Y = Console.CursorTop;
            int i = 0;

            Console.Write(text);

            StringBuilder sb = new StringBuilder();
            ConsoleKeyInfo keyInfo;

            do
            {
                keyInfo = Console.ReadKey(true);
                char keyChar = keyInfo.KeyChar;

                switch (keyInfo.Key)
                {
                    case ConsoleKey.OemMinus: //Символ "минус" (Проверка, что он является первым символом?)
                        if (sb.Length == 0)
                            sb.Append(keyChar);
                        break;

                    case ConsoleKey.Backspace: // Символ "Забой" последнего символа
                        if (sb.Length != 0)
                            sb.Remove(sb.Length - 1, 1);
                        break;

                    case ConsoleKey.OemComma: // Символ ","
                        sb.Append(keyChar);
                        break;

                    case ConsoleKey.Escape: // Символ "ESC" - отказ от ввода
                        sb.Clear();
                        break;

                    default:
                        if (Char.IsDigit(keyChar))  //Символ является цифрой
                            sb.Append(keyChar);
                        break;
                }

                Console.CursorLeft = X;
                Console.CursorTop = Y;
                Console.Write("{0} {1} ", text, sb.ToString());
            } while ((keyInfo.Key != ConsoleKey.Enter) && (keyInfo.Key != ConsoleKey.Escape));


            Console.WriteLine();
            result = default(T);
            if (sb.Length == 0)
                return false;
            result = (T)Convert.ChangeType(sb.ToString(), typeof(T));
            return true;
        }

        public static Double Factorial(double count, double factorial)
        {
            for (int i = 2; i <= count; i++)
            {
                factorial = factorial * i;
            }
            return factorial;
        }

        static void Main(string[] args)
        {
            int number = 0;
            Console.Write("--------------------------------------\n" +
                          "| Отмахов А.С. | ИВТ-22 | Вариант 10 |\n" +
                          "--------------------------------------\n");
            if (ReadNumber<int>("Введите номер задачи\n " +
                                "\t11 - 1.1,\n " +
                                "\t12 - 1.2,\n " +
                                "\t131 - 1.31,\n " +
                                "\t132 - 1.32,\n " +
                                "\t14 - 1.4\n", out number)) ;
            switch (number)
            {
                case 11:
                    double b = 0, d = 0, n = 0;
                    Console.Clear();
                    Console.WriteLine("Задание: вычислить значение функции a = b + d * (n - 1)");
                    Console.WriteLine("Введите число b");
                    b = Convert.ToDouble(Console.ReadLine());
                    Console.WriteLine("Введите число d");
                    d = Convert.ToDouble(Console.ReadLine());
                    Console.WriteLine("Введите число n");
                    n = Convert.ToDouble(Console.ReadLine());
                    Console.WriteLine("a = {0}", Lab1.FunctionCalculator(b, d, n));
                    break;
                case 12:
                    int N = 0;
                    Console.Clear();
                    Console.WriteLine("Задание: По номеру введенного года определить столетие");
                    Console.WriteLine("Введите год");
                    N = Convert.ToInt32(Console.ReadLine());
                    Console.WriteLine("Столетие равно {0}", Lab1.DefinitionOfACentury(N));
                    break;
                case 131:
                    double Xn = 0, Xk = 0, Yx = 0, h = 0;
                    Console.Clear();
                    Console.WriteLine("Задание: по заданным значениям Xn и Xk вывести значения X и Y c шагом h = (Xk - Xn) / 10");
                    Console.WriteLine("Введите значение Xn");
                    Xn = Convert.ToDouble(Console.ReadLine());
                    Console.WriteLine("Введите значение Xk");
                    Xk = Convert.ToDouble(Console.ReadLine());
                    h = (Xk - Xn) / 10;
                    while (Xn < Xk)
                    {
                        Console.WriteLine("При Xn = {0},  Yx = {1}", Math.Round(Xn, 3), Math.Round((Lab1.FunctionOfY(Xn, Xk, Yx)), 5));
                        Xn = Xn + h;
                    }
                    break;
                case 132:
                    double Sx = 0, x = 0, factorial = 1;
                    Xn = 0; Xk = 0; h = 0; Yx = 0;
                    Console.Clear();
                    Console.WriteLine("Задание: по заданным значениям Xn и Xk вывести значения X, Yx и Sx");
                    Console.WriteLine("Введите значение Xn");
                    Xn = Convert.ToDouble(Console.ReadLine());
                    Console.WriteLine("Введите значение Xk");
                    Xk = Convert.ToDouble(Console.ReadLine());
                    h = (Xk - Xn) / 10;
                    while (Xn < Xk)
                    {
                        for (int count = 0; count < 14; count++)
                        {
                            Sx = Sx + ((count * count + 1) / Factorial(count, factorial)) * Math.Pow((Xn / 2), count);
                            x = x + h;
                        }
                        Console.WriteLine("При Xn = {0},  Yx = {1}, Sx = {2}", Math.Round(Xn, 3), Math.Round((Lab1.FunctionOfYAndS(Xn, Xk, Yx, Sx)), 5), Math.Round(Sx, 5));
                        Sx = 0;
                        Xn = Xn + h;
                    }
                    break;
                case 14:
                    Random rand = new Random(System.DateTime.Now.Millisecond);
                    int i;
                    Console.Clear();
                    Console.WriteLine("Задание: Отрицательные элементы массива перенести в начало, сохраняя исходное взаимное расположение");
                    Console.Write("Введите размерность массива: ");
                    int size = Convert.ToInt32(Console.ReadLine()); ;
                    Console.WriteLine("size = " + size);
                    int[] mas = new int[size];
                    for (i = 0; i < size; i++)
                    {
                        mas[i] = rand.Next() % 30 - 15;
                        Console.Write(mas[i] + " ");
                    }
                    Console.Write(Environment.NewLine);
                    Lab1.Array(size, mas);
                    Console.WriteLine();
                    Console.ReadKey();
                    break;
                default:
                    Console.WriteLine("Неправильный ввод номера задания");
                    break;
            }
        }
    }
}