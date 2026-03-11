# Write your MySQL query statement below
select email from Person GROUP BY email having COUNT(email)>1;

