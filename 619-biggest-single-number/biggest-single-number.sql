-- dimar's solution
WITH pasangcount AS (
    SELECT num, COUNT(num) AS c
    FROM mynumbers
    GROUP BY num
), 
joinpn AS (
    SELECT m.num AS mn, p.c AS pc
    FROM mynumbers m
    INNER JOIN pasangcount p ON p.num = m.num
), 
pilter AS (
    SELECT mn
    FROM joinpn
    WHERE pc = 1
    ORDER BY mn DESC
), 
tambah0 AS (
    SELECT mn FROM pilter
    UNION ALL 
    SELECT NULL AS mn
)

SELECT coalesce(mn, NULL) AS num
FROM tambah0
LIMIT 1;