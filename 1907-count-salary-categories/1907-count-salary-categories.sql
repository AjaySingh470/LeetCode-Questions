select "Low Salary" as category , count(income) as accounts_count
from accounts
where income < 20000
union 
select "Average Salary" , count(income) as account_count
from accounts
where income between 20000 and 50000
union 
select "High Salary" , count(income) as account_count
from accounts

where income > 50000 ;