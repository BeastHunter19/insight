quadrato :: [Integer] -> [Integer]
quadrato []     = []
quadrato (x:xs) = x^2:quadrato xs
