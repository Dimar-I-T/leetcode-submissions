-- dimar's solution
select name, sum(amount) balance
from transactions t
join users u on
    t.account = u.account
group by t.account, name
having sum(amount) > 10000