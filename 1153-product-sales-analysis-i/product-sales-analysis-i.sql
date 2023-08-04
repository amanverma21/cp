select p.product_name, s.year, s.price from sales as s
INNER JOIN Product as p ON p.product_id = s.product_id
 
