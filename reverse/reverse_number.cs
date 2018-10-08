using System;  
  
namespace ReverseNumber  
{
    public class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter a Number to reverse ?");
            int Number = int.Parse(Console.ReadLine());
            Console.WriteLine("Select method:\n\t1 - Vector\n\t2 - Math ");
            int op = int.Parse(Console.ReadLine());
            switch (op)
            {
                case 1:
                    Vector(Number);
                    break;
                case 2:
                    Math(Number);
                    break;
                default:
                    Console.WriteLine("Erro");
                    break;

            }
        }

        public static void Vector(int Number)
        {
            int Length = Number.ToString().Length;
            int[] Vector = new int[Length];
            foreach (char i in Number.ToString())
            {
                Vector[Length - 1] = int.Parse(i.ToString());
                Length--;
            }
            Console.Write("Reverse No. is ");
            for (int i = 0; i < Vector.Length; i++)
            {
                Console.Write(Vector[i].ToString());
            }
            Console.ReadLine();
        }
        public static void Math(int Number)
        {
            int Reverse = 0;
            while (Number > 0)
            {
                int remainder = Number % 10;
                Reverse = (Reverse * 10) + remainder;
                Number = Number / 10;
            }
            Console.WriteLine("Reverse No. is {0}", Reverse);
            Console.ReadLine();
        }
    }
}  
