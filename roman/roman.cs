using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Roman_Nummeral_Program
    {
        public static Dictionary<char, int> numerals = new Dictionary<char, int> { { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 } };
        static void Main(string[] args)
        {
            // The code provided will print ‘Hello World’ to the console.
            // Press Ctrl+F5 (or go to Debug > Start Without Debugging) to run your app.
            Console.WriteLine("Welcome to the one and only Roman Numeral Reader! Type in your query below. (We now support addition OR subtraction)\n");
            var input = Console.ReadLine();
            string[] math;
            int answer = 0;
            if (input.Contains("+"))
            {
                math=input.Split('+');
                for (int i = 0; i < math.Length; i++)
                {
                    answer = answer + RomanNumeralReader(math[i]);
                }
            } else if (input.Contains('-'))
                 
            {
                math = input.Split('-');
                for (int i = 0; i < math.Length; i++)
                {
                    answer = answer + RomanNumeralReader(math[i]);
                }
            }
            else
            {
                answer=RomanNumeralReader(input);
            }
            Console.WriteLine("\nThe answer is " + answer);
            Console.ReadKey();

        }

    

        public static int RomanNumeralReader(string s)
        {
           
            char[] chars = s.ToCharArray();
            int answer = numerals[chars[0]];
            for (int i = 1; i < chars.Length; i++)
            {
                if (numerals[chars[i - 1]] < numerals[chars[i]]){
                    answer = answer + numerals[chars[i]] - numerals[chars[i - 1]];
                }
                else
                {
                    answer = answer + numerals[chars[i]];
                }
                
            }
            return answer;
        }
    }
}
