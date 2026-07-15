-- dimar's solution
with banyakk as (
    select tiv_2015, count(tiv_2015) banyak 
    from insurance
    group by tiv_2015
),
banyakll as (
    select ll, count(ll) as c 
    from (
        select pid, tiv_2015, tiv_2016, array[lat, lon] ll
        from insurance
    ) s
    group by ll
    having count(ll) = 1
)

select round(tiv_2016::numeric, 2) as tiv_2016 from
(   
    select sum(case when banyak > 1 then i.tiv_2016 else 0 end) tiv_2016
    from (
        select pid, tiv_2015, tiv_2016, array[lat, lon] ll
        from insurance
    ) i
    join banyakll b
    on i.ll = b.ll
    join banyakk b1
    on i.tiv_2015 = b1.tiv_2015
) s1
