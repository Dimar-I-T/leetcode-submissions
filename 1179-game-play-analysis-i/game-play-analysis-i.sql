-- dimar's solution
with rankedA as (
    select player_id, event_date, rank() over(partition by player_id order by event_date asc) r
    from activity
)

select player_id, event_date first_login
from rankedA
where r = 1