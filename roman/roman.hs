module Main where

import Data.Bool

romanToInt :: Char -> Integer
romanToInt 'I' = 1
romanToInt 'V' = 5
romanToInt 'X' = 10
romanToInt 'L' = 50
romanToInt 'C' = 100
romanToInt 'D' = 500
romanToInt 'M' = 1000
romanToInt  _  = 0


romanToNum :: [Char] -> Integer
romanToNum xs
   | length xs == 0 = 0
   | length xs == 1 = romanToInt (head xs)
   | otherwise      = let fst = romanToInt (head xs)
                          snd = romanToInt (xs  !! 1)
                          t1  = romanToNum (tail xs)
                      in if fst < snd then t1 - fst
                                      else t1 + fst

main :: IO()
main = putStrLn result

result :: [Char]
result = if final == False then "Your program is wrong"
                         else "Your program is working!!! "
  where final = foldl (&&) True expr
        expr :: [Bool]
        expr = [e1, e2, e3, e4, e5]
        e1   = (romanToNum "XVI") == 16
        e2   = (romanToNum "VI") == 6
        e3   = (romanToNum "CM") == 900
        e4   = (romanToNum "CMXL") == 940
        e5   = (romanToNum "XIII") == 13

