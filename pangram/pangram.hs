module Main where

import Text.Printf (printf)

import Data.Char (toLower)
import Data.Set (fromList, isSubsetOf)


checkPangram :: [Char] -> Bool
checkPangram s =  isSubsetOf alphabet $ lowerList s
       where lowerList = fromList . map toLower
             alphabet  = fromList ['a'..'z']


main :: IO()
main = do 
     printf "Enter the word: "
     word <- getLine 
     case checkPangram word of
       True  ->  printf "Your word is pangram.\n"
       False ->  printf "Your word is not pangram.\n"
