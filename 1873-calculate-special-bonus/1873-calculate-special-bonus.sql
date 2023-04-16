select employee_id, if(employee_id%2=1 and not name like 'M%', salary,0) as bonus from Employees order by employee_id
