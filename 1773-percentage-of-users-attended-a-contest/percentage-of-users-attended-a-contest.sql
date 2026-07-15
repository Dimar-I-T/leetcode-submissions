-- dimar's solution
with gabung as (
    select contest_id, count(contest_id) bp
    from register
    group by contest_id
), jumlah as (
    select count(*) c
    from users
)

select contest_id, round(100.0 * g.bp / j.c, 2) as percentage
from gabung g
cross join jumlah j
order by percentage desc, contest_id asc

