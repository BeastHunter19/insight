filtra :: (a -> Bool) -> [a] -> [a]
filtra _ [] = []
filtra cond (x:xs) =
                    if cond x
                    then filtra cond xs
                    else x:filtra cond xs
