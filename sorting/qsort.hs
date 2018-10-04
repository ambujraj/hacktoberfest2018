{-
	Usage:
		ghci qsort.hs
		Prelude> qsort [Int array]
-}

qsort :: [Int] -> [Int]
qsort [] = []
qsort (x:xs) = qsort esq ++ [x] ++ qsort dir
               where
                    esq = [y | y <- xs, y < x]
                    dir = [y | y <- xs, y >= x]
