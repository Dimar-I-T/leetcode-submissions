-- dimar's solution
with studs as (
    select row_number() over() ro, s1.student st1, s2.student st2, s3.student st3
    from seat s1
    left join seat s2 on
        s1.id = s2.id - 1
    left join seat s3 on
        s1.id = s3.id + 1
), susunan as (
    select ro, case
        when ro % 2 = 0 then st3
        else st2 end student
    from studs
)

select ro as id, case when
    student is null
    then (select student
          from seat
          where id = (select id
                      from seat
                      order by id desc
                      limit 1
                     )
         )
    else student end student
from susunan
    