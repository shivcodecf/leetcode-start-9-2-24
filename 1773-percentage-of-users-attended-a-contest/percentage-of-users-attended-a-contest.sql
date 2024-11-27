-- SELECT 
--     r.contest_id, 
--     (COUNT(r.user_id) / COUNT(DISTINCT u.user_id)) * 100 AS percentage
-- FROM 
--     Register r
-- LEFT JOIN 
--     Users u
-- ON 
--     u.user_id = r.user_id
-- GROUP BY 
--     r.contest_id
-- ORDER BY 
--     r.contest_id ASC;





    select 
contest_id, 
round(count(distinct user_id) * 100 /(select count(user_id) from Users) ,2) as percentage
from  Register
group by contest_id
order by percentage desc,contest_id
