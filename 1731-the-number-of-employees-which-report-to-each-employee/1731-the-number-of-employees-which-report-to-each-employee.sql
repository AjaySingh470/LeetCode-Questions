select e2.reports_to as employee_id , e1.name , count(e2.employee_id) as reports_count , round(avg(e2.age)) as average_age
from employees as e1 join employees as e2
on e1.employee_id = e2.reports_to
group by e2.reports_to
order by e2.reports_to ;