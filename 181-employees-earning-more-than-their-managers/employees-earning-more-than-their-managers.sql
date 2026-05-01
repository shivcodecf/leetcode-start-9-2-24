-- # Write your MySQL query statement below
-- select name as Employee from Employee e1 SELF JOIN Employee e2 on e1.id = e2.managerId where e1.salary>e2.salary;

SELECT e2.name AS Employee
FROM Employee e1
JOIN Employee e2 
ON e1.id = e2.managerId
WHERE e1.salary < e2.salary;