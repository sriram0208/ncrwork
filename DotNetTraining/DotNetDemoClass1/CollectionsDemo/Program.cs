using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CollectionsDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            Customer cust1 = new Customer { ID = 1, Name = "shanker" };
            Customer cust2 = new Customer { ID = 2,Name= "vijay" };
            Customer cust3 = new Customer { ID = 3, Name = "dhawan" };

            Dictionary<int, Customer> values = new Dictionary<int, Customer>();
            values.Add(cust1.ID, cust1);
            values.Add(cust2.ID, cust2);
            values.Add(cust3.ID, cust3);

            foreach(KeyValuePair<int,Customer> value in values)
            {
                Console.WriteLine("Customer ID--{0}--Customer Name--{1}", value.Key, value.Value);
            }
        }
    }


    class Customer
    {
        public int ID;
        public string Name;
    }

    
}
