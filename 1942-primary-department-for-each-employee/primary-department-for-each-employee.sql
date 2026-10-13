# Write your MySQL query statement below
-- SELECT EMPLOYEE_ID, DEPARTMENT_ID FROM EMPLOYEE
-- WHERE PRIMARY_FLAG='Y' OR EMPLOYEE_ID IN (
--     SELECT EMPLOYEE_ID FROM EMPLOYEE GROUP BY EMPLOYEE_ID
--     HAVING COUNT(DEPARTMENT_ID)=1
-- )

(select employee_id, department_id from employee
where primary_flag = 'y')
union all
(select employee_id, department_id from employee
group by employee_id having count(*) = 1)