# Write your MySQL query statement below
select s1.id,coalesce(s2.student,s1.student) as student  from seat s1
left join seat s2
on s2.id = (s1.id+1)^1-1
order by s1.id;