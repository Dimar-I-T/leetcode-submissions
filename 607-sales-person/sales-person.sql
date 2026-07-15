-- dimar's solution
with com as (
    select com_id cid, name, city
    from company 
),
bar as(
    select o.sales_id sid
    from orders o
    left join com c on o.com_id = c.cid
    where c.name like 'RED%'
)

select s.name name
from salesperson s
left join bar b on s.sales_id = b.sid
where b.sid is null


