using System;

namespace Factorial
{
    public static class Squareable
    {
        public static bool IsSqrt(double x)
        {
            if(x <= 0)
                return false;

            if (Math.Round(Math.Sqrt(x)) == Math.Sqrt(x))
                return true;
            return false;
        }
    }
}
