lunghezza :: String -> Integer
lunghezza []     = 0
lunghezza (a:xs) = lunghezza xs + 1
