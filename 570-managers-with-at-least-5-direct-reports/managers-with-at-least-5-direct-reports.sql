# Write your MySQL query statement below

Select e1.name from
Employee e1 JOIN Employee e2
on e1.id = e2.managerId
group by e2.managerId

HAVING
count(e2.managerId) >=5 





