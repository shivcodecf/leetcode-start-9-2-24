# Write your MySQL query statement below

Select id,movie,description,rating from Cinema 
WHERE 
id % 2
AND
description !="boring"
order by
rating desc;




