listaMax :: [Int] -> [Int] -> [Int]
listaMax [] []         = []
listaMax (x:xs) (y:ys) = if x>y then x:listaMax xs ys else y:listaMax xs ys
