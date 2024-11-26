# Write your MySQL query statement below
Select p.project_id, ROUND(AVG(e.experience_years),2) as average_years from Project p 

left join

Employee e

ON  e.Employee_id = p.Employee_id

group by p.project_id;










   

