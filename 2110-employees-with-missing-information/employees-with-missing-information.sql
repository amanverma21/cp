SELECT e.employee_id from Employees e LEFT JOIN Salaries s
ON e.employee_id = s.employee_id WHERE s.salary IS NULL
UNION
SELECT s.employee_id from Salaries s LEFT JOIN Employees e
ON e.employee_id = s.employee_id WHERE e.employee_id IS NULL
ORDER BY employee_id