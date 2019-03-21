
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassAndObjectDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            Sample S=new Sample(12,"abcd");
            S.display();
            int x;
            int sum = AddSum(1,z:2);
            Console.WriteLine(sum);


            //Method hiding
            //Employee F = new Employee();
            //FullTimeEmp F = new FullTimeEmp();
            Employee F = new FullTimeEmp();
            F.firstName = "jdbck";
            F.lastName = "lljnc";
            F.PrintFullName();

            ChildClass C = new ChildClass();
            PropertyDemo P = new PropertyDemo();
            P.Name = "bvrit";
            Console.WriteLine(P.Name);
            P.Len = -  21;
            Console.WriteLine(P.Len);

            Console.ReadLine();

        }

        public static int AddSum(int x, int y=0,int z=0)
        {
            //sum = x + x + y;
            return x + y;
        }

        //public static int AddSum(int x, int y, params int[] valueSet)
        //{
        //    if (valueSet != null)
        //    {

        //    }
        //    return x + y;
        //}


    }
    public class Sample
    {
        int sid;
        string name;
        public Sample(int sid,string name)
        {
            this.sid = sid;
            this.name = name;
        }
        public void display()
        {
            Console.WriteLine(sid);
            Console.WriteLine(name);
        }

    }

    
    // method hidinng
    public class Employee
    {
        public string firstName, lastName, email;
        virtual public void PrintFullName()
        {
          
            Console.WriteLine("base firstNAme={0} lastname={1}",firstName, lastName);
        }
    }
    public class FullTimeEmp : Employee
    {
        public float salary;
        public override void PrintFullName()
        {
            Console.WriteLine("firstNAme={0} lastname={1}", firstName, lastName);
        }
    }

    //constructor chaining
    public class ParentClass
    {

        public ParentClass(string s)
        {
            Console.WriteLine("Parent constructor called");
        }
        public ParentClass()
        {
            Console.WriteLine("Parent constructor called");
        }
    }
    public class ChildClass : ParentClass
    {
        public ChildClass() : base("Called from derive class")
        {
            Console.WriteLine("Child constructor called");
        }
    }

    //Properties
    public class PropertyDemo
    {
        private string name;
        private int len;
       
        public string Name
        {
            get
            {
                return name;
            }
            set
            {
                name = value;
            }
        }
        public int Len
        {
            get
            {
                return len;
            }
            set
            {
                if (value < 1)
                    Console.WriteLine("Age cannot be nagative");
                else
                    len = value;
            }
        }
    }
}
