-- dimar's solution
with distTeacher as (
    select distinct teacher_id
    from teacher
), distT as (
    select distinct teacher_id, subject_id ds
    from teacher
)

select teacher_id, count(teacher_id) cnt
from distT
group by teacher_id