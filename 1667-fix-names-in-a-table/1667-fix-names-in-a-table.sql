# Write your MySQL query statement below
SELECT user_id, CONCAT(UPPER(SUBSTRING(name,1,1)),LOWER(SUBSTRING(name,2,length(name)))) AS name FROM users ORDER BY user_id