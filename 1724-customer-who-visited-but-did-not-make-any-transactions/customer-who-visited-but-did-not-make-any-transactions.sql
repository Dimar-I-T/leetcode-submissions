-- dimar's solution
with distTrans as(
    select visit_id, sum(amount) s
    from transactions
    group by visit_id 
),
selisih as(
    select v.customer_id, (count(v.customer_id) - count(d.s)) count_no_trans
    from visits v
    left join distTrans d on v.visit_id = d.visit_id 
    group by v.customer_id
)

select *
from selisih
where count_no_trans > 0

