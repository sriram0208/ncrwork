using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassLibrary2_modifiers
{
    public partial class PartialClassDemo
    {
        private int id;
        private string name;
        partial void method();
        public void print()
        {
            method();
        }
    }

}
