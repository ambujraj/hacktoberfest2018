# RSA-criptography-hs
The RSA criptography in haskell, made for learning purposes.
How to use:

1- If you already have the public and private keys:
Just call the functions encrypt m (e, n) and decript c (d, n ). d, n = private key; e,n = public key.

2- If you do not have the keys:
Call the function rsaE m seed, and provide your number m - that you want to encript - and a random seed. To decript do the same
thing with rsaD m seed, providing your number and the same seed.


Steps:
1- Choose two different prime numbers:
The easiest way to do this was with the method ramdomRIO (a,b), but, as this was made for learning purposes, I chose to use
randomR instead. The difference is that randomR needs a random number generator g, which is provided by the seed 'k'.

2-Calculate the totient;

if x /= y
         then return ((x - 1) * (y -1))

3-Choose an integer e that is coprime to the totient. "e" is the public key exponent;

publicKey :: Integer -> Integer -> Int -> Integer -> IO Integer
publicKey m n k e = do
  
  y <- calculateTotient m n k    
  if (gcd e y) == 1
    then return e    
    else publicKey m n k (e + 1)


4-Compute d = 1 + k*totient(n)."d" is kept as the private key exponent;

5- Just encript or decript:
  
encrypt :: Integer -> (Integer, Integer) -> Integer
encrypt m (e, n) = ((m^e) `mod` n)

decript :: Integer -> (Integer, Integer) -> Integer
decript c (d, n ) = (c^d `mod` n)

