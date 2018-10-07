using System;

namespace NumberReverse
{
    class ReverseNumber
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter a Number");
            string input = Console.ReadLine().Trim();
            int N = int.Parse(input);
            Reverse(N);
        }

        static void Reverse(int N)
        {
            int num = N;
            int rev = 0;

            while (num > 0)
            {
                int remainder = num % 10;
                rev = (rev * 10) + remainder;
                num = num / 10;
            }

            Console.WriteLine("The Number is:" + N);
            Console.WriteLine("The Reverse of the number is:" + rev);
            Console.Read();
        }
    }
}
