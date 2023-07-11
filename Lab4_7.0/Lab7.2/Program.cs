using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using Lab7._2;
public class main
{
    public static void Main()
    {
        //count vector components constructor
        Vector firstVector = new Vector(3, 4);
        Vector secondVector = new Vector(5, 6);
        Vector thirdVector = new Vector(0, 0);

        //copy constructor
        thirdVector.CopyVector(secondVector);
        Console.WriteLine("An object of class DualNum was created with parameters: a = 0, b = 0\n" +
            "when copying it from an object with parameters 5 and 6, we got:\n" +
            $"thirdVector = {thirdVector.ToString()}\n");
        //Mod()
        Console.WriteLine("third vector length is " + thirdVector.Mod());

        //mathenatical overloads
        Console.WriteLine("Addition of objects 3 and 2:\n" +
            $"{thirdVector.ToString()} + {secondVector.ToString()} = {thirdVector + secondVector}\n");
        Console.WriteLine("Objects difference:\n" +
            $"{firstVector.ToString()} - 5 = {firstVector - 5}\n");
        Console.WriteLine("Objects division 3 / 1:\n" +
             $"{thirdVector.ToString()} / {secondVector.ToString()} = {thirdVector / secondVector}\n");
        Console.WriteLine("Objects scalar multiplication 1 and 3:\n" +
            $"{firstVector.ToString()} * {thirdVector.ToString()} = {firstVector * thirdVector}\n");
    }
}