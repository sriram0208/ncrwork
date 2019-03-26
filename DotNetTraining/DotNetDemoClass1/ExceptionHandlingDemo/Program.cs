using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExceptionHandlingDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            ExceptionSample.readNumber();
        } 


        class ExceptionSample
        {
            public static void readNumber()
            {
                try
                {
                    Console.WriteLine("Enter first number : ");
                    string a = Console.ReadLine();

                    Console.WriteLine("Enter second number : ");
                    string b = Console.ReadLine();

                    int c = Convert.ToInt32(a) / Convert.ToInt32(b);
                    //int num;
                    //if(int.TryParse(a, out num))
                    //{

                    //}

                    Console.WriteLine(c.ToString());
                }

                catch (FormatException ex)
                {
                    Console.WriteLine(ex.Message);
                    throw new Exception("inner exception", ex);
                }
                catch (DivideByZeroException ex)
                {
                    Console.WriteLine(ex.Message);
                    throw new Exception("inner exception", ex);
                }
                catch (OverflowException ex)
                {
                    Console.WriteLine(ex.Message);
                    throw new Exception("inner exception", ex);
                }

            }
            

        }

    }
}
