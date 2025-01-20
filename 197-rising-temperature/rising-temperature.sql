-- Select the IDs from Weather where the temperature is higher than the previous day
SELECT w2.id
FROM Weather w1, Weather w2
WHERE DATEDIFF(w2.recordDate, w1.recordDate) = 1
AND w1.temperature < w2.temperature;