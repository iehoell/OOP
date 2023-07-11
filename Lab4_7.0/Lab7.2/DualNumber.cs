using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab7._2
{
    public class Vector
    {   
        // interface
        private double a;
        private double b;

        //count vector components constructor
        public Vector(double Vector1, double Vector2)
        {
            this.a = Vector1;
            this.b = Vector2;
        }
        // get the components of vector
        public double GetA()
        {
            return this.a;
        }
        public double GetB()
        {
            return this.b;
        }
        // methods

        //copy constructor
        public Vector CopyVector(Vector other)
        {
            this.a = other.GetA();
            this.b = other.GetB();
            return this;
        }
        public double Mod() 
        {
            double vectorLength;
            vectorLength = Math.Sqrt(Math.Pow(this.a, 2) + Math.Pow(this.b, 2));
            return vectorLength;
        }
        // overloads
           // overloads +
        public static Vector operator + (Vector left, Vector right)
        {
            left.a += right.a;
            left.b += right.b;
            return left;
        }
        public static Vector operator +(Vector left, double right)
        {
            left.a += right;
            left.b += right;
            return left;
        }
            // overloads -
        public static Vector operator - (Vector left, Vector right) 
        {
            left.a -= right.a;
            left.b -= right.b;
            return left;
        }
        public static Vector operator -(Vector left, double right)
        {
            left.a -= right;
            left.b -= right;
            return left;
        }
            // overloads *
        public static double operator * (Vector left, Vector right)
        {
            double scalar;
            scalar = ((left.a * right.a) + (left.b + right.b)) * ((left.a * right.a + left.b * right.b) / (left.Mod() * right.Mod()));
            left.a = left.a * right.a;
            left.b = left.b * right.b;
            return scalar;
        }
        public static double operator *(Vector left, double right)
        {
            double scalar;
            scalar = ((left.a * right) + (left.b + right)) * Math.Cos((left.a * right + left.b * right) / (left.Mod() * right));
            left.a = left.a * right;
            left.b = left.b * right;
            return scalar;
        }
            //overloads /
        public static Vector operator /(Vector left, Vector right)
        {
            left.a = left.a / right.a;
            left.b = left.b / right.b;
            return left;
        }
        public static Vector operator / (Vector left, double right)
        {
            left.a = left.a / right;
            left.b = left.b / right;
            return left;
        }
        // overload ToString
        public override String ToString()
        {
            return $"({this.a.ToString()} , {this.b.ToString()})";
        }
    }
}
