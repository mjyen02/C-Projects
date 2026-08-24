using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ECE2310_Final_Project
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Pool[] pools = new Pool[7];
            Location[] locations = new Location[7];
            ArrayList poolList = new ArrayList();
            Random randomTemp = new Random();

            locations[0] = new Location(4, 8);
            locations[1] = new Location(1, 3);
            locations[2] = new Location(4, 2);
            locations[3] = new Location(13, 1);
            locations[4] = new Location(12, 9);
            locations[5] = new Location(10, 5);
            locations[6] = new Location(6, 6);

            for (int i = 0; i < 7; i++)
            {
                pools[i] = new Pool(locations[i], (i + 1).ToString());
                Console.WriteLine();
                poolList.Add(pools[i]);
            }

            Location start = new Location(0, 0);
            Console.WriteLine("From (0,0) >>");

            while (poolList.Count > 0)
            {
                Pool selectedPool = null;
                double dist = double.MaxValue;

                foreach (Pool i in poolList)
                {
                    if (i.PoolLocation.findDistance(start) < dist)
                    {
                        dist = i.PoolLocation.findDistance(start);
                        selectedPool = i;
                    }
                }

                selectedPool.changeTemperature();

                Console.WriteLine("The Maintenance Team goes to: " + selectedPool + " >> ");
                start = selectedPool.PoolLocation;
                poolList.Remove(selectedPool);
            }

            Console.WriteLine();

            for (int i = 0; i < 7; i++)
            {
                Console.WriteLine(pools[i].ToString());
            }
        }
    }
}
