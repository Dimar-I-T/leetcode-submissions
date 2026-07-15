-- dimar's solution
with gabung as (
    select requester_id as n
    from requestAccepted
    union all
    select accepter_id as n
    from requestAccepted
), hitungB as (
    select n, count(n) c
    from gabung
    group by n
)

select n id, c num
from hitungB
order by c desc
limit 1