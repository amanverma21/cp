select customer_number
from orders
group by customer_number
ORDER BY COUNT(customer_number) DESC
limit 1;