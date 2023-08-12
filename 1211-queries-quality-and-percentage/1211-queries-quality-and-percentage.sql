# Write your MySQL query statement below
select round(avg(rating/position),2) as quality ,
round(sum(if (rating < 3 , 1 , 0))/count(*),4)*100 as poor_query_percentage
, query_name
from Queries
group by query_name ;