module Main where

import Math.Combinat.Partitions.Integer (Partition, fromPartition, partitionsWithKParts)

main :: IO ()
main = do
    let triple = head $ getPythagTrips 1000
    putStrLn . show $ triple
    putStrLn . show $ product triple

--a^2 + b^2 = c^2 -> a + b + c = n
getPythagTrips :: Int -> [[Int]]
getPythagTrips n = filter isPythagTriple (partitionsWith3Parts n) where
    isPythagTriple [c, b, a] =  a^2 + b^2 == c^2
    isPythagTriple _ = undefined

partitionsWith3Parts :: Int -> [[Int]] --In monotone decreasing order.
partitionsWith3Parts n = map fromPartition (partitionsWithKParts 3 n)
