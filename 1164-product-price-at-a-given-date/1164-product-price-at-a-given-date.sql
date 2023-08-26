# Write your MySQL query statement below
SELECT product_id, FIRST_VALUE(new_price) OVER(PARTITION BY product_id ORDER BY change_date DESC) AS price
FROM Products
WHERE change_date <= '2019-08-16'
union 
select product_id , 10 as price 
from products 
where product_id not in (select product_id from products where change_date <= '2019-08-16')