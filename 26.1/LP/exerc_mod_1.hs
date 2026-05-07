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
inList :: Eq t => t -> [t] -> Bool
inList _ [] = False
inList a (b:bs) = (a == b) || (inList a bs)

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

-- d) indefinido para 
listLast :: [t] -> t
listLast 

-- e)
--listUnion :: Eq t => [t] -> [t] -> [t]

-- f)
--listUnion :: Eq t => [t] -> [t] -> [t]

-- g)
--listUnion :: Eq t => [t] -> [t] -> [t]

-- h)
--listUnion :: Eq t => [t] -> [t] -> [t]

-- i)
--listUnion :: Eq t => [t] -> [t] -> [t]



main :: IO ()
main = putStr $ show (listUnion [2, 1, 3, 4] [1, 2, 3, 0])
--main = putStr $ show (diffList [1, 2, 3] [3, 2, 1, 0])