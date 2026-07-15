-- dimar's solution
with order_turn as (
    select *
    from queue
    order by turn asc
), summ as (
    select person_name, sum(weight) over(order by turn asc) s
    from order_turn
), limitt as (
    select person_name
    from (
        select *
        from summ
        where s <= 1000
    )
    order by s desc
    limit 1
)

select * from limitt