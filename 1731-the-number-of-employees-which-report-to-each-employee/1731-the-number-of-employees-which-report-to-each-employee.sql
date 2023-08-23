select reports_to as employee_id ,
    (select e.name from employees as e where e2.reports_to = e.employee_id) as name,
    count(employee_id) as reports_count , 
    round(avg(age),0) as average_age
from employees as e2
group by reports_to 
having reports_to in (select employee_id from Employees)
order by employee_id

;