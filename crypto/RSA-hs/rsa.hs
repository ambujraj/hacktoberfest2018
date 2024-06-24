module RSA where
  import Control.Monad.Fix
  import System.Random(randomRIO)
  import Data.Bits
  import System.Random
  
  -- plan b to generate random numbers
  -- randomNumber :: Integer -> Integer -> IO Integer
  -- randomNumber a b = (randomRIO(a,b))
  
  isPrime :: Integer -> Bool
  isPrime k = null [ x | x <- [2.. ceiling (sqrt (fromIntegral k))], k `mod`x  == 0]

  main :: Integer -> Integer -> Int -> Integer
  main x m k = let s1 = mkStdGen k
                   (i1, _) = randomR (x, m :: Integer) s1
                 in i1 
  
  getRandomPrime :: Integer -> Integer -> Int -> Integer
  getRandomPrime m n k = let x = main m n k
                             
                         in if isPrime x 
                            then x
                            else getRandomPrime m n (k+1) 
                   
  calculateTotient :: Integer -> Integer -> Int -> Integer
  calculateTotient m n k = let x = getRandomPrime m n k
                               y = getRandomPrime m n (k + 1003322)         
                           in if x /= y
                              then ((x - 1) * (y -1))
                              else calculateTotient m n (k*10)
  
  calculateN :: Integer -> Integer -> Int -> Integer
  calculateN m n k = let x = getRandomPrime m n k
                         y = getRandomPrime m n (k + 1003322)
                     in (x * y)        
  
  publicKey :: Integer -> Integer -> Int -> Integer -> Integer
  publicKey m n k e = let y = calculateTotient m n k
                      in if (gcd e y) == 1
                         then e    
                         else publicKey m n k (e + 1)
   
  privateKey :: Integer -> Integer -> Int -> Integer -> Integer
  privateKey m n k e = let x = calculateTotient m n k
                           y = fromIntegral(x * 2 + 1)`div`e
                       in  y   
    
  encrypt :: Integer -> (Integer, Integer) -> Integer
  encrypt m (e, n) = ((m^e) `mod` n)
  
  decript :: Integer -> (Integer, Integer) -> Integer
  decript c (d, n ) = (c^d `mod` n)
  
  rsaE :: Integer -> Int -> Integer -- main function to encript
  rsaE  m seed  = let e = publicKey 1 900 seed 3
                      n = calculateN 1 900 seed  
                      c = encrypt m (e, n)
                  in (encrypt m (e, n))
  
  rsaD :: Integer -> Int -> Integer -- main function to decript
  rsaD m seed = let e = publicKey 1 900 seed 3 -- generates two random primes between 1 and 900
                    n = calculateN 1 900 seed
                    d = privateKey 1 900 seed e
                    c = encrypt m (e, n)
                in decript c (d, n)
  
  
