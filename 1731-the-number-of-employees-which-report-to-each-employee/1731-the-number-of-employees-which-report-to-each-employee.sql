select a.employee_id, a.name, 
count(b.reports_to)reports_count,
round(avg(b.age))average_age
from employees a, employees b
where a.employee_id = b.reports_to
group by 1,2
order by 1;