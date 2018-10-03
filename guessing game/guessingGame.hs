module Main where

import Text.Printf (printf)
import System.Random (randomRIO)

smallest = 1 :: Int
biggest  = 20 :: Int

checkNumber :: Int -> Bool
checkNumber _ = True

main :: IO ()
main = do
     secret <- randomRIO ( smallest, biggest) :: IO Int
     printf "Find number in range from %d to %d.\n" smallest biggest
     loop secret where
       loop :: Int -> IO()
       loop secret = do 
              guess <- readLn :: IO Int
              case compare guess secret of
                 LT -> do 
                     printf "Too small\n"
                     loop secret
                 GT -> do
                     printf "Too big!!\n"
                     loop secret
                 EQ -> do
                      printf "You found the number. Well done!\n"

