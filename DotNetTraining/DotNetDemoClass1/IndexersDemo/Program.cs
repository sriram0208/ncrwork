using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IndexersDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            IndexerSample s= new IndexerSample();
            Console.WriteLine(s[2]);
            Console.ReadLine();

        }


        public class Employee{
            public int id;
            public string name;
        }
        public class IndexerSample
        {
            List<Employee> list = new List<Employee>();
            public IndexerSample()
            {
                list.Add(new Employee { id = 1, name = "sai kiran" });
                list.Add(new Employee { id = 2, name = "sumesh" });

            }
            public string this[int id]
            {
                get
                {
                    return list.FirstOrDefault(emp => emp.id == id).name;
                }
                set
                {
                    list.FirstOrDefault(emp => emp.id == id).name = value;
                }
            }
        }
    }
}
