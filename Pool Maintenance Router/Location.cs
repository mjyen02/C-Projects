using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ECE2310_Final_Project
{
    internal class Location
    {
        private int x;
        private int y;

        public Location()
        {
            x = 0;
            y = 0;
        }

        public Location(int xVal)
        {
            x = xVal;
            y = 0;
        }

        public Location(int xVal, int yVal)
        {
            x = xVal;
            y = yVal;
        }

        public int X
        {
            get { return x; }
            set { x = value; }
        }

        public int Y
        {
            get { return y; }
            set { y = value; }
        }

        public override string ToString()
        {
            return "Pool "+ "is located at " + x.ToString() + ", " + y.ToString();
        }

        public double findDistance(Location location2)
        {
            double distance = Math.Round(Math.Sqrt(Math.Pow(location2.X - x, 2) + Math.Pow(location2.Y - y, 2)));
            return distance;
        }

        ~Location() { }
    }
}
