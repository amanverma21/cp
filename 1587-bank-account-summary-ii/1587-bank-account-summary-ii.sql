# Write your MySQL query statement below
select u.name as name, sum(t.amount) as balance 
from users u
join transactions t
on u.account=t.account
group by name 
having balance>10000