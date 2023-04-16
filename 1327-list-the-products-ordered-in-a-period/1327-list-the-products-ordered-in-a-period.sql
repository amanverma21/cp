# Write your MySQL query statement below
SELECT p.product_name, SUM(o.unit) AS unit
FROM Orders o LEFT JOIN Products p ON o.product_id = p.product_id
WHERE YEAR(o.order_date) = '2020' AND MONTH(o.order_date) = '02'
GROUP BY p.product_name
HAVING SUM(o.unit) >= 100
