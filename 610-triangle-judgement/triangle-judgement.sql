# Write your MySQL query statement below
WITH V AS (
    SELECT *,
           (X + Y + Z) AS SUM,
           GREATEST(X, Y, Z) AS LARGE
    FROM TRIANGLE
)
SELECT X, Y, Z,
       IF(SUM - LARGE > LARGE, 'Yes', 'No') AS TRIANGLE
FROM V;