using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using LAB_3_3_LIB;

namespace SaveLoadLib
{
    public class SaveLoad
    {
        static void Save(List<ItemInfo> FlyingObjects)
        {
            FileStream file = new FileStream(Environment.CurrentDirectory + "\\save.txt", FileMode.Create);
            StreamWriter stream = new StreamWriter(Environment.CurrentDirectory + "\\save.txt");
            for (int i = 0; i < FlyingObjects.Count; i++)
            {
                stream.Write($"{FlyingObjects[i].get_name_of_item()}\n");
                stream.Write($"{FlyingObjects[i].get_speed_in_ms()}\n");
                stream.Write($"{FlyingObjects[i].get_length_in_metres()}\n");
            }
        }
        static int Load(List<ItemInfo> Items)
        {
            if (File.Exists(Environment.CurrentDirectory + "\\save.txt"))
            {
                StreamReader stream = new StreamReader(Environment.CurrentDirectory + "\\save.txt");
                string name = "";
                double speed;
                double length;
                double units;
                while (!stream.EndOfStream)
                {
                    name = stream.ReadLine();
                    speed = Convert.ToDouble(stream.ReadLine());
                    length = Convert.ToDouble(stream.ReadLine());
                    units = length / speed;
                    Items.Add(new ItemInfo(name, speed, length, units));
                }
                return 0;
            }
            else
            {
                return 1;
            }
        }
    }
}