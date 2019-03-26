using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InterfaceDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            
            //typecase to the interface
            InterfaceDemo.Demo dm = new InterfaceDemo.Demo();
            ((InterfaceDemo.ICustomer)dm).print();
            
        }
    }

    interface ICustomer
    {
        void print();
    }
    interface ICustomer1
    {
        void print();
    }
    public  class Demo : ICustomer, ICustomer1
    {
        void ICustomer.print()
        {
            Console.WriteLine("Interface1 demo");
        }
        void ICustomer1.print()
        {
            Console.WriteLine("Interface2 demo");
        }
    }
}
