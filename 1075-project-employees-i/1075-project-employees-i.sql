
select project_id , round(avg(experience_years),2) as average_years
from (select * from project p 
left join employee e 
 using(employee_id)) a
group by project_id ;
