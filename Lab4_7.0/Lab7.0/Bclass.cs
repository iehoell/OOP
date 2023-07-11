using System.Runtime.CompilerServices;

namespace classB
{
    public class Bclass
    {
        private int age;
        private String name;
        private bool isWithoutName;

        public Bclass(int num, String name)
        {
            this.age = num;
            this.name = name;
        }
        public String getName()
        {
            return name.ToString();
        }
        public bool isName()
        {
            return isWithoutName;
        }
        public static bool operator true(Bclass x)
        {
            if (x.name.ToString() != "")
            {
                x.isWithoutName = false;
                return true;
            }
            x.isWithoutName = true;
            return false;
        }
        public static bool operator false(Bclass x)
        {
            if (x.name == "")
            {
                x.isWithoutName = false;
                return true;
            }
            x.isWithoutName= true;
            return false;
        }
        public static bool operator !=(Bclass x, Bclass y)
        {
            return x.age != y.age ? true : false;
        }
        public static bool operator ==(Bclass x, Bclass y)
        {
            return x.age == y.age ? true : false;
        }
        public static bool operator >=(Bclass x, Bclass y)
        {
            return x.age >= y.age ? true : false;
        }
        public static bool operator <=(Bclass x, Bclass y)
        {
            return x.age <= y.age ? true : false;
        }
        public static Bclass operator +(Bclass x, String name)
        {
            x.name += name;
            return x;
        }
        public static int operator -(Bclass x, int num)
        {
            x.age -= num;
            return x.age;
        }
        public static int operator *(Bclass x, int num)
        {
            x.age *= num;
            return x.age;
        }
    }
}



