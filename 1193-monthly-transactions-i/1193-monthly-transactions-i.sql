# Write your MySQL query statement below
select A.month , A.country , count(A.id) as trans_count , 
sum(if(A.state = "approved",1,0)) as approved_count , 
sum(A.amount) as trans_total_amount ,
sum(if(A.state = "approved",A.amount,0)) as approved_total_amount
from (
    select *,substring(t.trans_date,1,7) as month from transactions as t
)A
group by A.month,A.country ;