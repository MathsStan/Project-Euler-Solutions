fibs = 1:2:[a + b | (a, b) <- zip fibs (tail fibs)]

evenSum max = fn fibs where
    fn (_:even:_:rest) = 
        if even < max
            then even + fn (rest)
            else 0

let problemMax = 4000000
in main = print $ evenSum problemMax