-- dimar's solution
with qu as (
    select query_name, round(1.0*sum(1.0*rating/position)/count(query_name), 2) as quality
    from queries
    group by query_name
    having query_name is not null
), bq as (
    select query_name, count(query_name) banyak
    from queries
    group by query_name
    having query_name is not null
), bp as (
    select *
    from queries
    where rating < 3
), po as (
    select query_name, count(bp.query_name) co
    from bp
    group by bp.query_name
    having bp.query_name is not null
), cal as (
    select po.query_name qn, round(100.0*po.co/bq.banyak, 2) pqp
    from po
    join bq on
        po.query_name = bq.query_name
)

(select query_name, quality, cal.pqp poor_query_percentage
from qu
inner join cal on
    qu.query_name = cal.qn)

union

select query_name, quality, 0
from qu
where query_name not in (select qn from cal)

