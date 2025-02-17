SELECT
    CASE
       -- \U0001f3c1 If it's the last odd row, keep it the same
       WHEN id = (SELECT MAX(id) FROM Seat) AND MOD(id, 2) = 1 THEN id

       -- \U0001f504 If id is odd, swap it with the next seat
       WHEN MOD(id,2) = 1 THEN id + 1

       -- \U0001f504 If id is even, swap it with the previous seat
       ELSE id - 1
    END AS id, student      
FROM Seat
ORDER BY id;