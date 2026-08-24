using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ECE2310_Final_Project
{
    internal class Temperature
    {
        private double degree;
        private string scale;

        public Temperature()
        {
            degree = 100;
            scale = "Fahrenheit";
        }

        public Temperature(double temp)
        {
            degree = temp;
            scale = "Fahrenheit";
        }

        public Temperature(string scaleType)
        {
            degree = 100;
            scale = scaleType;
        }

        public Temperature (double temp, string scaleType)
        {
            degree = temp;
            scale = scaleType;
        }

        public double Degree
        {
            get { return degree; }
            set { degree = value; }
        }

        public string Scale
        {
            get { return scale; }
            set { scale = value; }
        }

        public override string ToString()
        {
            return "The pool is " + degree + " degrees " + scale;
        }
    }
}
