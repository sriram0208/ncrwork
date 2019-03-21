using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DotNetDemoClass1
{
    class Program
    {
       
        static void Main(string[] args)
        {
            Console.WriteLine("DotNet first class");
            ClassLibrary1.Class1.printToConsole();
            
            System.Int32 a = 10;
            Console.WriteLine(a);

            Console.WriteLine(int.MaxValue);
            Console.WriteLine(int.MinValue);
            int? ni = null;
            int [] arr = new int[5];
            for(int i = 0; i < 5; i++)
            {
                arr[i] = i+1;
            }
            foreach(var val in arr)
            {
                Console.WriteLine(val);
            }

            List<int> li = new List<int>();
            li.Add(9);
            li.Add(8);

            //21-03

            float f=5;
            int b = 10;
            f = b;
            b =(int) f;
            Console.WriteLine(f);
            Console.Read();
        }

        private void sample()
        {
            Console.WriteLine("DotNet first class in method");
        }
    }
}
