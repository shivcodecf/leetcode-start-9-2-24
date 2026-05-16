# Write your MySQL query statement below
select e1.name from Employee e1 join  Employee e2 on e1.id = e2.managerId WHERE e2.managerId IS NOT NULL
GROUP BY  e2.managerId having COUNT(e2.managerId)>=5;
