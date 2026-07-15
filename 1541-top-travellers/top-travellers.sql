-- dimar's solution
with a as (
    (select name, sum(distance) travelled_distance
    from rides r
    join users u on
        u.id = r.user_id
    group by name
    order by sum(distance) desc, name asc)
    union
    (select name, '0' as travelled_distance
    from users
    where id not in 
    (select user_id
    from rides))
)

select * from a
order by travelled_distance desc, name asc