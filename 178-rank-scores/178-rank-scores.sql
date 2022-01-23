SELECT s.score, dense_rank() OVER (ORDER BY s.score DESC) AS 'rank'
FROM Scores s;