select  p.product_name , sum(o.unit) as unit
from Orders as o join products as p
on o.product_id = p.product_id 
and
o.order_date between "2020-02-01" and "2020-02-29"
group by o.product_id 
having sum(o.unit)>=100
;