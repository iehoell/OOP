using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using classB;

namespace Lab7._0
{
    public class Lab7_1
    {
        public static void Main()
        {
            Bclass firstPerson = new Bclass(21, "First person");
            Bclass secondPerson = new Bclass(20, "Second person");
            Bclass youngerPerson = firstPerson <= secondPerson ? firstPerson : secondPerson;

            if (youngerPerson)
            {
                Console.WriteLine("No name: " + youngerPerson.isName());
            } 
            else
            {
                Console.WriteLine("No name: " + youngerPerson.isName());
            }
            if (firstPerson == secondPerson)
            {
                Console.WriteLine("Both person are one age");
            }
            else
            {
                youngerPerson += " is younger";
                Console.WriteLine(youngerPerson.getName());
                Console.WriteLine("His age in months is " + (youngerPerson * 12));
            }
        }
    }
}
