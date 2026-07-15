-- dimar's solution
with awal as (
    select user_id, 0.00 as confirmation_rate from signups
), awal1 as (
        select user_id, round(1.0 * count(case when action = 'confirmed' then user_id end) / count(user_id), 2) confirmation_rate
    from confirmations
    group by user_id
)

select a0.user_id, coalesce(a0.confirmation_rate + a1.confirmation_rate, 0) as confirmation_rate
from awal1 a1
right join awal a0
on a0.user_id = a1.user_id