using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassLibrary2_modifiers
{
    public partial class PartialClassDemo
    {
        public void printPartial()
        {
            Console.WriteLine(id.ToString());
        }
        partial void method()
        {
            Console.WriteLine("hello");
        }
    }
}
