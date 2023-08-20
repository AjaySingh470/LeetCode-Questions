select p.product_id as product_id , round(sum(p.price*us.units)/sum(us.units),2) as average_price from Prices as p , UnitsSold as us 
where p.product_id = us.product_id 
and
us.purchase_date between p.start_date and p.end_date 
group by p.product_id;