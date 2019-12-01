maxDouble :: [Double] -> [Double] -> [Double]
maxDouble [] [] = []
maxDouble (d:ds) (e:es) =
     if e>d
     then e:maxDouble ds es
     else d:maxDouble ds es