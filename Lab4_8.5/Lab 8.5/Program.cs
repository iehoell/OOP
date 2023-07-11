using System;
using System.Collections.Generic;
using ReloadOper1;

namespace ReloadOper1
{
    class MyEventReceiver
    {
        public void EventMistakeHandler()
        {
            Console.WriteLine("Событие: допущена ошибка при вводе!!!");
        }
        public void EventWarningHandler()
        {
            Console.WriteLine("Событие: подозрительно большое значение!!!");
        }
    }
    public class Vector
    {
        public delegate void MyEventHandler();

        public event MyEventHandler OnSomeMistakeEvent;
        public void SomeMistakeEvent()
        {
            if (OnSomeMistakeEvent != null)
            {
                OnSomeMistakeEvent();
            }
        }
        public event MyEventHandler OnSomeWarningEvent;
        public void SomeWarningEvent()
        {
            if (OnSomeWarningEvent != null)
            {
                OnSomeWarningEvent();
            }
        }

        private double a;
        private double b;
        public double A
        {
            get { return a; }
            set
            {
                if (value > 100)
                    SomeWarningEvent();  //Зажигание события "a не м.б. отрицательным!"
                else
                    a = value;
            }
        }
        public double B
        {
            get { return b; }
            set
            {
                if (value > 100)
                    SomeWarningEvent();  //Зажигание события "b не м.б. отрицательным!"
                else
                    b = value;
            }
        }

