listaDispari :: [Int] -> [Int]
listaDispari []     = []
listaDispari (x:ys) = if even x then listaDispari ys else x:listaDispari ys
