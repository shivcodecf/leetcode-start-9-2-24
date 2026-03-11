# Write your MySQL query statement below

-- SELECT MAX(salary) AS SecondHighestSalary
-- FROM Employee
-- WHERE salary < (
--     SELECT MAX(salary) FROM Employee
-- );

select MAX(salary) AS SecondHighestSalary from Employee where salary < (select MAX(salary) from employee);

