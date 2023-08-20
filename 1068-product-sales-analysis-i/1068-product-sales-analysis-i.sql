# Write your MySQL query statement below
select p.product_name as product_name , s.year as year , s.price as price 
from Sales as s 
join product as p 
on 
p.product_id = s.product_id ;