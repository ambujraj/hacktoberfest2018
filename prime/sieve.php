<?php

function sieve($size)
{
    $primes = array();
    if ($size < 2)
    {
        return $primes;
    }
    else
    {
        while (count($primes) <= $size)
        {
            array_push($primes, count($primes));
        }
        for ($i = 2;$i < count($primes);$i++)
        {
            $temp = count($primes) - 1;

            while ($temp > $i)
            {
                if ($temp % $i == 0)
                {
                    $primes[$temp] = NULL;
                }
                $temp--;
            }
        }
        return (array_values(array_filter(array_slice($primes, 2))));
    }
}
