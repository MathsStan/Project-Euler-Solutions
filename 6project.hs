sumSquareDifference n = abs $ squareOfSum n - sumOfSquares n

sumOfSquares n = flip div 6 $ 2*n^3 + 3*n^2 + n

squareOfSum n = flip div 4 $ n^4 + 2*n^3 + n^2