-- dimar's solution
select name Customers
from customers c
left join orders o
on c.id = o.customerid
where customerid is null 