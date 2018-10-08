using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    public class gg
    {
        static void Main(string[] args)
        {
            Random Random = new Random();
            int RandomNumber = Random.Next(0, 11);

            int Number = 0;

            for (int i = 0; i<5; i++)
            {
                Console.WriteLine("\nIntroduce a number between 1 and 10");
                Number = int.Parse(Console.ReadLine());

                if (Number == RandomNumber)
                {
                    Console.WriteLine("\nYou Win");
                    break;
                }
                else if (Number < RandomNumber)
                    Console.WriteLine("\nToo Low");
                else
                    Console.WriteLine("\nToo Big");
            }

            if (Number != RandomNumber)
                Console.WriteLine("\nYou Lost");
            Console.ReadLine();
        }

        
    }
}
