# Write your MySQL query statement below
SELECT
    a.machine_id, ROUND(AVG(CASE 
                   WHEN a.activity_type = 'end' THEN a.timestamp
                   WHEN a.activity_type = 'start' THEN -a.timestamp
                  END)*2, 3) as processing_time
FROM
    Activity a
GROUP BY
    a.machine_id