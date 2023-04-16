SELECT 
USER_ID,
NAME,
MAIL
FROM USERS
WHERE mail REGEXP '^[a-zA-Z]+[a-zA-Z-._0-9]*@leetcode[.]com'