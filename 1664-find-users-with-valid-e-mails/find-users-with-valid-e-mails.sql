-- dimar's solution
select user_id, name, mail
from users
where mail ~ '^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode\.com$'