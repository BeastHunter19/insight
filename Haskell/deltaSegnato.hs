deltaSegnato delta (q, []) = q
deltaSegnato delta (q, (c:cs)) = deltaSegnato delta (delta(q, c), cs)

data Sigma = A | B 
    deriving(Show)
data Q = Q0 | Q1 | Q2
    deriving(Show)

mydelta :: (Q, Sigma) -> Q
mydelta (Q0, A) = Q0
mydelta (Q0, B) = Q1
mydelta (Q1, A) = Q2
mydelta (Q1, B) = Q2
mydelta (Q2, A) = Q2
mydelta (Q2, B) = Q2

mydeltasegnato = deltaSegnato mydelta