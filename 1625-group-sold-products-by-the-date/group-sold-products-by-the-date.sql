-- dimar's solution
with a as (
    select distinct product, sell_date
    from activities
    order by sell_date, product
)

select sell_date, count(sell_date) num_sold, string_agg(product, ',') products
from a
group by sell_date