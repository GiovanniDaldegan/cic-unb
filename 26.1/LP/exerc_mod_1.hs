-- LP T01 - 26.1
-- Lista de exercícios sobre Haskell

-- 01
maior4 :: Int -> Int -> Int -> Int -> Int
maior4 a b c d
  | a >= b && a >= c && a >= d = a
  | b >= a && b >= c && b >= d = b
  | c >= a && c >= b && c >= d = c
  | otherwise                  = d

-- 02
converterNotaParaMencao :: Float -> String
converterNotaParaMencao a
  | a < 0 || a > 10   = "Inválido"
  | a >= 9            = "SS"
  | a >= 7            = "MS"
  | a >= 5            = "MM"
  | a >= 3            = "MI"
  | a >= 0            = "SR"

-- 03
-- funções utilitárias
inList :: Eq t => t -> [t] -> Bool
inList _ [] = False
inList a (b:bs) = (a == b) || (inList a bs)

inListBetween :: Eq t => t -> [t] -> Int -> Int -> Bool
inListBetween _ [] _ _ = False
inListBetween e (f:fs) a b
  | a > b || a < 1  = False       -- oculta erro
  | a > 1     = inListBetween e fs (a-1) (b-1)
  | b >= 1    = (e == f) || inListBetween e fs (a-1) (b-1)
  | otherwise = False

-- a) lista A - B, retorna apenas elementos de A e não de B
listDiff :: Eq t => [t] -> [t] -> [t]
listDiff [] l = []
--listDiff l [] = l -- como tratar?? TODO
listDiff (a:as) l
  | inList a l  = listDiff as l
  | otherwise   = a : listDiff as l

-- b)
listIntersec :: Eq t => [t] -> [t] -> [t]
listIntersec [] l = []
listIntersec l [] = []
listIntersec (a:as) l
  | inList a l  = a : (listIntersec as l)
  | otherwise   = listIntersec as l

-- c)
listUnion :: Eq t => [t] -> [t] -> [t]
listUnion [] [] = []
listUnion [] l  = l
listUnion l []  = l
listUnion (a:as) (b:bs) = a : b : listUnion as bs

-- d) permite rep na primeira lista, mas na segunda se elemento pertencer à primeira
listUnionNoRep :: Eq t => [t] -> [t] -> [t]
listUnionNoRep [] [] = []
listUnionNoRep a b = listUnionNoRepAux a a b

listUnionNoRepAux :: Eq t => [t] -> [t] -> [t] -> [t]
listUnionNoRepAux _ [] [] = []
listUnionNoRepAux _ l []  = l
listUnionNoRepAux aog [] (b:bs)
  | inList b aog  = listUnionNoRepAux aog [] bs
  | otherwise     = b : listUnionNoRepAux aog [] bs
listUnionNoRepAux aog (a:as) (b:bs)
  | inList b aog  = a : listUnionNoRepAux aog as bs
  | otherwise     = a : b : listUnionNoRepAux aog as bs
{-
  | (inList a aog) && (inList b bog)      = listUnionNoRepAux aog bog as bs
  | not (inList a aog) && (inList b bog)  = a : listUnionNoRepAux aog bog as bs
  | (inList a aog) && not (inList b bog)  = b : listUnionNoRepAux aog bog as bs
  | otherwise                             = a : b : listUnionNoRepAux aog bog as bs
-}

-- e) indefinido para lista vazia
listLast :: Eq t => [t] -> t
listLast (a:as)
  | as == []  = a
  | otherwise = listLast as

-- f) indefinido para lista vazia / index out of bounds
listNth :: [t] -> Int -> t
listNth (a:as) n
  | n == 1    = a
  | otherwise = listNth as (n-1)

-- g)
listInvert :: [t] -> [t]
listInvert [] = []
listInvert (a:as) = (listInvert as) ++ [a]

-- h)
--listUnion :: Eq t => [t] -> [t] -> [t]

-- i)
--listUnion :: Eq t => [t] -> [t] -> [t]



main :: IO ()
--main = putStr $ show (listUnion [2, 1, 3, 4] [1, 2, 3, 0])
--main = putStr $ show (diffList [1, 2, 3] [3, 2, 1, 0])
--main = putStr $ show (listUnionNoRep [1, 2, 3, 0, 1] [1, 3, 0, 2, 2, 2])
main = putStr $ show (inListBetween 0 [1, 1, 1, 0, 1, 1, 1] 3 5)
