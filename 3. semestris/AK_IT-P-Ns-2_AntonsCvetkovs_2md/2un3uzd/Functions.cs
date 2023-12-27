using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2un3uzd
{
    internal class Functions
    {
        public static double quadratic(double a, double b, double c, double x) { return Math.Pow(a * x, 2) + b * x + c; }

        public static double rational1(double a, double b, double c, double x) { return Math.Pow(a / x, 2) + b / x + c; }

        public static double rational2(double a, double b, double c, double x) { return (a * x + b) / (a * x + c); }
    }
}
