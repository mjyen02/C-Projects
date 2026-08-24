using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ECE2310_Final_Project
{
    internal class Pool
    {
        private static Random randomTempValue = new Random();
        private Temperature temp;
        private Location poolLocation;
        private static int count = 0;
        private string poolID;
        
        public Pool()
        {
            Console.WriteLine("There are: {0} Pools", count);
            temp = new Temperature(randomTempValue.Next(98,105));
            poolLocation = new Location(0,0);
            count++;
            Console.WriteLine("A New Pool was Created, there are: {0} pools", count);
        }

        public Pool(int x, int y, string ID)
        {
            Console.WriteLine("There are: {0} Pools", count);
            temp = new Temperature(randomTempValue.Next(98, 105));
            poolLocation = new Location(x, y);
            poolID = ID;
            count++;
            Console.WriteLine("A New Pool was Created, there are: {0} pools", count);
            Console.WriteLine("Pool {4} is at x: {0} y: {1} set at {2} {3}", poolLocation.X, poolLocation.Y, temp.Degree, temp.Scale, poolID);
        }

        public Pool(Location location, string ID)
        {
            Console.WriteLine("There are: {0} Pools", count);
            temp = new Temperature(randomTempValue.Next(98, 105));
            poolLocation = location;
            poolID = ID;
            count++;
            Console.WriteLine("A New Pool was Created, there are: {0} pools", count);
            Console.WriteLine("Pool {4} is at x: {0} y: {1} set at {2} {3}", poolLocation.X, poolLocation.Y, temp.Degree, temp.Scale, poolID);
        }

        public Random RandomTempValue
        {
            get { return randomTempValue; }
            set { randomTempValue = value; }
        }

        public Temperature Temp
        {
            get { return temp; }
            set { temp = value; }
        }

        public Location PoolLocation
        {
            get { return poolLocation; }
            set { poolLocation = value; }
        }

        public void changeTemperature()
        {
            temp = new Temperature(randomTempValue.Next(98,105));
        }

        public override string ToString()
        {
            return "Pool " + poolID + " at x: " + poolLocation.X + " y: " + poolLocation.Y + " set to " + temp.Degree + " " + temp.Scale; 
        }

        ~Pool() { }
    }
}
