
sqrtInt :: Int -> Int
sqrtInt x = sqrtInt' x 0 x
         where sqrtInt' :: Int -> Int -> Int -> Int
               sqrtInt' x low high
                   | low >= high    = low
                   | middSq < x  = sqrtInt' x (midd+1) high
                   | middSq > x  = sqrtInt' x (low) (midd-1)
                   | middSq == x = midd
                 where midd   = (high + low) `quot` 2
                       middSq = midd*midd
                                            