        public int Chose
        {
            get { return Chose; }
            set
            {
                if (value > 9 && value < 1)
                    SomeMistakeEvent();  //Зажигание события 
                else
                    b = value;
            }
        }
        public Vector(double inputa, double inputb)
        {
            a = inputa; b = inputb;
        }
        public Vector(Vector item)
        {
            a = item.a; b = item.b;
        }
        public Vector()
        {

        }
        public double[] Re()
        {
            double[] real_part = new double[2];
            real_part[0] = a; real_part[1] = b;
            return real_part;
        }
        public string vector()
        {
            return $"({a}, {b})";
        }
        public string ToString(Vector objec)
        {
            return objec.vector();
        }
        public string ToString(Vector objec, string inputString)
        {
            return inputString + objec.vector();
        }
        public static string operator +(Vector objeca, Vector objecb)
        {
            return $"({objeca.a + objecb.a} , {objeca.b + objecb.b})";
        }
        public static string operator +(Vector objeca, double inputNumber)
        {
            return $"({objeca.a + inputNumber} , {objeca.b + inputNumber})";
        }
        public static string operator -(Vector objeca, Vector objecb)
        {
            return $"({objeca.a - objecb.a} , {objeca.b - objecb.b})";
        }
        public static string operator -(Vector objeca, double inputNumber)
        {
            return $"({objeca.a - inputNumber} , {objeca.b - inputNumber})";
        }
        public static string operator *(Vector objeca, Vector objecb)
        {
            double a = (objeca.a * objecb.a);
            double b = (objeca.b * objecb.b);

            return $"({a} , {b})";

        }
        public static string operator *(Vector objeca, double inputNumber)
        {
            return $"({objeca.a * inputNumber} , {objeca.b * inputNumber})";
        }
    }
}
class Program
{
    static void Main()
    {
        Vector Sender = new Vector();
        MyEventReceiver Receiver = new MyEventReceiver();
        Sender.OnSomeMistakeEvent += Receiver.EventMistakeHandler;
        Sender.OnSomeWarningEvent += Receiver.EventWarningHandler;
        int flagOfExit = 1, inputChoce = 0;
        int firstElem = -1, secondElem = -1;
        List<Vector> vectors = new List<Vector>();
        while (flagOfExit == 1)
        {
            double BiggestValueOfvectors = 0;
            Console.Write("\n-------------------------------------------------------");
            if (vectors.Count != 0)
            {
                for (int i = 0; i < vectors.Count; i++)
                {
                    Console.Write($"\n[{i}]" + $"\t{vectors[i].vector()}");
                    double[] realNumberOfvectors = vectors[i].Re();
                    for (int realNumbers = 0; realNumbers < 2; realNumbers++)
                    {
                        if (BiggestValueOfvectors < realNumberOfvectors[realNumbers]) { BiggestValueOfvectors = realNumberOfvectors[realNumbers]; }
                    }
                }
            }
            else
            {
                Console.Write("\nпока список пуст");
            }
            Console.Write("\n-------------------------------------------------------\n");
            //if (BiggestValueOfvectors > 100)
            //{
            Sender.A = BiggestValueOfvectors;
            //Sender.SomeWarningEvent();
            //}
            Console.WriteLine("меню:");
            Console.WriteLine("1 - создать новый элемент");
            Console.WriteLine("2 - скопировать элемент");
            Console.WriteLine("3 - сумма двух векторов");
            Console.WriteLine("4 - разность двух векторов");
            Console.WriteLine("5 - произведение двух векторов");
            Console.WriteLine("6 - сумма вектора и числа");
            Console.WriteLine("7 - разность вектора и числа");
            Console.WriteLine("8 - произведение вектора и числа");
            Console.WriteLine("9 - выход");
            //while (inputChoce < 1 || inputChoce > 9)
            //{
            try
            {
                inputChoce = Convert.ToInt32(Console.ReadLine());
            }
            catch
            {
                Sender.Chose = inputChoce;
                //Console.WriteLine("неправильно введено значение, попробуйте еще раз!!!");
            }

            //}
            switch (inputChoce)
            {
                case 1:
                    vectors.Add(createNewObject());
                    break;
                case 2:
                    while (firstElem < 0 || firstElem > vectors.Count)
                    {
                        try
                        {
                            Console.Write("\nвыберите первый элемент - ");
                            firstElem = Convert.ToInt32(Console.ReadLine());
                        }
                        catch
                        {
                            Sender.SomeMistakeEvent();
                            Console.Write("\nнеправильно введен номер элемента!!!");
                            Console.ReadLine();
                        }
                    }
                    vectors.Add(new Vector(vectors[firstElem]));
                    firstElem = -1;
                    break;
                case 3:
                    while ((firstElem < 0 || firstElem > vectors.Count) || (secondElem < 0 || secondElem > vectors.Count))
                    {
                        try
                        {
                            Console.Write("\nвыберите первый элемент - ");
                            firstElem = Convert.ToInt32(Console.ReadLine());
                            Console.Write("\nвыберете второй элемент - ");
                            secondElem = Convert.ToInt32(Console.ReadLine());
                        }
                        catch
                        {
                            Sender.SomeMistakeEvent();
                            Console.Write("\nнеправильно введен номер элемента!!!");
                            Console.ReadLine();
                        }
                    }
                    Console.Write($"\nсумма векторов = {vectors[firstElem] + vectors[secondElem]}");
                    Console.ReadLine();
                    firstElem = -1; secondElem = -1;
                    break;
                case 4:
                    while ((firstElem < 0 || firstElem > vectors.Count) || (secondElem < 0 || secondElem > vectors.Count))
                    {
                        try
                        {
                            Console.Write("\nвыберите первый элемент - ");
                            firstElem = Convert.ToInt32(Console.ReadLine());
                            Console.Write("\nвыберете второй элемент - ");
                            secondElem = Convert.ToInt32(Console.ReadLine());
                        }
                        catch
                        {
                            Sender.SomeMistakeEvent();
                            Console.Write("\nнеправильно введен номер элемента!!!");
                            Console.ReadLine();
                        }
                    }
                    Console.Write($"\nразность векторов = {vectors[firstElem] - vectors[secondElem]}");
                    Console.ReadLine();
                    firstElem = -1; secondElem = -1;
                    break;
                case 5:
                    while ((firstElem < 0 || firstElem > vectors.Count) || (secondElem < 0 || secondElem > vectors.Count))
                    {
                        try
                        {
                            Console.Write("\nвыберите первый элемент - ");
                            firstElem = Convert.ToInt32(Console.ReadLine());
                            Console.Write("\nвыберете второй элемент - ");
                            secondElem = Convert.ToInt32(Console.ReadLine());
                        }
                        catch
                        {
                            Sender.SomeMistakeEvent();
                            Console.Write("\nнеправильно введен номер элемента!!!");
                            Console.ReadLine();
                        }
                    }
                    Console.Write($"\nпроизведение векторов = {vectors[firstElem] * vectors[secondElem]}");
                    Console.ReadLine();
                    firstElem = -1; secondElem = -1;
                    break;
                case 6:
                    while ((firstElem < 0 || firstElem > vectors.Count))
                    {
                        try
                        {
                            Console.Write("\nвыберите элемент - ");
                            firstElem = Convert.ToInt32(Console.ReadLine());
                            Console.Write("\nвведите число - ");
                            secondElem = Convert.ToInt32(Console.ReadLine());
                        }
                        catch
                        {
                            Sender.SomeMistakeEvent();
                            Console.Write("\nнеправильно введен номер элемента или число!!!");
                            Console.ReadLine();
                        }
                    }
                    Console.Write($"\nсумма вектора и числа = {vectors[firstElem] + secondElem}");
                    Console.ReadLine();
                    firstElem = -1; secondElem = -1;
                    break;
                case 7:
                    while ((firstElem < 0 || firstElem > vectors.Count))
                    {
                        try
                        {
                            Console.Write("\nвыберите элемент - ");
                            firstElem = Convert.ToInt32(Console.ReadLine());
                            Console.Write("\nвведите число - ");
                            secondElem = Convert.ToInt32(Console.ReadLine());
                        }
                        catch
                        {
                            Sender.SomeMistakeEvent();
                            Console.Write("\nнеправильно введен номер элемента или число!!!");
                            Console.ReadLine();
                        }
                    }
                    Console.Write($"\nразность вектора и числа = {vectors[firstElem] - secondElem}");
                    Console.ReadLine();
                    firstElem = -1; secondElem = -1;
                    break;
                case 8:
                    while ((firstElem < 0 || firstElem > vectors.Count))
                    {
                        try
                        {
                            Console.Write("\nвыберите элемент - ");
                            firstElem = Convert.ToInt32(Console.ReadLine());
                            Console.Write("\nвведите число - ");
                            secondElem = Convert.ToInt32(Console.ReadLine());
                        }
                        catch
                        {
                            Sender.SomeMistakeEvent();
                            Console.Write("\nнеправильно введен номер элемента или число!!!");
                            Console.ReadLine();
                        }
                    }
                    Console.Write($"\nпроизведеие вектора и числа = {vectors[firstElem] * secondElem}");
                    Console.ReadLine();
                    firstElem = -1; secondElem = -1;
                    break;
                case 9:
                    Environment.Exit(0);
                    break;
            }
            inputChoce = 0;
            Console.Clear();
        }
    }
    public static Vector createNewObject()
    {
        double a = 0, b = 0;
        try
        {
            Console.Write("\nвведите a - ");
            a = Convert.ToDouble(Console.ReadLine());
        }
        catch
        {
            Console.Write("\nнекорректно введено значение");
        }
        try
        {
            Console.Write("\nвведите b - ");
            b = Convert.ToDouble(Console.ReadLine());
        }
        catch
        {
            Console.Write("\nнекорректно введено значение");
        }
        Vector Ob = new Vector(a, b);
        return Ob;
    }
}
