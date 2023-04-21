using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LAB_3_3_LIB;
using SaveLoadLib;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            List<ItemInfo> FlyingObjects = new List<ItemInfo>();
            bool flag_of_exit = false;
            string name = "";
            double speed = 0, length = 0, units = 0;
            int choice;
            double max = 0.0;
            while (!flag_of_exit)
            {
                Console.Clear();
                Console.Write("  \tназвание\tскорость, м/с\tдлина, м\tскорость, ед2\n");
                Console.Write("-------------------------------------------------------------------------------------\n");
                if (FlyingObjects.Count != 0)
                {
                    for (int i = 0; i < FlyingObjects.Count; i++)
                    {
                        Console.ResetColor();
                        if (FlyingObjects[i].get_speed_in_relative_units() > max)
                        {
                            max = FlyingObjects[i].get_speed_in_relative_units();
                        }
                        if (FlyingObjects[i].get_speed_in_relative_units() == max)
                        {
                            Console.ForegroundColor = ConsoleColor.Green;
                        }
                        Console.Write("№" + $"{i + 1}");
                        Console.Write($"\t{FlyingObjects[i].get_name_of_item()}");
                        Console.Write($"\t\t{Convert.ToString(FlyingObjects[i].get_speed_in_ms())}");
                        Console.Write($"\t\t{Convert.ToString(FlyingObjects[i].get_length_in_metres())}");
                        Console.Write($"\t\t{Convert.ToString(Math.Round(FlyingObjects[i].get_speed_in_relative_units(), 2))}\n");
                        Console.ResetColor();
                    }
                }
                else { Console.WriteLine("пока справочник пуст"); }
                Console.Write("-------------------------------------------------------------------------------------\n");
                Console.WriteLine("1 - добавить пункт в справочник");
                Console.WriteLine("2 - удалить пункт из справочника");
                Console.WriteLine("3 - Сохранить");
                Console.WriteLine("4 - Загрузить");
                Console.WriteLine("5 - выход из программы");
                try
                {
                    Console.Write("выберите пункт - ");
                    choice = Convert.ToInt32(Console.ReadLine());
                    switch (choice)
                    {
                        case 1:
                            {
                                try
                                {
                                    Console.Write("\nвведите название - ");
                                    name = Console.ReadLine();
                                    Console.Write("\nвведите скорость в м/c - ");
                                    speed = Convert.ToDouble(Console.ReadLine());
                                    Console.Write("\nвведите длину в метрах - ");
                                    length = Convert.ToDouble(Console.ReadLine());
                                }
                                catch
                                {
                                    Console.WriteLine("некорректно введены значения");
                                    Console.WriteLine("нажмите любую клавишу");
                                    Console.ReadLine();
                                    break;
                                }
                                FlyingObjects.Add(new ItemInfo(name, speed, length, units));
                            }
                            break;
                        case 2:
                            {
                                Console.Write("введите номер элемента, который вы хотите удалить - ");
                                choice = Convert.ToInt32(Console.ReadLine());
                                if (choice <= 0 || choice > FlyingObjects.Count)
                                {
                                    Console.WriteLine("введено некорректное значение");
                                    Console.WriteLine("нажмите любую клавишу");
                                    Console.ReadLine();
                                }
                                else
                                {
                                    FlyingObjects.RemoveAt(choice - 1);
                                }
                            }
                            break;
                        case 3:
                            Save(FlyingObjects);
                            Console.WriteLine("нажмите любую клавишу");
                            Console.ReadLine();
                            break;
                        case 4:
                            Load(FlyingObjects);
                            Console.WriteLine("нажмите любую клавишу");
                            Console.ReadLine();
                            break;
                        case 5:
                            flag_of_exit = true;
                            break;
                    }
                }
                catch
                {
                    Console.WriteLine("некорректно введено значение");
                    continue;
                }
            }
        }

        static void Save(List<ItemInfo> FlyingObjects)
        {
            StreamWriter stream = new StreamWriter(Environment.CurrentDirectory + @"\save.txt");
            for (int i = 0; i < FlyingObjects.Count; i++)
            {
                stream.Write($"{FlyingObjects[i].get_name_of_item()}" + "\n");
                stream.Write($"{Convert.ToString(FlyingObjects[i].get_speed_in_ms())}" + "\n");
                stream.Write($"{Convert.ToString(FlyingObjects[i].get_length_in_metres())}" + "\n");
                stream.Write($"{Convert.ToString(FlyingObjects[i].get_speed_in_relative_units())}" + "\n");
            }
            stream.Close();
        }
        static int Load(List<ItemInfo> FlyingObjects)
        {
            if (File.Exists(Environment.CurrentDirectory + @"\save.txt"))
            {
                StreamReader stream = new StreamReader(Environment.CurrentDirectory + "\\save.txt");
                FlyingObjects.Clear();
                string name = "";
                double speed;
                double length;
                double units;
                while (!stream.EndOfStream)
                {
                    name = stream.ReadLine();
                    speed = Convert.ToDouble(stream.ReadLine());
                    length = Convert.ToDouble(stream.ReadLine());
                    units = Convert.ToDouble(stream.ReadLine());
                    FlyingObjects.Add(new ItemInfo(name, speed, length, units));
                }
                stream.Close();
                return 0;
            }
            else
            {
                return 1;
            }
        }
    }
}