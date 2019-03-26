using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DelegateDemo
{
    class Program
    {
        public delegate void DelegateHelper(string s);
        static void Main(string[] args)
        {
            Console.Read();
        }
        public class Employee
        {
            public delegate bool PromoteDelegate(Employee emp);
            public int ID { get; set; }
            public string nName { get; set; }
            public int YearsInCurrentRole { get; set; }
        public static void Promotion(List<Employee> employee,PromoteDelegate promote)
        {
            foreach(Employee emp in employee){
                if (promoteDelegate(emp))
                {
                    Console.WriteLine("Name {0}-Promoted", employee.Name);
                }
            }
        } 
       
    }
}
