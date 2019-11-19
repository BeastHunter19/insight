inversa :: String -> String
inversa []     = []
inversa (a:ys) = (inversa ys)++[a]
