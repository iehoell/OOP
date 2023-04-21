using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LAB_3_3_LIB
{
    internal class ItemInfo
    {
        private string name_of_item = "";
        private double speed_in_ms;
        private double length_in_metres;
        private double relative_units;

        public ItemInfo(string name, double speed, double length, double units)
        {
            name_of_item = name;
            speed_in_ms = speed;
            length_in_metres = length;
            relative_units = units;
        }
        public double item_length
        {
            get { return length_in_metres; }
            set { length_in_metres = value; }
        }
        public string get_name_of_item()
        {
            return name_of_item;
        }
        public double get_speed_in_ms()
        {
            return speed_in_ms;
        }
        public double get_length_in_metres()
        {
            return length_in_metres;
        }
        public double get_speed_in_relative_units()
        {
            return (speed_in_ms / length_in_metres);
        }
    }
}
