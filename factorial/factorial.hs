factorial :: Int -> Int
factorial 0 = 1
factorial n = n * factorial(n - 1)

main = print (factorial 5)
