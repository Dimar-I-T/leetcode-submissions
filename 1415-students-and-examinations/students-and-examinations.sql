-- dimar's solution
with berisi as (
    select e.student_id student_id, s.student_name student_name, e.subject_name subject_name,
    count(e.student_id) attended_exams
    from examinations e
    join students s on s.student_id = e.student_id
    group by subject_name, student_id
), basis as (
    select st.student_id si, st.student_name sn, s.subject_name sun
    from students st
    cross join subjects s
), adanull as(
    select b.si bsi, b.sn bsn, b.sun bsun, be.attended_exams att
    from basis b
    left join berisi be on
        b.si = be.student_id and
        b.sun = be.subject_name
    order by b.si, b.sun
)

select bsi student_id, bsn student_name, bsun subject_name, case
    when att is null then 0
    else att end as attended_exams
from adanull

