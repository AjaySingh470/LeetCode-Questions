select 
now.visited_on
, sum(past.amount) as amount
, round(sum(past.amount)/7,2) as average_amount
from (select visited_on, sum(amount) as amount from Customer group by visited_on) as now
join (select visited_on, sum(amount) as amount from Customer group by visited_on) as past 
  on datediff(now.visited_on, past.visited_on) between 0 and 6
group by now.visited_on
having now.visited_on >= (select visited_on as first from Customer order by visited_on limit 1) + 6
order by now.visited_on