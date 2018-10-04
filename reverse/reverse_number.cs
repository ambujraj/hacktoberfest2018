using System;  
  
namespace ReverseNumber  
{  
    class Program  
    {  
        static void Main(string[] args)  
        {  
            Console.WriteLine("Enter a Number to reverse ?");  
            int Number = int.Parse(Console.ReadLine());  
            int Reverse = 0;  
            while(Number>0)  
            {  
                int remainder = Number % 10;  
                Reverse = (Reverse * 10) + remainder;  
                Number = Number / 10;  
            }  
            Console.WriteLine("Reverse No. is {0}",Reverse);  
            Console.ReadLine();  
        }  
    }  
}  
