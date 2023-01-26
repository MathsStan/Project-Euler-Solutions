module Main where

import Math.Combinat.Partitions.Integer (Partition, fromPartition, partitionsWithKParts)

main :: IO ()
main = putStrLn . show $ getPythagTrips 1000

--a^2 + b^2 = c^2 -> a + b + c = n
getPythagTrips :: Int -> [[Int]]
getPythagTrips n = filter isPythagTriple (partitionsWith3Parts n) where
    isPythagTriple [c, b, a] =  a^2 + b^2 == c^2
    isPythagTriple _ = undefined

partitionsWith3Parts :: Int -> [[Int]] --In monotone decreasing order.
partitionsWith3Parts n = map fromPartition (partitionsWithKParts 3 n)
