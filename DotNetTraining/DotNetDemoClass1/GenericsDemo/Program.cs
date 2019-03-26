using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GenericsDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            int a=0, b=1;

            if (Calculator.Compare<int>(a, b))
                Console.WriteLine("Equal");
            else
                Console.WriteLine("Not Equal");

            Console.ReadLine();
        }
    }
    public class Calculator
    {
        public static bool Compare<T>(T x,T y)
        {
           
            return x.Equals(y);
        }
    }
}
