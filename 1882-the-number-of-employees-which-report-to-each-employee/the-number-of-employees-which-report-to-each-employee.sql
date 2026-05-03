select e1.employee_id , e1.name, COUNT(e2.reports_to) as reports_count, round(AVG(e2.age)) as average_age from Employees e1 JOIN Employees e2 on e1.employee_id = e2.reports_to  GROUP BY e1.employee_id ORDER BY e1.employee_id


-- select * from Employees e1 JOIN Employees e2 on e1.employee_id = e2.reports_to;