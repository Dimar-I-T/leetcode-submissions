-- dimar's solution
select product_name, sum(case when order_date between '2020-02-01' and '2020-02-29' then unit end) unit
from orders o
left join products p on
    o.product_id = p.product_id
group by product_name
having sum(case when order_date between '2020-02-01' and '2020-02-29' then unit end) >= 100