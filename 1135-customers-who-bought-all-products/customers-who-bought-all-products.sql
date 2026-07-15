-- dimar's solution
with rankc as (
    select customer_id, product_key, dense_rank() over(partition by customer_id order by product_key) ra
    from customer
), rowProduct as (
    select row_number() over() r from product
), maks as (
    select customer_id, max(ra)
    from rankc
    group by customer_id
)

select distinct customer_id
from rankc
where ra in (select r from rowproduct order by r desc limit 1)