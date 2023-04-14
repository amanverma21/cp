select name as 'Customers'
from customers
left outer join orders
on customers.id = orders.customerid
where orders.customerid IS NULL;